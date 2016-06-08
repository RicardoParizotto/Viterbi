BIN_DIR=bin/
SRC_DIR=src/
FLAGS=-Wall -pedantic -O2 -std=c++11
CPP=g++
all:
	$(CPP) $(SRC_DIR)inicio.cpp $(SRC_DIR)distancia.cpp $(SRC_DIR)main.cpp $(SRC_DIR)viterbi.cpp -o $(BIN_DIR)viterbi $(FLAGS)

clean:
	rm $(BIN_DIR)viterbi
