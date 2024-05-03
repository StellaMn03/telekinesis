#ifndef SPREADSHEET_HPP
#define SPREADSHEET_HPP


#include "spreadSheet.h"

#include <string>

spreadSheet::spreadSheet()
	: ob{nullptr} 
	, row{0}
	, col{0}
{}

spreadSheet::spreadSheet(size_t n)
	: row{n} 
	, col{n}
{
	ob = new Cell*[row];
	for(size_t i=0; i < n; i++){
		ob[i] = new Cell[n];
     }
}


spreadSheet::spreadSheet(size_t size_row, size_t size_col)
	: ob{nullptr}
	, row{size_row}
	, col{size_col}
{
	ob = new Cell*[row];
	for(size_t i = 0;i < size_row;i++)
	{
		ob[i] = new Cell[size_col];
	}
}

spreadSheet::spreadSheet(const spreadSheet &other)
	: ob{nullptr}
	, row{other.row}
	, col{other.col}
{
	ob = new Cell *[row];
	for (size_t i = 0; i < row; ++i)
	{
		ob[i] = new Cell[col];
	}

	for (size_t i = 0; i < other.row; ++i)
	{
		for (size_t j = 0; j < other.col; ++j)
		{
			ob[i][j] = other.ob[i][j];
		}
	}
	std::cout << "lll";
}

spreadSheet::spreadSheet(spreadSheet &&other) noexcept
	: ob{nullptr}
	, row{other.row}
	, col{other.col}

{
	other.row = 0;
	other.col = 0;
	other.ob = nullptr;
	std::cout << "ooo";
}

spreadSheet::~spreadSheet()
{
	for (size_t i = 0; i < row; ++i)
	{
		delete[] ob[i];
		ob[i] = nullptr;
	}
	delete[] ob;
	ob = nullptr;
}

const spreadSheet &spreadSheet::operator=(const spreadSheet &rhv)
{
	if (this != &rhv)
	{
		for (size_t i = 0; i < row; ++i)
		{
			delete[] ob[i];
			ob[i] = nullptr;
		}

		row = rhv.row;
		col = rhv.col;

		ob = new Cell *[row];
		for (size_t i = 0; i < row; ++i)
		{
			ob[i] = new Cell[col];
		}

		for (size_t i = 0; i < row; ++i)
		{
			for (size_t j = 0; j < col; ++j)
			{
				ob[i][j] = rhv.ob[i][j];
			}
		}
	}
	return *this;
}
const spreadSheet &spreadSheet::operator=(spreadSheet &&rhv) noexcept
{
	if (this != &rhv)
	{
		for (size_t i = 0; i < row; ++i)
		{
			delete[] ob[i];
			ob[i] = nullptr;
		}

		row = rhv.row;
		col = rhv.col;
		ob = rhv.ob;

		rhv.row = 0;
		rhv.col = 0;
		rhv.ob = nullptr;
	}

	return *this;
}

const Cell *spreadSheet::operator[](size_t i)const
{
	return ob[i];
}

void spreadSheet::setCell(int size_row, int size_col, const std::string &str)
{
	if (size_row >= 0 && size_row < row && size_col >= 0 && size_col < col)
	{
		ob[size_row][size_col] = str;
	}
	else
	{
		std::cout << "try again";
	}
}

Cell& spreadSheet::get(size_t r, size_t c)
{
	return ob[r][c];
	}
void spreadSheet::addRow()
{
	Cell **newOb = new Cell *[row + 1];
	for (size_t i = 0; i < row; ++i)
	{
		newOb[i] = ob[i];
	}

	newOb[row] = new Cell[col];
	delete[] ob;
	++row;
	ob = newOb;
	newOb = nullptr;
}

void spreadSheet::addColumn()
{

	Cell **newOb = new Cell *[row];

	for (size_t i = 0; i < row; ++i)
	{

		ob[i] = new Cell[col + 1];

		for (size_t j = 0; j < col; ++j)
		{

			newOb[i][j] = ob[i][j];
		}
		newOb[i][col] = Cell();
	}

	for (size_t i = 0; i < row; ++i)
	{
		delete[] ob[i];
	}
	delete[] ob;

	++col;
	ob = newOb;
}

void spreadSheet::delete_row(size_t index){
	if(index > this->row){
		std::cout<<"out of range";
		return;
	}

	Cell** arr = new Cell*[row-1];
	for(size_t i=0, k=0 ; i<row ; i++){
		if(i != index){
			arr[k++] = ob[i];
         }
		else
		{
			delete[] ob[i];
        }
	}
    delete[] ob;
    ob = arr;
    row =row -1;
}

void spreadSheet::delete_col(size_t index){

	if( index > this->col)
	{
		std::cout <<"out of range";
		return;
	}

	for(size_t i=0; i<row; i++)
	{
		for(size_t j=0; j<col; j++){

			if( j == index){
		       for( size_t k = index; k < col-1; ++k)
					{
			          ob[i][k] = ob[i][k+1];
			        }
			}
		}
	}
  
   col = col-1;
}
size_t spreadSheet::get_row_size()
{
	int count = 0;
	for( size_t i = 0;i < row; ++i){
		count++;
	}

	std::cout << "row size`" <<count << std::endl;

	return 0;
}

size_t spreadSheet::get_col_size()
{
	int count = 0;
	for(size_t j = 0;j < col; ++j)
		{
			count++;
		}

    std::cout << "Col size`" << count << std::endl;

	return 0;
}
size_t spreadSheet::get_row()
{
	return row;
}
size_t spreadSheet::get_col()
{
	return col;
}

std::string spreadSheet::get_value(size_t i_row ,size_t j_col)
{
   for(size_t i = 0; i < row; ++i)
   {
	   if( i = i_row){
	      for(size_t j = 0; j < col; ++j)
	       {
			   if( j = j_col){

		          return  ob[i][j].get_val_cell();
			   }
		   }
	   }
   }
   throw std::invalid_argument("");
}


std::ostream& operator<<(std::ostream& out, spreadSheet& rhv)
{
	for(size_t i = 0;i < rhv.get_row(); ++i)
	{
		for( size_t j = 0; j < rhv.get_col(); ++j)
			{
				out << rhv.get_value(i,j);
			}
	}
	return out;
}


std::istream& operator>>(std::istream& in, spreadSheet& rhv)
{
	for ( size_t i = 0; i < rhv.get_row(); ++i)
	{
		for( size_t j = 0; j < rhv.get_col(); ++j)
		{
            std::string cellValue;
            in >> cellValue;
            rhv.setCell(i, j, cellValue); 
		}
	}
	return in;
}

#endif
