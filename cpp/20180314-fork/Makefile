SRC := $(wildcard *.cpp)
OBJ := main.o
BIN := main
RM := rm -f

CXX = g++
CXXFLAGS = --std=c++1z -Wall -Wextra

.PHONY : all clean

all : $(BIN)

$(BIN) : $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJ) : $(SRC)
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean :
	$(RM) $(OBJ) $(BIN)
