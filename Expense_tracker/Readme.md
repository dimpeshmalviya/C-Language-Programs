# Expense Tracker in C

A simple command-line expense tracker written in C that allows users to **add**, **view**, and **delete** expenses stored in a CSV file.

## Features

- Add a new expense with **date**, **amount**, and **description**.
- View all expenses in a tabular format along with the **total expense**.
- Delete expenses by specifying the **date**.

## File Structure

- `expenses.csv` – Stores all the expenses in the format: `date,amount,description`.
- `main.c` – The main program source code.

## Usage

1. **Compile the program** using `gcc`:

```bash
gcc main.c -o expense_tracker
```
Run the program:
```bash
./expense_tracker
```

Follow the menu:

1. Add Expense – Enter date, amount, and description.

2. View Expenses – Displays all expenses with a total sum.

3. Delete Expense – Delete all expenses for a specific date.

4. Exit – Close the program.

Example
```bash
1. Add Expense
2. View Expenses
3. Delete Expense
4. Exit
Enter your choice: 1
Enter date (YYYY-MM-DD): 2025-10-18
Enter amount: 250.50
Enter description: Groceries
Expense added successfully!

Enter your choice: 2

Date            Amount  Description
------------------------------------
2025-10-18      250.50  Groceries
------------------------------------
Total: 250.50
```