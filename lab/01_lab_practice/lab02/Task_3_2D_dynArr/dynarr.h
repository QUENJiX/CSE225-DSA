/*
    CSE225L Lab 3 - Task 3: 2D dynArr Header

    Algorithm:
    1. Represent the matrix using int** data.
    2. Store row count and column count privately.
    3. Use clear() as a helper to delete an existing matrix safely.
    4. Use allocate(r, c) to create a new matrix.
    5. Use setValue(row, col, value) and getValue(row, col) for access.
    6. Use getRows and getCols to support nested loops in main.

    Pseudocode:
    CLASS dynArr
        PRIVATE:
            data: pointer to pointer to integer
            rows: integer
            cols: integer
            clear()
        PUBLIC:
            dynArr()
            dynArr(r, c)
            ~dynArr()
            allocate(r, c)
            setValue(row, col, value)
            getValue(row, col)
            getRows()
            getCols()
    END CLASS
*/

#ifndef DYNARR_H
#define DYNARR_H

class dynArr {
   private:
    int** data;
    int rows;
    int cols;
    void clear();

   public:
    dynArr();
    dynArr(int r, int c);
    ~dynArr();
    void allocate(int r, int c);
    void setValue(int row, int col, int value);
    int getValue(int row, int col);
    int getRows();
    int getCols();
};

#endif  // DYNARR_H
