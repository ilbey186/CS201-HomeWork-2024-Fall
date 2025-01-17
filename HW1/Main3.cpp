#include <iostream>
using namespace std;
#include "Mission.h"
#include "SpaceMissionManagementSystem.h"
#include "Spacecraft.h"


int main()
{SpaceMissionManagementSystem SMS;

    SMS.showAllMissions();
    cout << endl;

    SMS.addMission("Apollo 11", "1969-07-16", "Moon");
    SMS.addMission("Mars Exploration", "2020-07-30", "Mars");
    SMS.addMission("Interstellar Voyage", "1969-07-16", "Alpha Centauri");
    cout << endl;

    SMS.showAllMissions();
    cout << endl;

    SMS.removeMission("Mars Exploration");
    SMS.removeMission("Apollo 11");
    cout << endl;

    SMS.showAllMissions();
    cout << endl;

    SMS.removeMission("Mars Exploration");
    cout << endl;

    SMS.showAllMissions();
    cout << endl;
    return 0;
}