#include <iostream>

// ==========================================
// TASK 1: 1D Dynamic Array Allocation
// ==========================================

/*
 * Question: Should the value 5 appear directly in the code?
 * Discussion: No, magic numbers like '5' shouldn't be hardcoded inside logic. 
 * Using a named constant (e.g., OFFSET_VAL) or default parameter improves readability, 
 * code maintenance, and adaptability if the offset requirements change later.
 */
void v_alloc_table_add_5(int iSize) {
    // Protection against invalid iSize
    if (iSize <= 0) {
        std::cout << "[Task 1 Error] Invalid size: " << iSize << ". Size must be greater than 0.\n";
        return;
    }

    const int OFFSET_VAL = 5;

    // Allocate memory dynamically
    int* piTable = new int[iSize];

    // Initialize elements with offset + 5 (index + 5)
    for (int i = 0; i < iSize; ++i) {
        piTable[i] = i + OFFSET_VAL;
    }

    // Display elements
    std::cout << "Task 1 Array elements: ";
    for (int i = 0; i < iSize; ++i) {
        std::cout << piTable[i] << " ";
    }
    std::cout << "\n";

    // Always deallocate dynamically allocated memory
    delete[] piTable;
}

// ==========================================
// TASK 2: 2D Dynamic Array Allocation
// ==========================================

/*
 * Determine what to insert instead of ??? when reference cannot be used:
 * To modify a pointer variable (piTable) inside a function without using references (int**&),
 * we must pass a pointer to that pointer: int*** piTable.
 */
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
    if (piTable == nullptr || iSizeX <= 0 || iSizeY <= 0) {
        return false;
    }

    // Allocate array of row pointers
    *piTable = new int*[iSizeX];

    // Allocate each row
    for (int i = 0; i < iSizeX; ++i) {
        (*piTable)[i] = new int[iSizeY];
    }

    return true;
}

// ==========================================
// TASK 3: 2D Dynamic Array Deallocation
// ==========================================

/*
 * Conceptual Questions Answered:
 * 1. Will there be a difference compared to b_alloc_table_2_dim?
 *    - Parameter type: int*** (pointer to pointer-to-pointer) or int** (if passing the allocated array pointer directly).
 *    - Logic: We iterate through each row to delete sub-arrays before deleting the main pointer array.
 * 2. Can b_dealloc_table_2_dim have fewer parameters than b_alloc_table_2_dim?
 *    - Yes! We only need iSizeX (number of rows) to loop through and delete each allocated sub-array. 
 *      The column size (iSizeY) is not required for deallocating dynamic memory in C++.
 */
bool b_dealloc_table_2_dim(int*** piTable, int iSizeX) {
    if (piTable == nullptr || *piTable == nullptr || iSizeX <= 0) {
        return false;
    }

    // Deallocate each row
    for (int i = 0; i < iSizeX; ++i) {
        delete[] (*piTable)[i];
    }

    // Deallocate row pointer array
    delete[] *piTable;

    // Reset caller's pointer to prevent dangling pointer access
    *piTable = nullptr;

    return true;
}

// ==========================================
// MAIN DRIVER FOR VISUAL STUDIO
// ==========================================

int main() {
    std::cout << "--- Testing Task 1 ---\n";
    v_alloc_table_add_5(5);
    v_alloc_table_add_5(-3); // Invalid size check

    std::cout << "\n--- Testing Task 2 & Task 3 ---\n";
    int** pi_table = nullptr;
    int sizeX = 5;
    int sizeY = 3;

    if (b_alloc_table_2_dim(&pi_table, sizeX, sizeY)) {
        std::cout << "2D Array (" << sizeX << "x" << sizeY << ") successfully allocated.\n";

        // Populate array to verify structure
        int count = 1;
        for (int i = 0; i < sizeX; ++i) {
            for (int j = 0; j < sizeY; ++j) {
                pi_table[i][j] = count++;
            }
        }

        // Print 2D array
        std::cout << "Array contents:\n";
        for (int i = 0; i < sizeX; ++i) {
            for (int j = 0; j < sizeY; ++j) {
                std::cout << pi_table[i][j] << "\t";
            }
            std::cout << "\n";
        }

        // Deallocate using reduced parameter count (no sizeY needed)
        if (b_dealloc_table_2_dim(&pi_table, sizeX)) {
            std::cout << "2D Array successfully deallocated.\n";
        } else {
            std::cout << "Failed to deallocate 2D array.\n";
        }
    } else {
        std::cout << "Failed to allocate 2D array.\n";
    }

    return 0;
}