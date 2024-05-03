#ifndef __SPREADSHEET_H_
#define __SPREADSHEET_H_

#include "cell.h"
#include <string>

class spreadSheet {
  private:
      Cell** ob;
	  size_t row;
	  size_t col;

  public:

      spreadSheet();
	  spreadSheet(size_t n);
	  spreadSheet(size_t size_row, size_t size_col );
	  spreadSheet(const spreadSheet&);
	  spreadSheet(spreadSheet&& ) noexcept;
	  ~spreadSheet();
      const spreadSheet& operator=(const spreadSheet& );
	  const spreadSheet& operator=(spreadSheet&& ) noexcept;
	  const Cell* operator[]( size_t) const;
	  void setCell(int row,int col, const std::string& str);
	  Cell& get(size_t r,size_t c);
	  void addRow();
	  void addColumn();
	  void delete_row(size_t index);
	  void delete_col(size_t index);
      size_t get_row_size();
      size_t get_col_size();
	  size_t get_row();
	  size_t get_col();
	  std::string get_value(size_t,size_t);
};

std::ostream& operator<<(std::ostream& out, spreadSheet& rhv);
std::istream& operator>>(std::istream& in, spreadSheet& rhv);

#include "spreadSheet.hpp"
#endif

 	  
