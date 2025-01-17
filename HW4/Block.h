//Mehmet Ilbey Angur - Section 1 - 22303555

#ifndef BLOCK
#define BLOCK

#include <string>
using namespace std;

class Block
{
public:
    enum class BlockType;
    
    Block(BlockType type, int x, int y);
    Block();

    void setBlockType(int type);

    void setLocation(int x, int y);

    void setDayOfInfection(int x);

    string getBlockType() const;

    int getTheDayOfInfection();

    int getBlockX() const;

    int getBlockY() const;
private:
    BlockType blockType;
    int dayInfected = -1;
    int row;
    int collumn;
};

#endif //BLOCK