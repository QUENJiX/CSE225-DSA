#include "book.h"
#include <iostream>
using namespace std;

Book::Book() {
    isbn = 0;
    title = "";
    price = 0.0;
}

Book::Book(int isbn, string title, double price) {
    this->isbn = isbn;
    this->title = title;
    this->price = price;
}

bool Book::operator==(const Book& other) const {
    return isbn == other.isbn;
}

bool Book::operator!=(const Book& other) const {
    return !(*this == other);
}

void Book::Print() const {
    cout << isbn << ", " << title << ", " << price << endl;
}
