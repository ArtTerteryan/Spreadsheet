#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include "Cell.h"

class Spreadsheet {
private:
    Cell** cells;
    int row;
    int col;

public:
    Spreadsheet(const int r, const int c);
    ~Spreadsheet();

    void setCellAt(const Cell& cell, int r, int c);
    Cell& getCellAt(int r, int c);
    void addRow(int r);
    void removeRow(int r);
    void addColumn(int c);
    void removeColumn(int c);
    void swapRows(int r1, int r2);
    void swapColumns(int c1, int c2);
    void displaySpreadsheet() const;
};

#endif
