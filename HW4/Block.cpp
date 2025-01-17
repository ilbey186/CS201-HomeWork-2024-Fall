//Mehmet Ilbey Angur - Section 1 - 22303555

#include "Block.h"
#include <iostream>

using namespace std;



Block::Block(BlockType type, int x, int y)
{
    collumn = x;
    row = y;
    blockType = type;
}

Block::Block()
{
    collumn = -1;
    row = -1;
}

enum class Block::BlockType
{
    EMPTY,
    HEALTHY,
    INFECTED
};

void Block::setBlockType(int type)
{
    switch (type)
    {
        case 0:
            blockType = BlockType::EMPTY;
            break;
        case 1:
            blockType = BlockType::HEALTHY;
            break;
        case 2:
            blockType = BlockType::INFECTED;
            break;
        default:
            cout << "Block type " << type << "is wrong" << endl;
    }
}

void Block::setLocation(int x, int y)
{
    collumn = x;
    row = y;
}

void Block::setDayOfInfection(int x)
{
    dayInfected = x;
}
string Block::getBlockType() const 
{
    switch (blockType) 
    {
        case BlockType::EMPTY:
            return "Empty";
        case BlockType::HEALTHY:
            return "Healthy";
        case BlockType::INFECTED:
            return "Infected";
        default:
            return "Unknown";
    }
}

int Block::getBlockX() const
{
    return collumn;
}

int Block::getBlockY() const
{
    return row;
}