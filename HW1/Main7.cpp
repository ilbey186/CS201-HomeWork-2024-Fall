#include <iostream>
#include <string>
#include "SpaceMissionManagementSystem.h"

int main() {
    SpaceMissionManagementSystem system;

    const int numAllocations = 1000;

    // Step 1: Allocate a million missions and spacecrafts
    for (int i = 0; i < numAllocations; i++) {
        system.addMission("Mission" + std::to_string(i), "2024-01-01", "Destination");
        system.addSpacecraft("Spacecraft" + std::to_string(i), "TypeA");
    }

    // Step 2: Delete half of the missions
    for (int i = 0; i < numAllocations / 2; i++) {
        system.removeMission("Mission" + std::to_string(i));
    }

    // Step 3: Drop spacecrafts from the remaining missions
    for (int i = numAllocations / 2; i < numAllocations; i++) {
        system.dropSpacecraftFromMission("Spacecraft" + std::to_string(i));
    }

    // Step 4: Delete some spacecrafts
    for (int i = numAllocations / 3; i < (2 * numAllocations) / 3; i++) {
        system.removeSpacecraft("Spacecraft" + std::to_string(i));
    }

    return 0;
}
