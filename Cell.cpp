#include "Cell.h"
#include <stdexcept>

// Constructors
Cell::Cell() : dataType(STRING), stringValue(""), color(White) {}
Cell::Cell(int val, Color col) : dataType(INTEGER), intValue(val), color(col) {}
Cell::Cell(double val, Color col) : dataType(DOUBLE), doubleValue(val), color(col) {}
Cell::Cell(const std::string& val, Color col) : dataType(STRING), stringValue(val), color(col) {}
Cell::Cell(const Date& val, Color col) : dataType(DATE), dateValue(new Date(val)), color(col) {}

// Destructor
Cell::~Cell() {
    if (dataType == DATE && dateValue != nullptr) {
        delete dateValue;
    }
}

// Copy constructor
Cell::Cell(const Cell& other) : dataType(other.dataType), color(other.color) {
    switch (other.dataType) {
        case INTEGER:
            intValue = other.intValue;
            break;
        case DOUBLE:
            doubleValue = other.doubleValue;
            break;
        case STRING:
            stringValue = other.stringValue;
            break;
        case DATE:
            dateValue = new Date(*other.dateValue);
            break;
    }
}

// Assignment operator
Cell& Cell::operator=(const Cell& other) {
    if (this != &other) {
        if (dataType == DATE && dateValue != nullptr) {
            delete dateValue;
        }
        dataType = other.dataType;
        color = other.color;
        switch (other.dataType) {
            case INTEGER:
                intValue = other.intValue;
                break;
            case DOUBLE:
                doubleValue = other.doubleValue;
                break;
            case STRING:
                stringValue = other.stringValue;
                break;
            case DATE:
                dateValue = new Date(*other.dateValue);
                break;
        }
    }
    return *this;
}

// Setters
void Cell::setValue(int val) {
    if (dataType == DATE && dateValue != nullptr) {
        delete dateValue;
        dateValue = nullptr;
    }
    dataType = INTEGER;
    intValue = val;
}

void Cell::setValue(double val) {
    if (dataType == DATE && dateValue != nullptr) {
        delete dateValue;
        dateValue = nullptr;
    }
    dataType = DOUBLE;
    doubleValue = val;
}

void Cell::setValue(const std::string& val) {
    if (dataType == DATE && dateValue != nullptr) {
        delete dateValue;
        dateValue = nullptr;
    }
    dataType = STRING;
    stringValue = val;
}

void Cell::setValue(const Date& val) {
    if (dataType == DATE && dateValue != nullptr) {
        delete dateValue;
    }
    dataType = DATE;
    dateValue = new Date(val);
}

void Cell::setColor(Color col) {
    color = col;
}

// Getters
int Cell::getIntValue() const {
    if (dataType == INTEGER) {
        return intValue;
    }
    throw std::logic_error("Cell does not contain an integer value");
}

double Cell::getDoubleValue() const {
    if (dataType == DOUBLE) {
        return doubleValue;
    }
    throw std::logic_error("Cell does not contain a double value");
}

std::string Cell::getStringValue() const {
    if (dataType == STRING) {
        return stringValue;
    }
    throw std::logic_error("Cell does not contain a string value");
}

Date Cell::getDateValue() const {
    if (dataType == DATE && dateValue != nullptr) {
        return *dateValue;
    }
    throw std::logic_error("Cell does not contain a date value");
}

DataType Cell::getDataType() const { return dataType; }
Color Cell::getColor() const { return color; }

// Utility function to convert color to string
std::string Cell::colorToString() const {
    switch(color) {
        case White: return "white";
        case Red: return "red";
        case Blue: return "blue";
        case Green: return "green";
        case Yellow: return "yellow";
        default: return "unknown";
    }
}

// Display the content of a cell
void Cell::displayCell() const {
    std::cout << "Value=";
    switch(dataType) {
        case INTEGER:
            std::cout << intValue;
            break;
        case DOUBLE:
            std::cout << doubleValue;
            break;
        case STRING:
            std::cout << stringValue;
            break;
        case DATE:
            dateValue->displayDate();
            break;
    }
    std::cout << ", Color=" << colorToString();
}

void Cell::reset() {
    if (dataType == DATE && dateValue != nullptr) {
        delete dateValue;
        dateValue = nullptr;
    }
    dataType = STRING;
    stringValue = "";
    color = White;
}
