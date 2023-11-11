.PHONY: all memcheck clean clear

CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion -Werror -std=c++17

OBJS =  WaTor

all: ${OBJS}

memcheck: clean WaTor
	valgrind --leak-check=summary ./WaTor


MapT.o: MapT.h AnimalT.h 
DolphinT.o: DolphinT.h SharkT.o 
GameT.o: MapT.h GameT.h AnimalT.h 
SharkT.o: SharkT.h FishT.h GameT.o
FishT.o: FishT.h GameT.o
RabbitFishT.o: RabbitFishT.h FishT.o 
 
WaTor: GameT.o MapT.o SharkT.o FishT.o DolphinT.o RabbitFishT.o

clean:
	rm -f ${OBJS} *.o *.gcov *.gcno *.gcda

clear:
	clear
	clear
	make

run:
	make clear
	./WaTor
	
full:
	make clear
	make memcheck
