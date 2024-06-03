all: test_ata

test_ata: test_ata.o tetramini.o board.o
	g++ test_ata.o tetramini.o board.o -o test_ata -lncurses

test_ata.o: test_ata.cpp tetramini.h board.h
	g++ -c test_ata.cpp

tetramini.o: board.h tetramini.h tetramini.cpp 
	g++ -c tetramini.cpp

board.o: tetramini.h board.h board.cpp
	g++ -c board.cpp
