#include <iostream>
#include <fstream>

using namespace std;

#include "grid.h"

int grid::indexof (int row, int col) const {
  return row*cols+col;
}

bool grid::infected(int row, int col) const {
	return ((*area)[indexof(row, col)] == INFECTED);
}


grid::grid (string file) {
  
  ifstream grid_file;

  grid_file.open (file.c_str());

  grid_file >> rows;
  grid_file >> cols;

  area = new vector<bool>(rows*cols, NOT_INFECTED);


  while (true) { 
  
    int blob_row;
    int blob_col;

    grid_file >> blob_row;  
    grid_file >> blob_col;  

    if (grid_file.eof()) {
        break;
    }

    area->operator[](indexof(blob_row,blob_col)) = INFECTED;
  }
  
  grid_file.close();
}

grid::~grid () {
  delete area;
}

ostream &operator<<(ostream &stream, const grid& ob) {
	
	for (int row = 0; row < ob.rows; row++) {

		for (int col = 0; col < ob.cols; col++) {
			stream << ob.area->operator[](ob.indexof(row, col));
			stream << "  ";
		}

		stream << endl;
	}

	stream << endl;
	return stream;
}

int grid::count (int row, int col) {

	/* Begin Student Code */
	if(0<=row&&row < rows&&0<=col&&col <cols)
	{
		if(infected (row,col)&&area->operator[](indexof (row,col))
	    {
	    	note->operator[](indexof (row,col))="1+";
	    	return 1+count (row+1,col+1)+count (row+1,col)+
	    	count (row+1, col-1)+count (row-1, col+1)+
	    	count (row-1,col)+count (row-1,col-1);
		}
	else
	    return 0;
	}
	else
  	return 0;
	/* End Student Code */
}


