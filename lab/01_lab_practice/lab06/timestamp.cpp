#include "timestamp.h"
#include <iomanip>
#include <iostream>

using namespace std;

timeStamp::timeStamp() {
    seconds = 0;
    minutes = 0;
    hours = 0;
}

timeStamp::timeStamp(
    int seconds,
    int minutes,
    int hours
) {
    this->seconds = seconds;
    this->minutes = minutes;
    this->hours = hours;
}

int timeStamp::TotalSeconds() {
    return hours * 3600
         + minutes * 60
         + seconds;
}

bool timeStamp::operator<(timeStamp other) {
    return TotalSeconds() < other.TotalSeconds();
}

bool timeStamp::operator>(timeStamp other) {
    return TotalSeconds() > other.TotalSeconds();
}

bool timeStamp::operator==(timeStamp other) {
    return seconds == other.seconds
        && minutes == other.minutes
        && hours == other.hours;
}

void timeStamp::Print() {
    cout << setfill('0')
         << setw(2) << seconds << ": "
         << setw(2) << minutes << ": "
         << setw(2) << hours
         << endl;
}
