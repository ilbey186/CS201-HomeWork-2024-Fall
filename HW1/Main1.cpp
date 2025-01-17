#include <iostream>
using namespace std;
#include "Mission.h"
#include "SpaceMissionManagementSystem.h"
#include "Spacecraft.h"

int main()
{
    SpaceMissionManagementSystem SMS;

    SMS.showAllMissions();
    cout << endl;

    SMS.addMission("Apollo 11", "1969-07-16", "Moon");
    cout << endl;

    SMS.showAllMissions();
    cout << endl;

    SMS.addMission("Mars Exploration", "2020-07-30", "Mars");
    SMS.addMission("Voyager 1", "2025-08-10", "Jupiter");
    cout << endl;

    SMS.showAllMissions();
    cout << endl;

    SMS.addMission("Apollo 11", "1969-07-16", "Moon");
    cout << endl;

    SMS.showAllMissions();
    return 0;
}