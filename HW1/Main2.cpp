#include <iostream>
using namespace std;
#include "Mission.h"
#include "SpaceMissionManagementSystem.h"
#include "Spacecraft.h"


int main()
{SpaceMissionManagementSystem SMS;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.addSpacecraft("Orion", "Crewed");
    cout << endl;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.addSpacecraft("Curiosity", "Rover");
    SMS.addSpacecraft("Stellar Quest", "Uncrewed");
    cout << endl;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.addSpacecraft("Stellar Quest", "Uncrewed");
    cout << endl;

    SMS.showAllSpacecrafts();
    return 0;
}