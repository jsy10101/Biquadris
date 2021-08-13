#include "game.h"

Game::Game(std::string file, int level) :
    id{-1}, b{Board()}, file{file},
    noRandomFile{""}, currBlock{nullptr}, nextBlock{nullptr}, 
    levelPtr{nullptr} {
        if( level <= 0 ) {
            this->level = 0;
        } else if( level >= 4 ) {
            this->level = 4;
        } else {
            this->level = level;
        }
        score = std::make_unique<Score>();
        setLevel(levelPtr);
        genBlock(currBlock, false);
        genBlock(nextBlock, true);
    }

Board& Game::getBoardObject() {
    return b;
}

int Game::getPlayerScore() const {
    return score->getCurrScore();
}

int Game::getHighScore() const {
    return Score::getHighScore();
}

int Game::getLevel() const {
    return level;
}

void Game::setNoRandomFile(std::string noRandomFile) {
    this->noRandomFile = noRandomFile;
    setLevel(levelPtr);  
}

Block* Game::getNextBlock() {
    return nextBlock.get();
}

void Game::setDefCellState() {
    for(int i = 0; i < currBlock->getBlock().size(); ++i) {
       b.getBoard().at(currBlock->getBlock().at(i).getY())
                   .at(currBlock->getBlock().at(i).getX())
                   .setDefault(); 
    }
}

bool Game::isShiftable(int y, int x) {
    for(int i = 0; i < currBlock->getBlock().size(); ++i) {
       if( (currBlock->getBlock().at(i).getX() + x < 0) ||
           (currBlock->getBlock().at(i).getY() + y < 0) ||
           (currBlock->getBlock().at(i).getX() + x >= b.getCol()) ||
           (currBlock->getBlock().at(i).getY() + y >= b.getRow()) ||
           ( (b.getBoard().at(currBlock->getBlock().at(i).getY() + y)
                        .at(currBlock->getBlock().at(i).getX() + x)
                        .getCType() != '.')
             &&
             (b.getBoard().at(currBlock->getBlock().at(i).getY() + y)
                        .at(currBlock->getBlock().at(i).getX() + x)
                        .getCId() != currBlock->getBId()) ) ) {
            return false;
        } 
    }
    return true;
}

void Game::shiftBlock(int y, int x, int nIterations) {
    while( nIterations > 0 ) {
        if( isShiftable(y, x) ) {
            setDefCellState();
            currBlock->updateBlock(y, x);
            b.updateBoard(currBlock);
            if( currBlock->getBLevel() >= 3 ) {
                if( isShiftable(1, 0) ) {
                    setDefCellState();
                    currBlock->updateBlock(1, 0);
                    b.updateBoard(currBlock);
                }
            }
        } else {
            if( currBlock->getBLevel() >= 3 ) {
                if( isShiftable(1, 0) ) {
                    setDefCellState();
                    currBlock->updateBlock(1, 0);
                    b.updateBoard(currBlock);
                }
            }
            break;
        }
        --nIterations;
    }
}

void Game::setLevel(std::unique_ptr<Level>& levelPtr) {
    if( level <= 0 ) {
        levelPtr = std::make_unique<LevZer>(file);
    } else if( level == 1 ) {
        levelPtr = std::make_unique<LevOne>();
    } else if( level == 2 ) {
        levelPtr = std::make_unique<LevTwo>();
    } else if( level == 3 ) {
        levelPtr = std::make_unique<LevThree>(noRandomFile);
    } else if( level >= 4 ) {
        levelPtr = std::make_unique<LevFour>(noRandomFile);
    }  
}

void Game::changePlayerLevel(int levCntr, int nIterations) {
    while( nIterations > 0 ) {
        if( (levCntr + level >= 0) && (levCntr + level <= 4) ) {
            level += levCntr;
        } else {
            break;
        }
        --nIterations;
    }
    setLevel(levelPtr);
}

void Game::genBlock(std::unique_ptr<Block>& blockPtr, bool isNext) {
    if( !isNext && nextBlock ) {
        // move the nextBlock obj ptr to currBlock ptr if nextBlock is not null
        blockPtr = std::move(nextBlock);
    } else {
        // increament the block id
        id = id + 1;
        // create a hash map of blockId and blockSize to keep track of each block
        blockMap.insert( std::pair<int, int>(id, 4) );
        char blockType = levelPtr->blockCreate();
        if( blockType == 'I' ) {
            blockPtr = std::make_unique<Iblock>(id, level);
        } else if( blockType == 'J' ) {
            blockPtr = std::make_unique<Jblock>(id, level);
        } else if( blockType == 'L' ) {
            blockPtr = std::make_unique<Lblock>(id, level);
        } else if( blockType == 'O' ) {
            blockPtr = std::make_unique<Oblock>(id, level);
        } else if( blockType == 'S' ) {
            blockPtr = std::make_unique<Sblock>(id, level);
        } else if( blockType == 'T' ) {
            blockPtr = std::make_unique<Tblock>(id, level);
        } else if( blockType == 'Z' ) {
            blockPtr = std::make_unique<Zblock>(id, level);
        }
    }
    if( !isNext ) {
        b.updateBoard(blockPtr);
    }
}

void Game::dropBlock(int nIterations) {
    const int defaultDropRows = 15 - 1;
    while( nIterations > 0 ) {
        shiftBlock(1, 0, defaultDropRows);
        int bottomRow = 2;
        for(int i = 0; i < currBlock->getBlock().size(); ++i) {
            if( currBlock->getBlock().at(i).getY() > bottomRow ) {
                bottomRow = currBlock->getBlock().at(i).getY();
            }
        }
        deleteRow(bottomRow);
        genBlock(currBlock, false);
        genBlock(nextBlock, true);
        --nIterations;
    }
}

void Game::changeCurrBlock(std::string bType) {
    setDefCellState();
    if( bType == "I" ) {
        currBlock = std::make_unique<Iblock>(id - 1, level);
    } else if( bType == "J" ) {
        currBlock = std::make_unique<Jblock>(id - 1, level);
    } else if( bType == "L" ) {
        currBlock = std::make_unique<Lblock>(id - 1, level);
    } else if( bType == "O" ) {
        currBlock = std::make_unique<Oblock>(id - 1, level);
    } else if( bType == "S" ) {
        currBlock = std::make_unique<Sblock>(id - 1, level);
    } else if( bType == "T" ) {
        currBlock = std::make_unique<Tblock>(id - 1, level);
    } else if( bType == "Z" ) {
        currBlock = std::make_unique<Zblock>(id - 1, level);
    }
    b.updateBoard(currBlock);
} 

void Game::deleteRow(int bottomRow) {
    int i = bottomRow;
    int numRowsCleared = 0;
    bool isRowFull = false;
    // loop condition reason: at max, 4 rows can be deleted
    while( i > bottomRow - 4 ) {
        int j = b.getCol() - 1;
        while( j >= 0 ) {
            if( b.getBoard().at(i).at(j).getCType() == '.' ) {
                isRowFull = false;
                break;
            } else {
                isRowFull = true;
            }
            --j;
        }
        if( isRowFull ) {
            int j = 0;
            while( j < b.getCol() ) {
                int cellId = b.getBoard().at(i).at(j).getCId();
                if( blockMap.at(cellId) == 1 ) {
                    int lev = b.getBoard().at(i).at(j).getCLevel();
                    score->calcBlockScore(lev);
                    auto iter = blockMap.find(cellId);
                    blockMap.erase(iter);
                } else {
                   blockMap.at(cellId) -= 1;
                }
                ++j;
            }
            auto iterRowFull = b.getBoard().begin() + i;
            b.getBoard().erase(iterRowFull);

            std::vector<Cell> defaultRow( b.getCol(), Cell{} );
            auto iterTopRow = b.getBoard().begin();
            b.getBoard().insert( iterTopRow, defaultRow );
            ++numRowsCleared;
            score->calcRowScore(level, numRowsCleared);
        }
        --i;
    }
}

void Game::rotateBlock(int times) {
    
    times = times % 4; // removing extra rotations
    times += 4; // converting negative to positive
    times = times % 4; //removing extra rotations again

    while(times--) {

        int bottomLeftY = 3, bottomLeftX = 11;
        for(auto &b : currBlock->getBlock()) {
            if (b.getX() < bottomLeftX) {
                bottomLeftX = b.getX();
            }
            if (b.getY() > bottomLeftY) {
                bottomLeftY = b.getY();
            }
        }

        for(auto &b: currBlock->getBlock()) {
            b.addPosn(3 - bottomLeftY, 0 - bottomLeftX);
        }

        std::vector<Posn> tempBlock;
        for(auto &b : currBlock->getBlock()) {
            if (b.getY() == 0 && b.getX() == 0) {
                tempBlock.emplace_back(Posn(0,3));
            }
            else if (b.getY() == 0 && b.getX() == 1) {
                tempBlock.emplace_back(Posn(1,3));
            }
            else if (b.getY() == 0 && b.getX() == 2) {
                tempBlock.emplace_back(Posn(2,3));
            }
            else if (b.getY() == 0 && b.getX() == 3) {
                tempBlock.emplace_back(Posn(3,3));
            }
            else if (b.getY() == 1 && b.getX() == 0) {
                tempBlock.emplace_back(Posn(0,2));
            }
            else if (b.getY() == 1 && b.getX() == 1) {
                tempBlock.emplace_back(Posn(1,2));
            }
            else if (b.getY() == 1 && b.getX() == 2) {
                tempBlock.emplace_back(Posn(2,2));
            }
            else if (b.getY() == 1 && b.getX() == 3) {
                tempBlock.emplace_back(Posn(3,2));
            }
            else if (b.getY() == 2 && b.getX() == 0) {
                tempBlock.emplace_back(Posn(0,1));
            }
            else if (b.getY() == 2 && b.getX() == 1) {
                tempBlock.emplace_back(Posn(1,1));
            }
            else if (b.getY() == 2 && b.getX() == 2) {
                tempBlock.emplace_back(Posn(2,1));
            }
            else if (b.getY() == 2 && b.getX() == 3) {
                tempBlock.emplace_back(Posn(3,1));
            }
            else if (b.getY() == 3 && b.getX() == 0) {
                tempBlock.emplace_back(Posn(0,0));
            }
            else if (b.getY() == 3 && b.getX() == 1) {
                tempBlock.emplace_back(Posn(1,0));
            }
            else if (b.getY() == 3 && b.getX() == 2) {
                tempBlock.emplace_back(Posn(2,0));
            }
            else if (b.getY() == 3 && b.getX() == 3) {
                tempBlock.emplace_back(Posn(3,0));
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
        
        for(auto &b: tempBlock) {
            b.addPosn(3 - maxY, -minX);
        }

        for(auto &b: currBlock->getBlock()) {
            b.addPosn(bottomLeftY - 3, bottomLeftX);
        }

        for(auto &b: tempBlock) {
            b.addPosn(bottomLeftY - 3, bottomLeftX);
        }
        
        for(auto s: tempBlock) {
            if(s.getX() < 0 || s.getX() > 10) {
                return;
            }
            bool flag = false;
            for(auto t: currBlock->getBlock()) {
                if (s == t) {
                    flag = true;
                    break;
                } 
            }
            if(flag) {
                continue;
            }
            if(b.getBoard().at( s.getY() ).at( s.getX() ).getCType() != '.' ) {
                return;
            }
        }

        setDefCellState();
        currBlock->getBlock().clear();
        for(auto b : tempBlock) {
            currBlock->getBlock().emplace_back(b);
        }
        b.updateBoard(currBlock);
    }
}