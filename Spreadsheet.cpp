#include "Spreadsheet.h"
#include <stdexcept>

Spreadsheet::Spreadsheet(const int r, const int c) : row(r), col(c) {
    cells = new Cell*[row];
    for (int i = 0; i < row; i++) {
        cells[i] = new Cell[col];
    }
}

Spreadsheet::~Spreadsheet() {
    for (int i = 0; i < row; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}

void Spreadsheet::setCellAt(const Cell& cell, int r, int c) {
    if (r >= 0 && r < row && c >= 0 && c < col) {
        cells[r][c] = cell;
    } else {
        throw std::out_of_range("Cell position out of range");
    }
}

Cell& Spreadsheet::getCellAt(int r, int c) {
    if (r >= 0 && r < row && c >= 0 && c < col) {
        return cells[r][c];
    } else {
        throw std::out_of_range("Cell position out of range");
    }
}

void Spreadsheet::addRow(int r) {
    if (r < 0 || r > row) {
        throw std::out_of_range("Row index out of range");
    }
    Cell** newCells = new Cell*[row + 1];
    for(int i = 0; i <= row; i++) {
        newCells[i] = new Cell[col];
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < col; j++) {
            newCells[i][j] = cells[i][j];
        }
    }

    for(int i = r; i < row; i++) {
        for(int j = 0; j < col; j++) {
            newCells[i + 1][j] = cells[i][j];
        }
    }

    for(int i = 0; i < row; i++) {
        delete[] cells[i];
    }
    delete[] cells;

    cells = newCells;
    row += 1;
}

void Spreadsheet::removeRow(int r) {
    if (row <= 1) {
        throw std::logic_error("Cannot remove row: Spreadsheet must have at least one row");
    }
    if (r < 0 || r >= row) {
        throw std::out_of_range("Row index out of range");
    }
    Cell** newCells = new Cell*[row - 1];
    for(int i = 0; i < row - 1; i++) {
        newCells[i] = new Cell[col];
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < col; j++) {
            newCells[i][j] = cells[i][j];
        }
    }

    for(int i = r + 1; i < row; i++) {
        for(int j = 0; j < col; j++) {
            newCells[i - 1][j] = cells[i][j];
        }
    }

    for(int i = 0; i < row; i++) {
        delete[] cells[i];
    }
    delete[] cells;
    cells = newCells;
    row -= 1;
}

void Spreadsheet::addColumn(int c) {
    if (c < 0 || c > col) {
        throw std::out_of_range("Column index out of range");
    }
    for(int i = 0; i < row; i++) {
        Cell* newRow = new Cell[col + 1];
        for(int j = 0; j < c; j++) {
            newRow[j] = cells[i][j];
        }
        for(int j = c; j < col; j++) {
            newRow[j + 1] = cells[i][j];
        }
        delete[] cells[i];
        cells[i] = newRow;
    }
    col += 1;
}

void Spreadsheet::removeColumn(int c) {
    if (col <= 1) {
        throw std::logic_error("Cannot remove column: Spreadsheet must have at least one column");
    }
    if (c < 0 || c >= col) {
        throw std::out_of_range("Column index out of range");
    }
    for(int i = 0; i < row; i++) {
        Cell* newRow = new Cell[col - 1];
        for(int j = 0; j < c; j++) {
            newRow[j] =
            newRow[j] = cells[i][j];
        }
        for(int j = c + 1; j < col; j++) {
            newRow[j - 1] = cells[i][j];
        }
        delete[] cells[i];
        cells[i] = newRow;
    }
    col -= 1;
}

void Spreadsheet::swapRows(int r1, int r2) {
    if (r1 >= 0 && r1 < row && r2 >= 0 && r2 < row) {
        Cell* temp = cells[r1];
        cells[r1] = cells[r2];
        cells[r2] = temp;
    } else {
        throw std::out_of_range("Row index out of range");
    }
}

void Spreadsheet::swapColumns(int c1, int c2) {
    if (c1 >= 0 && c1 < col && c2 >= 0 && c2 < col) {
        for(int i = 0; i < row; i++) {
            Cell temp = cells[i][c1];
            cells[i][c1] = cells[i][c2];
            cells[i][c2] = temp;
        }
    } else {
        throw std::out_of_range("Column index out of range");
    }
}

void Spreadsheet::displaySpreadsheet() const {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cells[i][j].displayCell();
            std::cout << "   |   ";
        }
        std::cout << std::endl;
    }
}
