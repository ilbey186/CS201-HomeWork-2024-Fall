//Mehmet Ilbey Angur - Section 1 - 22303555

#include "PandemicSimulator.h"
#include <fstream>
#include <iostream>

PandemicSimulator::PandemicSimulator(const string cityGridFile) : city(cityGridFile), maxDays(0) 
{
   
    infectionTimes = new int*[city.getRows()];
    for (int i = 0; i < city.getRows(); ++i) 
    {
        infectionTimes[i] = new int[city.getColumns()];
    }

   initializeInfectionTimes();

    preComputeInfectionTimes();
}


PandemicSimulator::~PandemicSimulator ()
{
    for (int i = 0; i < city.getRows(); ++i) 
    {
        delete[] infectionTimes[i];
    }
    delete[] infectionTimes;
}

void PandemicSimulator::initializeInfectionTimes() 
{
   
    for (int i = 0; i < city.getRows(); ++i) 
    {
        for (int j = 0; j < city.getColumns(); ++j) 
        {
            Block& block = city.getBlock(i, j);

            if (block.getBlockType() == "Infected") 
            {
                infectionTimes[i][j] = 0;
            } 
            else 
            {
                infectionTimes[i][j] = -1; 
            }
        }
    }
}

void PandemicSimulator::preComputeInfectionTimes() 
{
    
    const int dX[4] = {0, 0, -1, 1};
    const int dY[4] = {-1, 1, 0, 0};
    Queue q;

    for (int i = 0; i < city.getRows(); ++i) 
    {
        for (int j = 0; j < city.getColumns(); ++j) 
        {
            Block& block = city.getBlock(i, j);
            if (block.getBlockType() == "Infected") 
            {
                infectionTimes[i][j] = 0;
                q.enqueue(&block);
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

            if (newRow >= 0 && newRow < city.getRows() && newCol >= 0 && newCol < city.getColumns()) 
            {
                Block& neighborBlock = city.getBlock(newRow, newCol);

                
                if (neighborBlock.getBlockType() == "Healthy" && infectionTimes[newRow][newCol] == -1) 
                {
                    infectionTimes[newRow][newCol] = infectionTimes[currentRow][currentCol] + 1;
                    q.enqueue(&neighborBlock);  
                }
            }
        }
    }
}

void PandemicSimulator::displayCityState(const int time) 
{
    std::cout << "City state at day " << time << ":\n";

 
    for (int i = 0; i < city.getRows(); ++i) 
    {
        for (int j = 0; j < city.getColumns(); ++j) 
        {
            Block& block = city.getBlock(i, j);

            if (block.getBlockType() == "Empty") 
            {
                std::cout << "0";
            } 
            else if (block.getBlockType() == "Healthy") 
            {
                if (infectionTimes[i][j] == -1 || infectionTimes[i][j] > time) 
                {
                    std::cout << "1"; 
                }
                else 
                {
                    std::cout << "2"; 
                }
            } 
            else if (block.getBlockType() == "Infected") 
            {
                std::cout << "2"; 
            }
        }
        std::cout << std::endl;
    }
}

void PandemicSimulator::simulateBlock(const int row , const int col) 
{
    if (row < 0 || row >= city.getRows() || col < 0 || col >= city.getColumns()) 
    {
        std::cout << "Invalid block coordinates.\n";
        return;
    }
    std::cout << "Time for block (" << row << ", " << col << ") to be infected: " << infectionTimes[row][col] << " days.\n";
}

void PandemicSimulator::simulatePandemic() {
    const int dX[4] = {0, 0, -1, 1};
    const int dY[4] = {-1, 1, 0, 0};
    Queue q;
    int day = 0;
    bool allInfected = true;

    for (int i = 0; i < city.getRows(); ++i) 
    {
        for (int j = 0; j < city.getColumns(); ++j) 
        {
            Block& block = city.getBlock(i, j);

            if (block.getBlockType() == "Infected") 
            {
                infectionTimes[i][j] = 0;
                q.enqueue(&block); 
            } 
            else 
            {
                infectionTimes[i][j] = -1; 
            }
        }
    }

    while (!q.isEmpty()) 
    {
        int currentLevelSize = q.getSize();
        for (int i = 0; i < currentLevelSize; i++) 
        {
            Block* currentBlock = q.dequeue();
            int currentRow = currentBlock->getBlockY();
            int currentCol = currentBlock->getBlockX();

            for (int direction = 0; direction < 4; direction++) 
            {
                int newRow = currentRow + dY[direction];
                int newCol = currentCol + dX[direction];

                if (newRow >= 0 && newRow < city.getRows() &&
                    newCol >= 0 && newCol < city.getColumns()) 
                    {
                    Block& neighborBlock = city.getBlock(newRow, newCol);

                    if (neighborBlock.getBlockType() == "Healthy" && infectionTimes[newRow][newCol] == -1) 
                    {
                        neighborBlock.setBlockType(2); 
                        infectionTimes[newRow][newCol] = infectionTimes[currentRow][currentCol] + 1;
                        q.enqueue(&neighborBlock); 
                    }
                }
            }
        }
        day++;
    }

    maxDays = day - 1;

    for (int i = 0; i < city.getRows(); i++) 
    {
        for (int j = 0; j < city.getColumns(); j++) 
        {
            if (city.getBlock(i, j).getBlockType() == "Healthy" && infectionTimes[i][j] == -1)
            {
                allInfected = false;
                break;
            }
        }
        if (!allInfected) break;
    }

    if (!allInfected) 
    {
        std::cout << "Pandemic cannot spread to all blocks." << std::endl;
    } 
    else 
    {
        std::cout << "Minimum time for pandemic to spread to all blocks: " << maxDays << " days." << std::endl;
    }
}