//Mehmet İlbey Angur - Section 2 - 22303555

#ifndef MISSION_H
#define MISSION_H

#include <string>

#include "Spacecraft.h"

using namespace std;
class Mission
{
public:
    Mission(string name, string launchDate, string destination);
    Mission();
    ~Mission();
    Mission(const Mission& other);
    Mission& operator=(const Mission& other);
    string getName() const;
    string getLaunchDate() const;
    string getDestination() const;
    int getSpacecraftCount() const;
    Spacecraft*& getMissionSpacecrafts();
    void setMissionSpacecrafts(Spacecraft* array);

    void setName(const string& name);
    void setLaunchDate(const string& launchDate);
    void setDestination(const string& destination);
    void incrementSpacecraftCount();
    void decrementSpacecraftCount();

private:
    string missionName;
    string missionLaunchDate;    
    string missionDestination;
    Spacecraft* spacecrafts = nullptr;
    int spacecraftCount = 0;
};

#endif //MISSION_H