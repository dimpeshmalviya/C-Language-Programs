# Doubly Linked List Implementation

**File:** `data_structures/doubly_linked_lists/doubly_linked_list.c`

---

## 📝 Problem Statement

This program implements the **Doubly Linked List (DLL)**, a fundamental dynamic data structure in C. A DLL is a sequential collection of elements where each node contains the data, a pointer to the next node (`next`), and crucially, a pointer to the previous node (`prev`).

This bi-directional linking allows for traversal in both forward and backward directions, unlike a Singly Linked List.

---

## ✨ Key Functions

| Function | Description | Complexity (Worst-Case) |
| :--- | :--- | :--- |
| `insert_at_end(data)` | Adds a new node containing `data` to the end of the list. | **O(1)** |
| `delete_node(key)` | Searches for and deletes the first node whose data matches `key`. | **O(N)** |
| `display_forward()` | Traverses and prints the list elements from the **Head** to the **Tail**. | **O(N)** |
| `display_backward()` | Traverses and prints the list elements from the **Tail** to the **Head**. | **O(N)** |

---

## 💡 Approach

The implementation uses a `struct Node` with three fields: `data`, `next`, and `prev`. Global pointers `head` and `tail` are maintained to ensure that insertion and deletion operations at the beginning or end of the list can be completed in $O(1)$ time.

---

## 🚀 How to Compile and Run

1.  **Compile the code** using `gcc`:
    ```bash
    gcc data_structures/doubly_linked_lists/oubly_linked_list.c -o dll
    ```

2.  **Run the executable**:
    ```bash
    ./dll
    ```

---

## 💻 Example Input and Output (Menu-Driven)

The program provides a command-line menu to demonstrate all operations.

**Interaction Example:**

| Step | Input (User Choice) | Operation |
| :--- | :--- | :--- |
| 1. | `1` (followed by `10`) | Insert node `10` at the end. |
| 2. | `1` (followed by `20`) | Insert node `20` at the end. |
| 3. | `3` | Display list forward. |
| 4. | `4` | Display list backward. |
| 5. | `2` (followed by `10`) | Delete node with value `10`. |
| 6. | `3` | Display list forward. |
| 7. | `5` | Exit the program. |

**Expected Output:**

<pre>
--- Doubly Linked List Operations ---

...
Enter choice: 1
Enter data to insert: 10
Inserted 10 at the end.

...
Enter choice: 1
Enter data to insert: 20
Inserted 20 at the end.

...
Enter choice: 3
List Forward: 10 -> 20 -> NULL

...
Enter choice: 4
List Backward: 20 -> 10 -> NULL

...
Enter choice: 2
Enter value of node to delete: 10
Node with value 10 deleted.

...
Enter choice: 3
List Forward: 20 -> NULL

...
Enter choice: 5
Exiting program. Goodbye!

</pre>