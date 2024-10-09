#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int m_month;
    int m_day;
    int m_year;
public:
    Date();
    Date(const int month, const int day, const int year);
    
    void displayDate() const;
    
    int getDay() const;
    int getMonth() const;
    int getYear() const;
};

#endif
