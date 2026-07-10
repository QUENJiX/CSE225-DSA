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
