#include "game.h"

Game::Game(std::string file, int level) : 
    level{level}, id{0}, b{Board()}, file{file},
    currBlock{nullptr}, nextBlock{nullptr}, 
    levelPtr{nullptr} {
        setLevel(levelPtr);
        genBlock(currBlock, false);
        genBlock(nextBlock, true);
    }

Board& Game::getBoardObject() {
    return b;
}

int Game::getLevel() const {
    return level;
}

int Game::getScore() const {
    return score;
}

Block* Game::getNextBlock() {
    return nextBlock.get();
}

void Game::setLevel(std::unique_ptr<Level>& levelPtr) {
    if( level == 0 ) {
        levelPtr = std::make_unique<LevZer>(file);
    } else if( level == 1 ) {
        //levelPtr = std::make_unique<LevZer>(file);
    } else if( level == 2 ) {
        //levelPtr = std::make_unique<LevZer>(file);
    } else if( level == 3 ) {
        //levelPtr = std::make_unique<LevZer>(file);
    } else if( level == 4 ) {
        //levelPtr = std::make_unique<LevZer>(file);
    }  
}

void Game::genBlock(std::unique_ptr<Block>& blockPtr, bool isNext) {
    if( isNext && nextBlock ) {
        // move the nextBlock obj ptr to currBlock ptr
        blockPtr = std::move(nextBlock);
    } else {
        char blockType = levelPtr->blockCreate();
        if( blockType == 'I' ) {
            blockPtr = std::make_unique<Iblock>(id);
        } else if( blockType == 'J' ) {
            blockPtr = std::make_unique<Jblock>(id);;
        } else if( blockType == 'L' ) {
            blockPtr = std::make_unique<Lblock>(id);
        } else if( blockType == 'O' ) {
            blockPtr = std::make_unique<Oblock>(id);
        } else if( blockType == 'S' ) {
            blockPtr = std::make_unique<Sblock>(id);
        } else if( blockType == 'T' ) {
            blockPtr = std::make_unique<Tblock>(id);
        } else if( blockType == 'Z' ) {
            blockPtr = std::make_unique<Zblock>(id);
        }
    }
    if( !isNext ) {
        b.updateBoard(blockPtr);
    }
}