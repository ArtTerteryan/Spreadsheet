#include "Tester.h"
#include <iostream>
#include <cassert>

void Tester::testCellDataTypes() {
    // Test INTEGER
    Cell cell1;
    cell1.setValue(100);
    assert(cell1.getDataType() == INTEGER);
    assert(cell1.getIntValue() == 100);

    // Test DOUBLE
    Cell cell2;
    cell2.setValue(3.14);
    assert(cell2.getDataType() == DOUBLE);
    assert(cell2.getDoubleValue() == 3.14);

    // Test STRING
    Cell cell3;
    cell3.setValue("Test String");
    assert(cell3.getDataType() == STRING);
    assert(cell3.getStringValue() == "Test String");

    // Test DATE
    Date date(12, 25, 2024);
    Cell cell4;
    cell4.setValue(date);
    assert(cell4.getDataType() == DATE);
    Date cellDate = cell4.getDateValue();
    assert(cellDate.getDay() == 25);
    assert(cellDate.getMonth() == 12);
    assert(cellDate.getYear() == 2024);

    std::cout << "testCellDataTypes() passed." << std::endl;
}

void Tester::testAddColumn() {
    Spreadsheet sheet(2, 2);
    Cell cell1(10, Red);
    Cell cell2(20, Blue);
    sheet.setCellAt(cell1, 0, 0);
    sheet.setCellAt(cell2, 1, 1);

    // Add Column
    sheet.addColumn(1);
    assert(sheet.getCellAt(0, 0).getIntValue() == 10);
    assert(sheet.getCellAt(1, 2).getIntValue() == 20);

    std::cout << "testAddColumn() passed." << std::endl;
}

void Tester::testRemoveColumn() {
    Spreadsheet sheet(2, 3);
    Cell cell1(10, Red);
    Cell cell2(20, Blue);
    sheet.setCellAt(cell1, 0, 0);
    sheet.setCellAt(cell2, 1, 2);

    // Remove Column
    sheet.removeColumn(1);
    assert(sheet.getCellAt(1, 1).getIntValue() == 20);

    std::cout << "testRemoveColumn() passed." << std::endl;
}

void Tester::testToInt() {
    Cell cell("42", White);
    try {
        int value = std::stoi(cell.getStringValue());
        assert(value == 42);
    } catch(...) {
        std::cerr << "testToInt() failed." << std::endl;
    }

    std::cout << "testToInt() passed." << std::endl;
}

void Tester::testSetCellAt() {
    Cell cell("40", White);
    Spreadsheet sheet(2, 2);
    sheet.setCellAt(cell, 1, 1);
    Cell& val = sheet.getCellAt(1, 1);
    assert(val.getStringValue() == "40");
    assert(val.getColor() == White);

    std::cout << "testSetCellAt() passed." << std::endl;
}

void Tester::testAddRow() {
    Cell cell("20", Red);
    Spreadsheet sheet(2, 2);
    sheet.setCellAt(cell, 1, 1);
    sheet.addRow(1);

    Cell& val = sheet.getCellAt(1, 1);
    assert(val.getStringValue() == "");
    assert(val.getColor() == White);

    std::cout << "testAddRow() passed." << std::endl;
}

void Tester::testRemoveRow() {
    Cell cell("20", Red);
    Spreadsheet sheet(3, 3);
    sheet.setCellAt(cell, 1, 1);
    sheet.removeRow(1);

    Cell& val = sheet.getCellAt(1, 1);
    assert(val.getStringValue() == "");
    assert(val.getColor() == White);

    std::cout << "testRemoveRow() passed." << std::endl;
}

void Tester::runAllTests() {
    testCellDataTypes();
    testAddColumn();
    testRemoveColumn();
    testToInt();
    testSetCellAt();
    testAddRow();
    testRemoveRow();

    std::cout << "All tests passed successfully." << std::endl;
}
