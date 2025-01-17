#include <iostream>
#include <string>
#include "SpaceMissionManagementSystem.h"

int main() {
    SpaceMissionManagementSystem system;

    const int numMissions = 1000;
    const int numSpacecrafts = 500;

    // Step 1: Allocate missions and spacecrafts
    for (int i = 0; i < numMissions; i++) {
        system.addMission("Mission" + std::to_string(i), "2024-01-" + std::to_string(i % 30 + 1), "Destination" + std::to_string(i % 10));
    }

    for (int i = 0; i < numSpacecrafts; i++) {
        system.addSpacecraft("Spacecraft" + std::to_string(i), "Type" + std::to_string(i % 5));
    }

    // Step 2: Assign spacecrafts to missions
    for (int i = 0; i < numMissions && i < numSpacecrafts; i++) {
        system.assignSpacecraftToMission("Spacecraft" + std::to_string(i), "Mission" + std::to_string(i));
    }

    // Step 3: Remove some missions
    for (int i = 0; i < numMissions; i += 10) {
        system.removeMission("Mission" + std::to_string(i));
    }

    // Step 4: Drop spacecrafts from remaining missions
    for (int i = 0; i < numSpacecrafts; i += 5) {
        system.dropSpacecraftFromMission("Spacecraft" + std::to_string(i));
    }

    // Step 5: Add more missions and spacecrafts
    for (int i = numMissions; i < numMissions + 500; i++) {
        system.addMission("NewMission" + std::to_string(i), "2024-02-01", "NewDestination" + std::to_string(i % 10));
    }

    for (int i = numSpacecrafts; i < numSpacecrafts + 250; i++) {
        system.addSpacecraft("NewSpacecraft" + std::to_string(i), "NewType" + std::to_string(i % 5));
    }

    // Step 6: Assign new spacecrafts to new missions
    for (int i = numMissions; i < numMissions + 500 && i < numSpacecrafts + 250; i++) {
        system.assignSpacecraftToMission("NewSpacecraft" + std::to_string(i), "NewMission" + std::to_string(i));
    }

    // Step 7: Remove half of the new missions
    for (int i = numMissions; i < numMissions + 500; i += 2) {
        system.removeMission("NewMission" + std::to_string(i));
    }

    // Step 8: Drop remaining spacecrafts from any missions
    for (int i = 0; i < numSpacecrafts + 250; i++) {
        system.dropSpacecraftFromMission("NewSpacecraft" + std::to_string(i));
    }

    return 0;
}
