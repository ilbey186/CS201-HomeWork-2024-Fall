//Mehmet İlbey Angur - Section 2 - 22303555

#include "Mission.h"
#include "SpaceMissionManagementSystem.h"


Mission::Mission(string name, string launchDate, string destination)
{
    missionName = name;
    missionLaunchDate = launchDate;
    missionDestination = destination;
    spacecraftCount = 0;
};

Mission::Mission()
{
    missionName = "";
    missionLaunchDate = "";
    missionDestination = "";
    spacecraftCount = 0;
};

Mission::~Mission()
{
    delete[] spacecrafts;
    spacecrafts = nullptr;
}

string Mission::getName() const
{
    return missionName;
}

string Mission::getLaunchDate() const
{
    return missionLaunchDate;
}

string Mission::getDestination() const
{
    return missionDestination;
}

int Mission::getSpacecraftCount() const
{
    return spacecraftCount;
}
Spacecraft*& Mission::getMissionSpacecrafts()
{
    return spacecrafts;
}
void Mission::setName(const string& name)
{
    missionName = name;
}

void Mission::setLaunchDate(const string& launchDate)
{
    missionLaunchDate = launchDate;
}

void Mission::setDestination(const string& destination)
{
    missionDestination = destination;
}

void Mission::setMissionSpacecrafts(Spacecraft* array)
{
    spacecrafts = array;
}

void Mission::incrementSpacecraftCount() 
{
    spacecraftCount++;
}

void Mission::decrementSpacecraftCount()
{
    spacecraftCount--;
}

Mission::Mission(const Mission& other)
    : missionName(other.missionName),
      missionLaunchDate(other.missionLaunchDate),
      missionDestination(other.missionDestination),
      spacecrafts(nullptr),
      spacecraftCount(other.spacecraftCount)
       
{
    if (other.spacecraftCount > 0 && other.spacecrafts != nullptr) 
    {
        spacecrafts = new Spacecraft[other.spacecraftCount];
        for (int i = 0; i < spacecraftCount; ++i) 
        {
            spacecrafts[i] = other.spacecrafts[i]; 
        }
    }
}

Mission& Mission::operator=(const Mission& other) 
{
        if (this == &other) 
        {
            return *this; 
        }

        delete[] spacecrafts;

        missionName = other.missionName;
        missionLaunchDate = other.missionLaunchDate;
        missionDestination = other.missionDestination;
        spacecraftCount = other.spacecraftCount;

     
        if (other.spacecraftCount > 0 && other.spacecrafts != nullptr) 
        {
            spacecrafts = new Spacecraft[spacecraftCount];
            for (int i = 0; i < spacecraftCount; ++i) 
            {
                spacecrafts[i] = other.spacecrafts[i]; 
            }
        } else 
        {
            spacecrafts = nullptr; 
        }

        return *this;
}