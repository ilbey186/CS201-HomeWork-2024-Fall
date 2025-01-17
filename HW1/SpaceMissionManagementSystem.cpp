//Mehmet İlbey Angur - Section 2 - 22303555

#include <iostream>
#include "SpaceMissionManagementSystem.h"

SpaceMissionManagementSystem::SpaceMissionManagementSystem()
: missionCount(0), missions(nullptr), spacecraftCount(0), spacecrafts(nullptr)
{}

SpaceMissionManagementSystem::~SpaceMissionManagementSystem()
{
    delete[] missions;
    missions = nullptr;
    delete[] spacecrafts;
    spacecrafts = nullptr;
};

void SpaceMissionManagementSystem::addMission(const string name, const string launchDate, const string destination)
{   
    Mission M(name, launchDate, destination);

    if (missionExist(getMissionArray(), name, getMissionCount())) 
    {
        cout << "Cannot add mission. Mission " << name << " already exists." << endl;

    } 
    else 
    {
        Mission* newArray = new Mission[getMissionCount() + 1];
        
        for (int i = 0; i < getMissionCount(); ++i) 
        {
            newArray[i] = missions[i];  
        }
        
        newArray[getMissionCount()] = M; 

        if (missions != nullptr) 
        {
            delete[] missions;
        }

        missions = newArray;
        
        incrementMissionCount();
        
        cout << "Added mission " << name << "." << endl;
    }
}

void SpaceMissionManagementSystem::removeMission( const string name )
{
    if(!missionExist(getMissionArray(), name, getMissionCount()))
    {
        cout << "Cannot remove mission. Mission " << name << " does not exist." << endl;
    }
    else
    {
        if(missionCount != 1)
        {
            for(int i = 0; i < spacecraftCount; i++)
            {
                if(spacecrafts[i].getSpacecraftCurrentMission() == name)
                {
                    spacecrafts[i].setSpacecraftStatus("Available");
                }
            }
            int index = indexFindMission(getMissionArray(), name, getMissionCount());
            Mission* newMissions = new Mission[getMissionCount() - 1];
            for(int i = 0 , j = 0; i < getMissionCount(); ++i)
            {
                if(i != index)
                {
                    newMissions[j] = missions[i];
                    j++;
                }
            }
            if(missions != nullptr)
            delete[] missions;

            missions = newMissions;
            decrementMissionsCount();
            cout << "Removed mission " << name << "." << endl; 
        }
        else
        {
            for(int i = 0; i < spacecraftCount; i++)
            {
                if(spacecrafts[i].getSpacecraftCurrentMission() == name)
                {
                    spacecrafts[i].setSpacecraftStatus("Available");
                }
            }
            delete[] missions;
            decrementMissionsCount();
            missions = nullptr;
            cout << "Removed mission " << name << "." << endl; 
        }
    }
} 

void SpaceMissionManagementSystem::addSpacecraft( const string name, const string type )
{
    Spacecraft S(name, type);
    if(spacecraftExist(getSpacecraftArray(), name, getSpacecraftCount()))
    {
        cout << "Cannot add spacecraft. Spacecraft " << name << " already exists." << endl;
    }
    else
    {
        Spacecraft* newArray = new Spacecraft[getSpacecraftCount() + 1];
        for(int i = 0; i < getSpacecraftCount(); ++i)
        {
            newArray[i] = spacecrafts[i];
        }
        newArray[getSpacecraftCount()] = S;
        
        if(spacecrafts != nullptr)
        delete[] spacecrafts;

        spacecrafts = newArray;
        incrementSpacecraftCount();
        cout << "Added spacecraft " << name << "." << endl;
        
    }
}

void SpaceMissionManagementSystem::removeSpacecraft( const string name )
{
    if(!spacecraftExist(getSpacecraftArray(), name, getSpacecraftCount()))
    {
        cout << "Cannot remove spacecraft. Spacecraft " << name << " does not exist." << endl;
    }
    else if(spacecrafts[indexFindSpacecraft(getSpacecraftArray(), name, getSpacecraftCount())].getSpacecraftStatus() == "Assigned")
    {
        cout << "Cannot remove spacecraft. Spacecraft " << name <<  " is assigned to a mission." << endl;
    }
    else
    {
        int index = indexFindSpacecraft(getSpacecraftArray(), name, getSpacecraftCount());
        if(spacecraftCount != 1)
        {
            Spacecraft* newArray = new Spacecraft[getSpacecraftCount() - 1];
            for(int i = 0 , j = 0; i < getSpacecraftCount(); ++i)
            {
                if(i != index)
                {
                    newArray[j] = spacecrafts[i];
                    j++;
                }
            }
            if(spacecrafts != nullptr)
            delete[] spacecrafts;

            spacecrafts = newArray;
            decrementSpacecraftCount();
            cout << "Removed spacecraft " << name << "." << endl;
        }
        else
        {   
            if(spacecrafts != nullptr)
            delete[] spacecrafts;
            spacecrafts = nullptr;
            decrementSpacecraftCount();
            cout << "Removed spacecraft " << name << "." << endl;
        }
    }
    
}

void SpaceMissionManagementSystem::assignSpacecraftToMission(const string spacecraftName, const string missionName)
{
    int spacecraftIndex = indexFindSpacecraft(spacecrafts, spacecraftName, spacecraftCount);
    if (spacecraftIndex == -1) 
    {
        cout << "Cannot assign spacecraft. Spacecraft " << spacecraftName << " does not exist." << endl;
        return;  
    }
    int missionIndex = indexFindMission(missions, missionName, missionCount);
    if(missionIndex == -1) 
    {
        cout << "Cannot assign spacecraft. Mission " << missionName << " does not exist." << endl;
        return;
    }
    if (spacecrafts[spacecraftIndex].getSpacecraftStatus() != "Available") 
    {
        cout << "Cannot assign spacecraft. Spacecraft " << spacecraftName
             << " is already assigned to mission "
             << spacecrafts[spacecraftIndex].getSpacecraftCurrentMission() << "." << endl;
        return;
    }
   
        Mission& mission = missions[missionIndex];

        Spacecraft* newArray = new Spacecraft[mission.getSpacecraftCount() + 1];
    
        for (int i = 0; i < mission.getSpacecraftCount(); ++i) 
        {
            newArray[i] = mission.getMissionSpacecrafts()[i];
        }
    
        newArray[mission.getSpacecraftCount()] = spacecrafts[spacecraftIndex];

        delete[] mission.getMissionSpacecrafts();
        mission.setMissionSpacecrafts(nullptr);
        mission.setMissionSpacecrafts(newArray);

        mission.incrementSpacecraftCount();

        spacecrafts[spacecraftIndex].setSpacecraftCurrentMission(missionName);
        spacecrafts[spacecraftIndex].setSpacecraftStatus("Assigned");

        cout << "Assigned spacecraft " << spacecraftName << " to mission " << missionName << "." << endl;
} 

void SpaceMissionManagementSystem::dropSpacecraftFromMission( const string spacecraftName )
{
    int spacecraftIndexInSystem = indexFindSpacecraft(getSpacecraftArray(), spacecraftName , spacecraftCount);
    if(!spacecraftExist(getSpacecraftArray(), spacecraftName, spacecraftCount))
    {
        cout << "Cannot drop spacecraft. Spacecraft " << spacecraftName <<" does not exist." << endl;
    }
    else if(spacecrafts[spacecraftIndexInSystem].getSpacecraftStatus() != "Assigned")
    {
        cout << "Cannot drop spacecraft. Spacecraft " << spacecraftName << " is not assigned to any mission." << endl;
    }
    else
    {
        
        int indexOfSpacecraftsMission = indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount);
        int indexOfSpacecraftInMission = indexFindSpacecraft(missions[indexOfSpacecraftsMission].getMissionSpacecrafts(), spacecraftName,missions[indexOfSpacecraftsMission].getSpacecraftCount() );
        if(missions[indexOfSpacecraftsMission].getSpacecraftCount() != 1)
        {
            cout << "Dropped spacecraft " << spacecraftName << " from mission " <<  spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission() << "." << endl;
            Spacecraft* newArray = new Spacecraft[missions[indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount)].getSpacecraftCount() - 1];
            for(int i = 0 , j = 0; i < missions[indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount)].getSpacecraftCount(); ++i)
            {
                if(i != indexOfSpacecraftInMission)
                {   
                
                    newArray[j] = missions[indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount)].getMissionSpacecrafts()[i];
                    j++;
                }
            }
            spacecrafts[spacecraftIndexInSystem].setSpacecraftStatus("Available");
            delete[] missions[indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount)].getMissionSpacecrafts();
            missions[indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount)].setMissionSpacecrafts(newArray);
            missions[indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount)].decrementSpacecraftCount();
        }
        else
        {
            delete[] missions[indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount)].getMissionSpacecrafts();
            spacecrafts[spacecraftIndexInSystem].setSpacecraftStatus("Available");
            cout << "Dropped spacecraft " << spacecraftName << " from mission " <<  spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission() << "." << endl;
            missions[indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount)].setMissionSpacecrafts(nullptr);
            missions[indexFindMission(missions, spacecrafts[spacecraftIndexInSystem].getSpacecraftCurrentMission(), missionCount)].decrementSpacecraftCount();
        }
        


    }
}

void SpaceMissionManagementSystem::showAllMissions() const
{
    cout << "Missions in the space mission management system:" << endl;
    if(getMissionCount() == 0)
    {
        cout << "None" << endl;
    }
    else
    {
        for(int i = 0; i < missionCount; i++)
        {
            cout << "Mission: " <<  missions[i].getName() << ", Launch Date: " << missions[i].getLaunchDate() 
                 << ", Destination: " << missions[i].getDestination() 
                 << ", Assigned Spacecraft Count: " << missions[i].getSpacecraftCount() << std::endl;
                
        }
    }
} 

void SpaceMissionManagementSystem::showAllSpacecrafts() const
{
    cout << "Spacecrafts in the space mission management system:" << endl;
    if(getSpacecraftCount() == 0)
    {
        cout << "None" << endl;
    }
    else
    {
        for(int i = 0; i < spacecraftCount; i++)
        {
            cout << "Spacecraft: " <<  spacecrafts[i].getSpacecraftName() << ", Type: " << spacecrafts[i].getSpacecraftType() 
                 << ", Status: " << spacecrafts[i].getSpacecraftStatus() << endl;
                 
        }
    }
    
}

void SpaceMissionManagementSystem::showMission( const string name ) const
{   
    int missionIndex = indexFindMission(missions, name, missionCount);
    
    if(missionIndex == -1) 
    {
        cout << "Cannot show mission. Mission " << name << " does not exist." << endl;
        return;
    }

    Mission& mission = missions[missionIndex];

    cout << "Mission:" << endl;
    cout << "  Name: " << mission.getName() << endl;
    cout << "  Launch Date: " << mission.getLaunchDate() << endl;
    cout << "  Destination: " << mission.getDestination() << endl;

    if(mission.getSpacecraftCount() > 0) 
    {
        cout << "  Assigned Spacecrafts:" << endl;
        for(int i = 0; i < mission.getSpacecraftCount(); ++i) 
        {
            cout << "  - " << mission.getMissionSpacecrafts()[i].getSpacecraftName() << endl;
        }
    } 
    else 
    {
        cout << "  Assigned Spacecrafts:\n    None" << endl;
    }
}

void SpaceMissionManagementSystem::showSpacecraft( const string name ) const
{
    
    int spacecraftIndex = indexFindSpacecraft(spacecrafts, name, spacecraftCount);

    if(spacecraftIndex == -1)
    {
     
        cout << "Cannot show spacecraft. Spacecraft " << name << " does not exist." << endl;
    }
    else
    {
        cout << "Spacecraft: " << spacecrafts[spacecraftIndex].getSpacecraftName() 
             << ", Type: " << spacecrafts[spacecraftIndex].getSpacecraftType() 
             << ", Status: " << spacecrafts[spacecraftIndex].getSpacecraftStatus() << endl;
    }
}

void SpaceMissionManagementSystem::incrementMissionCount()
{
    missionCount++;
}

void SpaceMissionManagementSystem::decrementMissionsCount()
{
    missionCount--;
}

int SpaceMissionManagementSystem::getMissionCount() const
{
    return missionCount;
}

Mission* SpaceMissionManagementSystem::getMissionArray() const
{
    return missions;
}

bool SpaceMissionManagementSystem::missionExist(Mission* missionArray, string name, int count)
{
    for(int i = 0; i < count ; i++)
    {
        if(missionArray[i].getName() == name)
        {
            return true;
        }
    }
    return false;
}

int SpaceMissionManagementSystem::indexFindMission(Mission* missionArray, string name, int count) const
{
    for(int i = 0; i < count; i++)
    {
        if(missionArray[i].getName() == name)
        {
            return i;
        }
    }
    return -1;
}

void SpaceMissionManagementSystem::incrementSpacecraftCount()
{
    spacecraftCount++;
}

void SpaceMissionManagementSystem::decrementSpacecraftCount()
{
    spacecraftCount--;
}

int SpaceMissionManagementSystem::getSpacecraftCount() const
{
    return spacecraftCount;
}

Spacecraft* SpaceMissionManagementSystem::getSpacecraftArray() const
{
    return spacecrafts;
}

bool SpaceMissionManagementSystem::spacecraftExist(Spacecraft* spacecraftArray, string name, int count) 
{
    for(int i = 0; i < count ; i++)
    {
        if(spacecraftArray[i].getSpacecraftName() == name)
        {
            return true;
        }
    }
    return false;
}

int SpaceMissionManagementSystem::indexFindSpacecraft(Spacecraft* spacecraftArray, string name, int count) const
{
    for(int i = 0; i < count; i++)
    {
        if(spacecraftArray[i].getSpacecraftName() == name)
        {
            return i;
        }
    }
    return -1;
}


