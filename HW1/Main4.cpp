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
    SMS.addSpacecraft("Curiosity", "Rover");
    SMS.addSpacecraft("Falcon", "Crewed");
    SMS.addSpacecraft("Lunar Lander", "Rover");
    cout << endl;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.removeSpacecraft("Lunar Lander");
    cout << endl;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.removeSpacecraft("Lunar Lander");
    SMS.removeSpacecraft("Falcon");
    cout << endl;

    SMS.showAllSpacecrafts();
    return 0;
}