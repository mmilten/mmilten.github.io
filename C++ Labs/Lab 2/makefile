# makefile for Client using IntArray
Client.exe: Client.o IntArray.o
	g++ -std=gnu++11 -o Client.exe IntArray.o Client.o
Client.o: Client.cpp IntArray.cpp IntArray.h
	g++ -std=gnu++11 -g -c Client.cpp
IntArray.o: IntArray.cpp IntArray.h
	g++ -std=gnu++11 -g -c IntArray.cpp

	
	
	