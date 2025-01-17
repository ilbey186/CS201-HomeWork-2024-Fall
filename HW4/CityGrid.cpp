//Mehmet Ilbey Angur - Section 1 - 22303555

#include "CityGrid.h"
#include "Block.h"
#include "Queue.h"
#include <iostream>
#include <fstream>
#include <limits>

CityGrid::CityGrid()
{

}

CityGrid::CityGrid(std::string cityGridFile)
{
    std::ifstream file(cityGridFile);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open the city grid file.");
    }

    
    file >> rows >> columns;

    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    theCity = new Block*[rows];
    for (int i = 0; i < rows; i++)
    {
        theCity[i] = new Block[columns];
    }
    for (int i = 0; i < rows; i++)
    {
        std::string line;
        std::getline(file, line); 

        if (line.length() < static_cast<size_t>(columns)) 
        {
            throw std::runtime_error("Insufficient data in the city grid file.");
        }

        for (int j = 0; j < columns; j++)
        {
            char blockChar = line[j]; 
            int blockType = blockChar - '0'; 

            if (blockType < 0 || blockType > 2)
            {
                throw std::runtime_error("Invalid block type in the file.");
            }

            theCity[i][j].setBlockType(blockType);
            theCity[i][j].setLocation(j, i);
        }
    }

    file.close();
}




CityGrid::~CityGrid()
{
    for(int i = 0; i < rows; i++)
    {
        delete[] theCity[i];
    }
    delete[] theCity;
}

Block** CityGrid::getCity()
{
    return theCity;
}

void CityGrid::display() const
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::string blockType = theCity[i][j].getBlockType();
            
            if (blockType == "Empty")
                std::cout << "0";
            else if (blockType == "Healthy")
                std::cout << "1";
            else if (blockType == "Infected")
                std::cout << "2";
            else
                std::cout << "?"; 
        }
        std::cout << std::endl; 
    }
}

void CityGrid::simulate() 
{
    
    const int dX[4] = {0, 0, -1, 1};
    const int dY[4] = {-1, 1, 0, 0};

    
    Queue q;

    
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (theCity[i][j].getBlockType() == "Infected") 
            {
                q.enqueue(&theCity[i][j]);
            }
        }
    }

    
    while (!q.isEmpty()) 
    {
        Block* currentBlock = q.dequeue();
        int currentRow = currentBlock->getBlockY();
        int currentCol = currentBlock->getBlockX();

       
        for (int direction = 0; direction < 4; direction++) 
        {
            int newRow = currentRow + dY[direction];
            int newCol = currentCol + dX[direction];

        
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && theCity[newRow][newCol].getBlockType() == "Healthy") 
            {
                theCity[newRow][newCol].setBlockType(2); 
                q.enqueue(&theCity[newRow][newCol]);
            }
        }
    }
}

Block& CityGrid::getBlock(int row, int column) 
{
    if (row < 0 || row >= rows || column < 0 || column >= columns) 
    {
        cout << "Nothing to return out of bound";
    }
    return theCity[row][column];
}


int CityGrid::getColumns()
{
    return columns;
}

int CityGrid::getRows()
{
    return rows;
}
