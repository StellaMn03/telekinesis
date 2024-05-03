#ifndef cell_hpp
#define cell_hpp 
#include "cell.h"


Cell::Cell()
    : storage("")
 {}

Cell::Cell(int i) 
    : storage(std::to_string(i))
 {}

Cell::Cell(double d) 
    : storage(std::to_string(d))
 {}

Cell::Cell(const std::string& s) 
    : storage(s)
  {}

Cell::Cell(const Cell& rhs) 
     : storage(rhs.storage)
  {}

Cell::Cell(Cell&& rhs) noexcept 
: storage(std::move(rhs.storage))  
  {}

Cell::~Cell() {}

const Cell& Cell::operator=(const Cell& rhs) {
    if (this != &rhs) {
        storage = rhs.storage;
    }
    return *this;
}

const Cell& Cell::operator=(Cell&& rhs) {
    if (this != &rhs) {
        storage = std::move(rhs.storage);
    }
    return *this;
}
std::string Cell::get_val_cell()
{
	return storage;
}
#endif
