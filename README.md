# LinkedList-Stack
# Task Management System (C Program)

Author: Omar Shoubaki  
ID: 1230329  
Section: 2  

## Project Overview
This project is a Task Management System implemented in C.  
It allows users to manage a list of tasks, perform or undo tasks, and generate summary reports through a simple menu-driven console interface.

The program demonstrates the use of linked lists and stacks to manage dynamic data efficiently.

## Features
1. Load tasks from file  
   Reads tasks from tasks.txt and stores them in a linked list.
2. Add a new task  
   Adds a new task with a unique ID, name, due date, and duration.
3. Delete a task  
   Removes a task from the list using its ID.
4. Search for a task  
   Allows searching by either task ID or task name (case-insensitive).
5. View unperformed tasks  
   Displays all tasks that have not yet been performed.
6. Perform a task  
   Moves the first unperformed task to the stack of performed tasks.
7. Undo a performed task  
   Pops the most recently performed task and moves it back to the unperformed list.
8. View performed tasks  
   Lists all tasks that have been completed so far.
9. Generate summary report  
   Creates a Report.txt file containing  
   - Unperformed tasks  
   - Undone tasks  
   - Finished tasks  
10. Exit the program

## Data Structures Used
Linked List  
Used to store and manage unperformed and undone tasks dynamically.

Stack  
Used to manage performed tasks in Last-In-First-Out (LIFO) order, enabling the undo feature.

## File Format
Input File (tasks.txt)  
Each task is stored in a single line in the following format:
id#name#date#duration

Example:
1#Submit report#2025-04-05#2.5
2#Prepare slides#2025-04-06#1.0
3#Meeting with team#2025-04-08#1.5


## How to Run
1. Make sure tasks.txt is in the same folder as your .c file.  
2. Compile the program using any C compiler
Copy code
3. Run the program:
./TaskManagementSystem
4. Follow the on-screen menu to perform operations.

## Generated Report
When you choose option 9 (Generate Summary Report),  
a file named Report.txt will be created containing all categorized task lists (unperformed, undone, and performed).

## Concepts Demonstrated
- Dynamic Memory Allocation  
- Linked List Traversal  
- Stack Operations (Push and Pop)  
- File Handling  
- String Manipulation and Case Conversion  

## Purpose
This project was developed as part of the COMP2421 – Data Structures course to demonstrate practical understanding of linked lists, stacks, and file handling in C.


Author: Omar Shoubaki  
Birzeit University  
Electrical and Computer Engineering Department
Birzeit University  
Electrical and Computer Engineering Department
