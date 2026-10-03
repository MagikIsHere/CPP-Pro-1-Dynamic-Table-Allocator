# C++ Dynamic Table Allocator & Memory Management

A C++ repository demonstrating raw memory management, dynamic array allocations (1D and 2D arrays), pointer arithmetic, and safe deallocation patterns.

## 📌 Project Overview

This repository provides standard C++ solutions for dynamic memory allocation and pointer manipulations without using container classes like `std::vector`. It covers essential memory control concepts including memory offset initialization, multi-dimensional pointer tables, and manual heap deallocation.

### Core Features

* **1D Dynamic Array Allocation (`v_alloc_table_add_5`)**:
  * Dynamically allocates standard integer arrays on the heap based on a size parameter.
  * Populates array elements using index offsets (`i + 5`).
  * Includes safety checks to guard against invalid or negative array sizes.
  * Properly releases memory using `delete[]`.

* **2D Dynamic Array Allocation (`b_alloc_table_2_dim`)**:
  * Allocates a 2D matrix ($X \times Y$) dynamically using a pointer-to-pointer-to-pointer (`int***`) setup without relying on C++ standard references (`&`).
  * Returns a boolean status (`true`/`false`) reflecting allocation success or edge-case input validation.

* **2D Dynamic Array Deallocation (`b_dealloc_table_2_dim`)**:
  * Safely traverses and deallocates every dynamically allocated row before deleting the outer pointer array.
  * **Optimized signature**: Demonstrates that deallocation only requires the primary row count (`iSizeX`) rather than both dimensions, as individual array block sizes are tracked internally by the runtime.
  * Nullifies the dangling pointer after deallocation.

---

## 🛠️ How to Run (Visual Studio / C++ Compiler)

1. Clone or download this repository:
   ```bash
   git clone [https://github.com/YOUR_USERNAME/cpp-dynamic-table-allocator.git](https://github.com/YOUR_USERNAME/cpp-dynamic-table-allocator.git)
