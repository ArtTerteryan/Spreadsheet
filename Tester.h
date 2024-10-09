#ifndef TESTER_H
#define TESTER_H

#include "Cell.h"
#include "Spreadsheet.h"

class Tester {
public:
    static void testCellDataTypes();
    static void testAddColumn();
    static void testRemoveColumn();
    static void testToInt();
    static void testSetCellAt();
    static void testAddRow();
    static void testRemoveRow();

    static void runAllTests();
};

#endif
