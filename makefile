all: tetramini

tetramini: tetramini.cpp
	g++ tetramini.cpp -o tetramini -lncurses
