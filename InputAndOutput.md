# Input and Output

## Insertion

```bash
    --- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: AbhinavMani
Destination: Mumbai
Weight (kg): 0.3
Priority (int, higher = served first): 5
Inserted package ID 1 with priority 5

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: AdityaMishra
Destination: Delhi
Weight (kg): 2.3
Priority (int, higher = served first): 2
Inserted package ID 2 with priority 2

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: AryaMishra
Destination: Kolkata
Weight (kg): 1.2
Priority (int, higher = served first): 9
Inserted package ID 3 with priority 9

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: Devansh
Destination: Chennai
Weight (kg): 3.1
Priority (int, higher = served first): 1
Inserted package ID 4 with priority 1

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: Darshika
Destination: Pune
Weight (kg): 1.1
Priority (int, higher = served first): 7
Inserted package ID 5 with priority 7

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: Harshit
Destination: Hyderabad
Weight (kg): 3.2
Priority (int, higher = served first): 9
Inserted package ID 6 with priority 9

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: Gita
Destination: Lucknow
Weight (kg): 9.2
Priority (int, higher = served first): 3
Inserted package ID 7 with priority 3

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: Chetan
Destination: Bhopal
Weight (kg): 2.8
Priority (int, higher = served first): 6
Inserted package ID 8 with priority 6

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: Deepa
Destination: Jaipur 
Weight (kg): 4.0
Priority (int, higher = served first): 4
Inserted package ID 9 with priority 4

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 1
Sender name: Esha
Destination: Patna  
Weight (kg): 8.2
Priority (int, higher = served first): 8
Inserted package ID 10 with priority 8

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 3
Current Queue (level-order: index:ID(priority), root index = 1):
1:3(9) 2:10(8) 3:6(9) 4:8(6) 5:5(7) 6:1(5) 7:7(3) 8:4(1) 9:9(4) 10:2(2) 
Detailed:
Index 1 => ID=3, Sender=AryaMishra, Dest=Kolkata, W=1.20kg, Priority=9
Index 2 => ID=10, Sender=Esha, Dest=Patna, W=8.20kg, Priority=8
Index 3 => ID=6, Sender=Harshit, Dest=Hyderabad, W=3.20kg, Priority=9
Index 4 => ID=8, Sender=Chetan, Dest=Bhopal, W=2.80kg, Priority=6
Index 5 => ID=5, Sender=Darshika, Dest=Pune, W=1.10kg, Priority=7
Index 6 => ID=1, Sender=AbhinavMani, Dest=Mumbai, W=0.30kg, Priority=5
Index 7 => ID=7, Sender=Gita, Dest=Lucknow, W=9.20kg, Priority=3
Index 8 => ID=4, Sender=Devansh, Dest=Chennai, W=3.10kg, Priority=1
Index 9 => ID=9, Sender=Deepa, Dest=Jaipur, W=4.00kg, Priority=4
Index 10 => ID=2, Sender=AdityaMishra, Dest=Delhi, W=2.30kg, Priority=2
```

## Deletion

```bash
--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 4
Inserted package ID 1 with priority 5
Inserted package ID 2 with priority 2
Inserted package ID 3 with priority 9
Inserted package ID 4 with priority 1
Inserted package ID 5 with priority 7
Inserted package ID 6 with priority 9
Inserted package ID 7 with priority 3
Inserted package ID 8 with priority 6
Inserted package ID 9 with priority 4
Inserted package ID 10 with priority 8
Inserted 10 sample packages.

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 3 (priority 9) -> Sender: Chetan, Dest: Kolkata, Weight: 1.20kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 6 (priority 9) -> Sender: Farhan, Dest: Hyderabad, Weight: 3.10kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 10 (priority 8) -> Sender: Jai, Dest: Patna, Weight: 5.00kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 5 (priority 7) -> Sender: Esha, Dest: Pune, Weight: 4.00kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 8 (priority 6) -> Sender: Hari, Dest: Lucknow, Weight: 2.50kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 1 (priority 5) -> Sender: Aman, Dest: Mumbai, Weight: 0.50kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 9 (priority 4) -> Sender: Isha, Dest: Jaipur, Weight: 1.00kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 7 (priority 3) -> Sender: Gita, Dest: Bangalore, Weight: 0.30kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 2 (priority 2) -> Sender: Bina, Dest: Delhi, Weight: 2.00kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Served package ID 4 (priority 1) -> Sender: Deepa, Dest: Chennai, Weight: 0.80kg

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 2
Queue empty. Nothing to serve.

--- Package Delivery Priority Queue ---
1) Insert package
2) Serve (delete highest priority)
3) Display queue
4) Bulk sample insert (10 packages demo)
5) Exit
Choose: 5
Exiting. Freeing resources.
```
