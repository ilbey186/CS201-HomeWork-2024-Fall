//Mehmet Ilbey Angur - Section 1 - 22303555

#ifndef CITYGRD
#define CITYGRID
#include "Block.h"
#include <fstream>

using namespace std;

class CityGrid
{
public:
    CityGrid();
    CityGrid(string cityGridFile);
    ~CityGrid();
    void display() const;
    void simulate();
    int getRows();
    int getColumns();
    Block** getCity();
    Block& getBlock(int row, int column);


private:
    Block** theCity = nullptr;
    int rows = 0;
    int columns = 0;
};

#endif //CITYGRID