# Data Structures Lab & Exam Preparation

This repository contains C implementations of various fundamental Data Structures and Algorithms. It is organized into two main sections: general lab experiments and unit-wise exam preparation modules.

## 📂 Directory Structure

### `DS_LAB/`
Contains core implementations of standard data structures:
*   `binary_search_tree.c` - Binary Search Tree operations (Insertion, Deletion, Search, Traversal).
*   `binary_tree_traversal.c` - Tree traversal algorithms.
*   `circular_queue.c` - Circular Queue implementation.
*   `doubly_linked_list.c` - Doubly Linked List operations.
*   `multiple_stacks.c` - Implementing multiple stacks within a single array.
*   `static_hashing.c` - Hashing techniques.

### `DS_SEE/`
Organized by syllabus units, likely for Semester End Exam (SEE) preparation:

*   **Unit 1:** Fundamental concepts.
    *   `dynamic_2D_alloc.c` - Dynamic memory allocation for 2D arrays.
    *   `str_concat_palin.c` - String concatenation and palindrome checking.
    *   `student_struct.c` - Usage of `struct` for storing student records.

*   **Unit 2:** Linear Data Structures (Stacks & Queues).
    *   `stack.c` - Standard Stack implementation.
    *   `circular_q.c` - Circular Queue variant.

*   **Unit 3:** Linked Lists.
    *   `single_LL.c` - Singly Linked List.
    *   `doubly_LL.c` - Doubly Linked List.
    *   `invert_LL.c` - Reversing/Inverting a Linked List.
    *   `polynomial_LL.c` - Polynomial addition using Linked Lists.
    *   `stack_LL.c` - Stack implementation using Linked Lists.

## 🚀 How to Compile and Run

Ensure you have a C compiler installed (like `gcc`).

**1. Open a terminal in the directory of the file you want to run.**

**2. Compile the code:**
```bash
gcc filename.c -o output_name
```
*Example:*
```bash
gcc DS_LAB/binary_search_tree.c -o bst
```

**3. Run the executable:**
*   **Windows:**
    ```bash
    bst.exe
    ```
*   **Linux/Mac:**
    ```bash
    ./bst
    ```

## 🛠 Prerequisites
*   **C Compiler:** GCC (GNU Compiler Collection) or Clang.
*   **OS:** Windows, Linux, or macOS.
