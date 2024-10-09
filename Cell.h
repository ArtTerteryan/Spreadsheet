#ifndef CELL_H
#define CELL_H

#include "Date.h"
#include <iostream>
#include <string>

enum Color {
    White,
    Red,
    Blue,
    Green,
    Yellow
};

enum DataType {
    STRING,
    INTEGER,
    DOUBLE,
    DATE
};

class Cell {
private:
    DataType dataType;
    union {
        int intValue;
        double doubleValue;
        Date* dateValue;
    };
    std::string stringValue;
    Color color;

    std::string colorToString() const;

public:
    Cell();
    Cell(int val, Color col);
    Cell(double val, Color col);
    Cell(const std::string& val, Color col);
    Cell(const Date& val, Color col);
    ~Cell();
    Cell(const Cell& other);
    Cell& operator=(const Cell& other);

    // Setters
    void setValue(int val);
    void setValue(double val);
    void setValue(const std::string& val);
    void setValue(const Date& val);
    void setColor(Color col);

    // Getters
    int getIntValue() const;
    double getDoubleValue() const;
    std::string getStringValue() const;
    Date getDateValue() const;
    DataType getDataType() const;
    Color getColor() const;

    void displayCell() const;
    void reset();
};

#endif
