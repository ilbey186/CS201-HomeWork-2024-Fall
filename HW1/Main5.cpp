#include <iostream>
using namespace std;
#include "Mission.h"
#include "SpaceMissionManagementSystem.h"
#include "Spacecraft.h"


int main()
{SpaceMissionManagementSystem SMS;

    SMS.showAllMissions();
    cout << endl;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.addMission("Apollo 11", "1969-07-16", "Moon");
    SMS.addMission("Mars Exploration", "2020-07-30", "Mars");
    SMS.addMission("Jupiter Orbiter", "2030-01-01", "Jupiter");
    SMS.addMission("Apollo 11", "1969-07-16", "Moon");
    cout << endl;

    SMS.showAllMissions();
    cout << endl;

    SMS.removeMission("Voyager 5");
    SMS.removeMission("Jupiter Orbiter");
    cout << endl;

    SMS.showAllMissions();
    cout << endl;

    SMS.addSpacecraft("Orion", "Crewed");
    SMS.addSpacecraft("Voyager 1", "Uncrewed");
    SMS.addSpacecraft("Curiosity", "Rover");
    SMS.addSpacecraft("Enterprise", "Crewed");
    SMS.addSpacecraft("Voyager 1", "Uncrewed");
    SMS.addSpacecraft("Voyager 2", "Rover");
    cout << endl;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.removeSpacecraft("Hubble");
    SMS.removeSpacecraft("Orion");
    cout << endl;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.assignSpacecraftToMission("Voyager 1", "Mars Exploration");
    SMS.assignSpacecraftToMission("Voyager 2", "Mars Exploration");
    SMS.assignSpacecraftToMission("Curiosity", "Apollo 11");
    cout << endl;

    SMS.showAllMissions();
    cout << endl;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.removeSpacecraft("Voyager 1");
    SMS.removeSpacecraft("Curiosity");
    cout << endl;

    SMS.assignSpacecraftToMission("Orion", "Apollo 11");
    SMS.assignSpacecraftToMission("Enterprise", "Saturn Voyage");
    SMS.assignSpacecraftToMission("Orion", "Saturn Voyage");
    SMS.assignSpacecraftToMission("Voyager 1", "Mars Exploration");
    SMS.assignSpacecraftToMission("Curiosity", "Mars Exploration");
    SMS.assignSpacecraftToMission("Enterprise", "Mars Exploration");
    cout << endl;

    SMS.showMission("Mars Exploration");
    cout << endl;

    SMS.dropSpacecraftFromMission("Voyager 1");
    SMS.dropSpacecraftFromMission("Orion");
    SMS.dropSpacecraftFromMission("Curiosity");
    SMS.dropSpacecraftFromMission("Voyager 1");
    cout << endl;

    SMS.showAllMissions();
    cout << endl;

    SMS.showAllSpacecrafts();
    cout << endl;

    SMS.showMission("Apollo 11");
    cout << endl;

    SMS.showMission("Voyager 10");
    cout << endl;

    SMS.showSpacecraft("Voyager 2");
    cout << endl;

    SMS.showSpacecraft("Hubble");
    cout << endl;

    SMS.removeMission("Mars Exploration");
    cout << endl;

    SMS.showAllSpacecrafts();
    return 0;
}