
CC=gcc
CXX=g++

CFLAGS	=   -g -std=c++11

RM=rm

OBJS =	Part1.o Part2.o Part3.o PromptUtils.o

EXES =	Part1.exe Part2.exe Part3.exe

all:	$(EXES)

Part1.exe: Part1.o
	$(CXX) $(CFLAGS) -o $@ $^

Part2.exe: Part2.o
	$(CXX) -g -std=c++11 -o $@ $^	
	
Part3.exe: Part3.o PromptUtils.o
	$(CXX) $(CFLAGS) -o $@ $^	

	
%.o:	%.cpp %.h
	$(CXX) -c $(CFLAGS) $< -o $@
	
clean:
	rm *.exe *.o
