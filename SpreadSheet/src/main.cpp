#include <iostream>
#include "spreadSheet.h"
int main()
{
 
// spreadSheet obj;
// spreadSheet ov = obj;
// spreadSheet ob1;
// ob1 = obj;
// spreadSheet source; 
//spreadSheet target(std::move(source));

// obj.addColumn();

 spreadSheet mat(3);
 spreadSheet mat2(4,5);
 mat2.get_col_size();
 mat2.get_row_size();
 mat2.addRow();
 mat2.delete_col(3);
 mat2.get_col_size();
 mat2.get_row_size();
  return 0;
}
