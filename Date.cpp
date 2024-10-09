#include "Date.h"
#include <iomanip>

Date::Date() : m_month(1), m_day(1), m_year(2024) {}

Date::Date(const int month, const int day, const int year) : m_month(month), m_day(day), m_year(year) {}

void Date::displayDate() const {
    std::cout << std::setw(2) << std::setfill('0') << m_day << '.'
              << std::setw(2) << std::setfill('0') << m_month << '.'
              << m_year;
}

int Date::getDay() const { return m_day; }
int Date::getMonth() const { return m_month; }
int Date::getYear() const { return m_year; }
