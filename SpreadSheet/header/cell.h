#ifndef Cell_h__
#define Cell_h__

#include <iostream>
#include <string>
class Cell {
private:
    std::string storage;

public:
    Cell();
    Cell(int i);
    Cell(double d);
    Cell(const std::string& s);
    Cell(const Cell& rhs);
    Cell(Cell&& rhs) noexcept;
    ~Cell();
    const Cell& operator=(const Cell& rhs);
    const Cell& operator=(Cell&& rhs);
	std::string get_val_cell();

};
#include "cell.hpp"
#endif
