# This is the makefile for Client usng MonthDays
Client.exe: Client.o MonthDays.o
	g++ -std=gnu++11 -o Client.exe MonthDays.o Client.o
Client.o: Client.cpp MonthDays.cpp Monthdays.h
	g++ -std=gnu++11 -g -c Client.cpp
MonthDays.o: MonthDays.cpp MonthDays.h
	g++ -std=gnu++11 -g -c MonthDays.cpp