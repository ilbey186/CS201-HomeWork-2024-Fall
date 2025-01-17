//Mehmet İlbey Angur - Section 2 - 22303555

#ifndef SPACECRAFT_H
#define SPACECRAFT_H

#include <string>

using namespace std;

class Spacecraft
{
public:
    Spacecraft(string,string);
    Spacecraft();
    ~Spacecraft();
    string getSpacecraftName() const;
    string getSpacecraftType() const ;
    string getSpacecraftStatus() const;
    string getSpacecraftCurrentMission() const;
    void setSpacecraftStatus(const string);
    void setSpacecraftCurrentMission(const string);
    
private:
    string spacecraftName;
    string spacecraftType;
    string spacecraftStatus = "Available";
    string spacecraftCurrentMission;
    
};

#endif //SPACECRAFT_H