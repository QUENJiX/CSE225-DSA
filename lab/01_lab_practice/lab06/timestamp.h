#ifndef TIMESTAMP_H
#define TIMESTAMP_H

class timeStamp {
private:
    int seconds;
    int minutes;
    int hours;

    int TotalSeconds();

public:
    timeStamp();
    timeStamp(int seconds, int minutes, int hours);

    bool operator<(timeStamp other);
    bool operator>(timeStamp other);
    bool operator==(timeStamp other);

    void Print();
};

#endif
