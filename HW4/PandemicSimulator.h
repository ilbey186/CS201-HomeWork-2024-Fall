//Mehmet Ilbey Angur - Section 1 - 22303555

#ifndef PANDEMIC_SIMULATOR
#define PANDEMIC_SIMULATOR
#include "CityGrid.h"
#include "Queue.h"
#include "Block.h"
#include <string>

using namespace std;
class PandemicSimulator 
{

public:
    PandemicSimulator(const string cityGridFile );
    ~PandemicSimulator ();
    
    
    void displayCityState(const int time);
    void simulateBlock(const int row , const int col);
    void simulatePandemic ();
private:
    void initializeInfectionTimes();
    void preComputeInfectionTimes();
    CityGrid city;
    int** infectionTimes; 
    int maxDays; 
  
};


#endif //PANDEMIC_SIMULATOR