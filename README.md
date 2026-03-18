# C++ Projects Repository

This repository contains my C++ projects for various courses. Each project is in its own folder named by the lab number and project name. The projects cover topics like authorship detection, recursion, data structures, and memory management.

## Projects

### Lab1_authorshipDetection
- **Topic:** Authorship Detection Part 1
- **Description:** Program to analyze text files and detect the likely author based on text statistics.
- **Purpose:** Practice file processing, string analysis, and using basic C++ data structures.
- **Files:** `main.cpp`, `authorStats.txt`, `mystery0.txt` … `mystery5.txt`
- **How to run:** Compile and run `main.cpp` in your preferred C++ environment. Make sure all `.txt` files are in the same folder.

### Lab2_pantryOnTheHeap
- **Topic:** Pantry on the Heap
- **Description:** Implements a pantry inventory system using heap memory.
- **Purpose:** Practice dynamic memory allocation and managing objects on the heap.
- **How to run:** Compile and run the provided `.cpp` file(s).

### Lab3_authorshipDetectionPart2
- **Topic:** Authorship Detection Part 2
- **Description:** Builds on Lab1. Creates and stores an array of `AuthorStats` structs on the heap, and finds the author who most likely wrote a mystery file.
- **Purpose:** Practice:
  - Using header files
  - Creating arrays of structs on the heap
  - Writing a simple optimization algorithm
  - File processing
- **Tasks:** 
  1. Copy Lab1 project and create a `.h` file for `AuthorStats` struct.
  2. Load author stats from `authorStats.txt` into an array on the heap.
  3. Calculate similarity scores to detect the author of mystery files.
- **How to run:** Compile `main.cpp` in the Lab3 folder. Ensure `authorStats.txt` and mystery files are present.

### Lab4_recursionExercises
- **Topic:** Recursion Exercises
- **Description:** Practice recursion through exercises like power function, binary search, string reversal, Fibonacci sequence, Twelve Days of Christmas song, and directory listing.
- **Purpose:** Strengthen recursion, search algorithms, and file system traversal.
- **Tasks:**
  1. Write recursive versions of `pow` and binary search.
  2. Write recursive string reversal and Fibonacci sequence functions.
  3. Print the Twelve Days of Christmas recursively.
  4. Extra Credit: Print a directory listing recursively using `dirent.h`.
- **How to run:** Compile and run `main.cpp` in the Lab4 folder. Input may be required for some exercises.

---

### Lab5_maze
- **Topic:** Maze Game
- **Description:** Create a maze game using classes for GamePlayer and Room, reading maze layout from files.
- **Purpose:** Practice:
  - Designing and implementing classes
  - Game design
  - Working with multiple files and header files

---

### Lab6_fractions
- **Topic:** Fraction Class
- **Description:** Implement a Fraction class with arithmetic operations (add, subtract, multiply, divide) and automatic reduction.
- **Purpose:** Practice:
  - Designing and implementing classes
  - Operator-like methods
  - Object-oriented programming

---

### Lab7_groupWork
- **Topic:** Forensic File Recovery
- **Description:** Recover corrupted JPEG files from a raw input file and recreate variations with your team.
- **Purpose:** Practice:
  - Loops and conditionals
  - Binary file I/O
  - Forensics and hexadecimal notation
  - Teamwork

---

### Lab8_intLinkedList
- **Topic:** Integer Linked List
- **Description:** Implement a linked list for integers with nodes and pointer-based operations.
- **Purpose:** Practice:
  - Linked lists
  - Using pointers
  - Classes and objects
  - Serializing/deserializing data

---

### Lab9_linkedList
- **Topic:** Generic Linked List
- **Description:** Upgrade Lab8 to a generic linked list using `void*` and function pointers for display and ordered insert.
- **Purpose:** Practice:
  - Generic programming with pointers
  - Function pointers
  - Problem solving

---

## How to run projects

1. Navigate into the lab folder you want to run.
2. Compile the program using your preferred C++ compiler:

```bash
g++ main.cpp -o program
