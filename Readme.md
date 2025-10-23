# Package Delivery Priority Sorting

A simple C program that simulates **priority-based package delivery** using a **Max-Heap Priority Queue**.  
Packages with higher priority values are served first.

---

## 📦 Features

- Insert new package (Sender, Destination, Weight, Priority)
- Serve (delete) highest priority package
- Display all packages (level-order)
- Bulk insert demo (10 sample packages)
- Dynamic memory management using `malloc` and `realloc`

---

## ⚙️ Compilation & Run

```bash
gcc -std=c11 -Wall -Wextra main.c -o main
./main
```

---

## 🧠 How It Works

- Uses a **Max-Heap** to efficiently manage package priorities.
- `insert` → O(log n)
- `serve/delete` → O(log n)
- `display` → O(n)

---

## 🧾 Sample Menu

```bash
--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
```

---

## 👥 Credits

Developed for **Assignment – Package Delivery Priority Sorting**
*Language:* C
*File:* `main.c`

1. Abhinav Mani Tripathi (2)
2. Aditya Mishra (8)
3. Arya Mishra (22)
4. Darshika Singh (29)
5. Devansh Singh (32)
6. Harshit Yadav (38)
