#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
   private:
    int isbn;
    std::string title;
    double price;

   public:
    Book();
    Book(int isbn, std::string title, double price);

    bool operator==(const Book& other) const;
    bool operator!=(const Book& other) const;
    void Print() const;
};

#endif
