#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class Appointment {
   private:
    int hour;
    int minute;
    std::string purpose;

    int TotalMinutes() const;

   public:
    Appointment();
    Appointment(int hour, int minute, std::string purpose);

    bool operator<(const Appointment& other) const;
    bool operator>(const Appointment& other) const;
    bool operator==(const Appointment& other) const;
    void Print() const;
};

#endif
