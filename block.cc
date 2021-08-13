#include "block.h"

Block::Block(char bType, int id, std::vector<Posn> block, int level) :
    bType{bType}, bId{id}, block{block}, bLevelGen{level}
    {}

char Block::getBType() const {
    return bType;
}

int Block::getBId() const {
    return bId;
}

std::vector<Posn>& Block::getBlock() {
    return block;
}

int Block::getBLevel() const {
    return bLevelGen;
}

void Block::updateBlock(int y, int x) {
    for(int i = 0; i < block.size(); ++i) {
        block.at(i).addPosn(y, x);
    }
}

void Block::rotateBlock(int times) {
    times = times % 4; // removing extra rotations
    times += 4; // converting negative to positive
    times = times % 4; //removing extra rotations again

    while(times--) {

        std::vector<Posn> tempBlock;
        for(auto b : block) {
            if (b.getY() == 0 && b.getX() == 0) {
                Posn p(3,0);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 0 && b.getX() == 1) {
                Posn p(2,0);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 0 && b.getX() == 2) {
                Posn p(1,0);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 0 && b.getX() == 3) {
                Posn p(0,0);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 1 && b.getX() == 0) {
                Posn p(3,1);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 1 && b.getX() == 1) {
                Posn p(2,1);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 1 && b.getX() == 2) {
                Posn p(1,1);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 1 && b.getX() == 3) {
                Posn p(0,1);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 2 && b.getX() == 0) {
                Posn p(3,2);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 2 && b.getX() == 1) {
                Posn p(2,2);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 2 && b.getX() == 2) {
                Posn p(1,2);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 2 && b.getX() == 3) {
                Posn p(0,2);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 3 && b.getX() == 0) {
                Posn p(3,3);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 3 && b.getX() == 1) {
                Posn p(2,3);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 3 && b.getX() == 2) {
                Posn p(1,3);
                tempBlock.emplace_back(p);
            }
            else if (b.getY() == 3 && b.getX() == 3) {
                Posn p(0,3);
                tempBlock.emplace_back(p);
            }
        }

        int maxY = 0, minX = 3;
        for(auto b : tempBlock) {
            if (b.getX() < minX) {
                minX = b.getX();
            }
            if (b.getY() > maxY) {
                maxY = b.getY();
            }
        }
        maxY = 3 - maxY;
        minX = -minX;
        for(auto b: tempBlock) {
            b.addPosn(maxY, minX);
        }
        block.clear();
        for(auto b : tempBlock) {
            block.emplace_back(b);
        }
    }
}

