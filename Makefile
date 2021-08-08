CXX = g++
CXXFLAGS = -std=c++14 -Wall -g -MMD -Werror=vla #-lX11  -L/usr/X11/lib -I/usr/X11/include
EXEC = a.out
# ######################################
# remove ` maintest.o ` later
# ######################################
OBJECTS = block.o iblock.o jblock.o lblock.o oblock.o sblock.o tblock.o zblock.o posn.o maintest.o
DEPENDS = ${OBJECTS:.o=.d}
SRC = ${OBJECTS:.o=.cc}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${SRC} -o ${EXEC} 

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
.PHONY: clean

