#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INIT_CAP 16
#define STRLEN 64

typedef struct {
    int id;
    char sender[STRLEN];
    char dest[STRLEN];
    float weight;
    int priority; // higher value => higher priority
} Package;

typedef struct {
    Package *arr; // dynamic array of packages (1-based indexing used internally)
    int size;
    int capacity;
} MaxHeap;

MaxHeap* create_heap(int init_cap) {
    MaxHeap *h = (MaxHeap*)malloc(sizeof(MaxHeap));
    if(!h) { perror("malloc"); exit(EXIT_FAILURE); }
    h->capacity = (init_cap > 1) ? init_cap : INIT_CAP;
    // allocate one extra to use 1-based index (simpler parent/child math)
    h->arr = (Package*)malloc(sizeof(Package) * (h->capacity + 1));
    if(!h->arr) { perror("malloc"); exit(EXIT_FAILURE); }
    h->size = 0;
    return h;
}

void free_heap(MaxHeap *h) {
    if(!h) return;
    free(h->arr);
    free(h);
}

void swap_pkg(Package *a, Package *b) {
    Package tmp = *a;
    *a = *b;
    *b = tmp;
}

void ensure_capacity(MaxHeap *h) {
    if(h->size < h->capacity) return;
    int newcap = h->capacity * 2;
    Package *tmp = (Package*)realloc(h->arr, sizeof(Package) * (newcap + 1));
    if(!tmp) {
        perror("realloc");
        return;
    }
    h->arr = tmp;
    h->capacity = newcap;
}

// heap indices: root at 1, children: 2*i, 2*i+1
void heapify_up(MaxHeap *h, int idx) {
    while(idx > 1) {
        int parent = idx / 2;
        if(h->arr[parent].priority < h->arr[idx].priority) {
            swap_pkg(&h->arr[parent], &h->arr[idx]);
            idx = parent;
        } else break;
    }
}

void heapify_down(MaxHeap *h, int idx) {
    while(1) {
        int left = idx * 2;
        int right = left + 1;
        int largest = idx;

        if(left <= h->size && h->arr[left].priority > h->arr[largest].priority)
            largest = left;
        if(right <= h->size && h->arr[right].priority > h->arr[largest].priority)
            largest = right;

        if(largest != idx) {
            swap_pkg(&h->arr[idx], &h->arr[largest]);
            idx = largest;
        } else break;
    }
}

void insert_package(MaxHeap *h, Package pkg) {
    ensure_capacity(h);
    h->size += 1;
    h->arr[h->size] = pkg; // copy struct
    heapify_up(h, h->size);
    printf("Inserted package ID %d with priority %d\n", pkg.id, pkg.priority);
}

int is_empty(MaxHeap *h) { return h->size == 0; }

Package delete_max(MaxHeap *h) {
    if(is_empty(h)) {
        fprintf(stderr, "Heap is empty. Returning dummy package.\n");
        Package dummy; memset(&dummy, 0, sizeof(dummy)); dummy.id = -1; return dummy;
    }
    Package top = h->arr[1];
    h->arr[1] = h->arr[h->size];
    h->size -= 1;
    heapify_down(h, 1);
    return top;
}

void display_heap(MaxHeap *h) {
    if(is_empty(h)) { printf("[Queue is empty]\n"); return; }
    printf("Current Queue (level-order: index:ID(priority), root index = 1):\n");
    for(int i = 1; i <= h->size; ++i) {
        printf("%d:%d(%d) ", i, h->arr[i].id, h->arr[i].priority);
    }
    printf("\nDetailed:\n");
    for(int i = 1; i <= h->size; ++i) {
        printf("Index %d => ID=%d, Sender=%s, Dest=%s, W=%.2fkg, Priority=%d\n",
               i, h->arr[i].id, h->arr[i].sender, h->arr[i].dest, h->arr[i].weight, h->arr[i].priority);
    }
}

void read_string_field(const char *prompt, char *buf, int len) {
    printf("%s", prompt);
    // read up to len-1 characters, consume newline
    if(fgets(buf, len, stdin)) {
        size_t L = strlen(buf);
        if(L && buf[L-1] == '\n') buf[L-1] = '\0';
    } else {
        buf[0] = '\0';
        int c; while((c = getchar()) != '\n' && c != EOF); // clear
    }
}

void menu_loop() {
    MaxHeap *heap = create_heap(INIT_CAP);
    int choice;
    int next_id = 1;

    while(1) {
        printf("\n--- Package Delivery Priority Queue ---\n");
        printf("1) Insert package\n2) Serve (delete highest priority)\n3) Display queue\n4) Bulk sample insert (10 packages demo)\n5) Exit\nChoose: ");
        if(scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        int c = getchar(); // consume newline

        if(choice == 1) {
            Package p;
            p.id = next_id++;
            read_string_field("Sender name: ", p.sender, STRLEN);
            read_string_field("Destination: ", p.dest, STRLEN);
            printf("Weight (kg): "); scanf("%f", &p.weight); c=getchar();
            printf("Priority (int, higher = served first): "); scanf("%d", &p.priority); c=getchar();
            insert_package(heap, p);
        }
        else if(choice == 2) {
            if(is_empty(heap)) { printf("Queue empty. Nothing to serve.\n"); continue; }
            Package served = delete_max(heap);
            printf("Served package ID %d (priority %d) -> Sender: %s, Dest: %s, Weight: %.2fkg\n",
                   served.id, served.priority, served.sender, served.dest, served.weight);
        }
        else if(choice == 3) {
            display_heap(heap);
        }
        else if(choice == 4) {
            // Bulk sample insert (10 entries) for demonstration
            const char *senders[] = {"Aman","Bina","Chetan","Deepa","Esha","Farhan","Gita","Hari","Isha","Jai"};
            const char *dests[]   = {"Mumbai","Delhi","Kolkata","Chennai","Pune","Hyderabad","Bangalore","Lucknow","Jaipur","Patna"};
            float weights[] = {0.5,2.0,1.2,0.8,4.0,3.1,0.3,2.5,1.0,5.0};
            int priorities[] = {5, 2, 9, 1, 7, 9, 3, 6, 4, 8}; // variety (10 entries)
            for(int i=0;i<10;i++){
                Package p;
                p.id = next_id++;
                strncpy(p.sender, senders[i], STRLEN-1); p.sender[STRLEN-1] = '\0';
                strncpy(p.dest, dests[i], STRLEN-1); p.dest[STRLEN-1] = '\0';
                p.weight = weights[i];
                p.priority = priorities[i];
                insert_package(heap, p);
            }
            printf("Inserted 10 sample packages.\n");
        }
        else if(choice == 5) {
            printf("Exiting. Freeing resources.\n");
            free_heap(heap);
            break;
        }
        else {
            printf("Invalid option.\n");
        }
    }
}

int main(void) {
    menu_loop();
    return 0;
}
