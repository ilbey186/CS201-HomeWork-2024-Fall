//Mehmet İlbey Angur - Section 2 - 22303555

#ifndef SPACEMISSIONMANAGEMENTSYSTEM_H
#define SPACEMISSIONMANAGEMENTSYSTEM_H

#include <string>
#include <cstdbool>

#include "Mission.h"

using namespace std;

class SpaceMissionManagementSystem {
public:
    
    SpaceMissionManagementSystem();
    ~SpaceMissionManagementSystem();
    void addMission( const string name, const string launchDate, const string destination );
    void removeMission( const string name );
    void addSpacecraft( const string name, const string type );
    void removeSpacecraft( const string name );
    void assignSpacecraftToMission( const string spacecraftName, const string missionName );
    void dropSpacecraftFromMission( const string spacecraftName );
    void showAllMissions() const;
    void showAllSpacecrafts() const;
    void showMission( const string name ) const;
    void showSpacecraft( const string name ) const;
    
private:
    int missionCount = 0;
    Mission* missions = nullptr;
    void incrementMissionCount();
    void decrementMissionsCount();
    int getMissionCount() const;
    Mission* getMissionArray() const;
    bool missionExist(Mission* missions, string name, int missionCount);
    int indexFindMission( Mission* missions,  string name, int missionCount) const;
    
    int spacecraftCount = 0;
    Spacecraft* spacecrafts = new Spacecraft[spacecraftCount];
    void incrementSpacecraftCount();
    void decrementSpacecraftCount();
    int getSpacecraftCount() const;
    Spacecraft* getSpacecraftArray() const;
    bool spacecraftExist(Spacecraft* missions, string name, int spacecraftCount);
    int indexFindSpacecraft(Spacecraft* missions, string name, int spacecraftCount) const;
};

#endif //SPACEMISSIONMANAGEMENTSYSTEM_H