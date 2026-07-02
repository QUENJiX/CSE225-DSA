#ifndef DYNARR_H
#define DYNARR_H

class dynArr {
   private:
    int** data;
    int rows;
    int cols;
    bool isValidIndex(int row, int col);
    void copyFrom(const dynArr& other);

   public:
    dynArr();
    dynArr(int r, int c);
    dynArr(const dynArr& other);
    ~dynArr();

    dynArr& operator=(const dynArr& other);
    void clear();
    void allocate(int r, int c);
    void setValue(int row, int col, int value);
    int getValue(int row, int col);
    int getRows();
    int getCols();
    bool isEmpty();
};

#endif
