#include "appointment.h"
#include <iomanip>
#include <iostream>
using namespace std;

Appointment::Appointment() {
    hour = 0;
    minute = 0;
    purpose = "";
}

Appointment::Appointment(int hour, int minute, string purpose) {
    this->hour = hour;
    this->minute = minute;
    this->purpose = purpose;
}

int Appointment::TotalMinutes() const {
    return hour * 60 + minute;
}

bool Appointment::operator<(const Appointment& other) const {
    return TotalMinutes() < other.TotalMinutes();
}

bool Appointment::operator>(const Appointment& other) const {
    return TotalMinutes() > other.TotalMinutes();
}

bool Appointment::operator==(const Appointment& other) const {
    return hour == other.hour && minute == other.minute;
}

void Appointment::Print() const {
    cout << setfill('0') << setw(2) << hour << ":" << setw(2) << minute
         << setfill(' ') << " - " << purpose << endl;
}
