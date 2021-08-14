CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD -Werror=vla #-lX11  -L/usr/X11/lib -I/usr/X11/include
DEB = 
EXEC = biquadris
OBJECTS = block.o iblock.o jblock.o lblock.o oblock.o sblock.o tblock.o zblock.o posn.o board.o cell.o level.o levZer.o levOne.o levTwo.o levThree.o levFour.o game.o gameController.o score.o view.o main.o
DEPENDS = ${OBJECTS:.o=.d}
SRC = ${OBJECTS:.o=.cc}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${DEB} ${SRC} -o ${EXEC} 

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

