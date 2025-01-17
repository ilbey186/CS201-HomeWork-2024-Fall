//Mehmet İlbey Angur - Section 2 - 22303555

#include <string>

#include "Spacecraft.h"

using namespace std;

Spacecraft::Spacecraft(string name, string type)
{
    spacecraftName = name;
    spacecraftType = type;
};
Spacecraft::Spacecraft()
{

};

Spacecraft::~Spacecraft()
{

};

string Spacecraft::getSpacecraftName() const
{
    return spacecraftName;
}

string Spacecraft::getSpacecraftType() const 
{
    return spacecraftType;
}

string Spacecraft::getSpacecraftStatus() const
{
    return spacecraftStatus;
}

string Spacecraft::getSpacecraftCurrentMission() const
{
    return spacecraftCurrentMission;
}

void Spacecraft::setSpacecraftStatus(const string status)
{
    spacecraftStatus = status;
}

void Spacecraft::setSpacecraftCurrentMission(const string mission )
{
    spacecraftCurrentMission = mission;
}