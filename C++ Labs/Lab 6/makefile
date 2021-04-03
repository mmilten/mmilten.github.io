QueueMain.exe: PrecondViolatedExcep.o QueueMain.o 
	g++ -std=gnu++11 -o QueueMain.exe PrecondViolatedExcep.o QueueMain.o
QueueMain.o: QueueMain.cpp QueueInterface.h Node.h LinkedQueue.h PrecondViolatedExcep.h
	g++ -std=gnu++11 -ggdb -c QueueMain.cpp
PrecondViolatedExcep.o: PrecondViolatedExcep.cpp PrecondViolatedExcep.h
	g++ -std=gnu++11 -ggdb -c PrecondViolatedExcep.cpp