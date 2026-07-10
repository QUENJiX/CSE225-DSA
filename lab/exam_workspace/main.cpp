#include <iostream>
#include "appointment.h"
#include "book.h"
#include "sortedtype.h"
#include "sortedtype.cpp"
#include "unsortedtype.h"
#include "unsortedtype.cpp"
using namespace std;

void PrintUnsortedIntegers(UnsortedType<int>& list) {
    int item;
    list.Reset();
    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(item);
        cout << item << " ";
    }
    cout << endl;
}

void PrintSortedIntegers(SortedType<int>& list) {
    int item;
    list.Reset();
    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(item);
        cout << item << " ";
    }
    cout << endl;
}

void PrintBooks(UnsortedType<Book>& list) {
    Book item;
    list.Reset();
    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(item);
        item.Print();
    }
}

void PrintAppointments(SortedType<Appointment>& list) {
    Appointment item;
    list.Reset();
    for (int i = 0; i < list.Length(); i++) {
        list.GetNext(item);
        item.Print();
    }
}

template <class ListType, class ItemType>
void PrintSearchResult(const ListType& list, const ItemType& value) {
    bool found;
    list.Search(value, found);
    cout << (found ? "Item is found" : "Item is not found") << endl;
}

int main() {
    cout << "LAB 5 - UNSORTED INTEGER LIST" << endl;
    UnsortedType<int> unsortedNumbers;
    unsortedNumbers.Insert(5);
    unsortedNumbers.Insert(7);
    unsortedNumbers.Insert(6);
    unsortedNumbers.Insert(9);
    PrintUnsortedIntegers(unsortedNumbers);
    cout << "Length: " << unsortedNumbers.Length() << endl;
    PrintSearchResult(unsortedNumbers, 7);
    unsortedNumbers.Delete(7);  // Last item replaces 7; order is not preserved.
    PrintUnsortedIntegers(unsortedNumbers);

    cout << "\nLAB 5 - UNSORTED BOOK LIST" << endl;
    UnsortedType<Book> books;
    books.Insert(Book(101, "Algorithms", 650.0));
    books.Insert(Book(205, "Data Structures", 720.0));
    books.Insert(Book(310, "C++ Basics", 500.0));
    books.Delete(Book(205, "", 0.0));  // operator== compares ISBN only.
    PrintBooks(books);

    cout << "\nLAB 6 - SORTED INTEGER LIST" << endl;
    SortedType<int> sortedNumbers;
    sortedNumbers.Insert(5);
    sortedNumbers.Insert(4);
    sortedNumbers.Insert(2);
    sortedNumbers.Insert(7);
    sortedNumbers.Insert(1);
    PrintSortedIntegers(sortedNumbers);
    PrintSearchResult(sortedNumbers, 4);
    sortedNumbers.Delete(4);  // Later items shift left; order is preserved.
    PrintSortedIntegers(sortedNumbers);

    cout << "\nLAB 6 - SORTED APPOINTMENT LIST" << endl;
    SortedType<Appointment> appointments;
    appointments.Insert(Appointment(14, 30, "Project meeting"));
    appointments.Insert(Appointment(9, 15, "Lab assessment"));
    appointments.Insert(Appointment(12, 0, "Lunch"));
    appointments.Insert(Appointment(16, 45, "Library"));
    appointments.Delete(Appointment(12, 0, ""));
    PrintAppointments(appointments);

    return 0;
}
