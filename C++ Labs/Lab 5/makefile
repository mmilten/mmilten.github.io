StackMain.exe: Palindrome.o StackMain.o
	g++ -std=gnu++11 -o StackMain.exe Palindrome.o StackMain.o
StackMain.o: StackMain.cpp Palindrome.h ArrayStack.h StackInterface.h 
	g++ -std=gnu++11 -ggdb -c StackMain.cpp
Palindrome.o: Palindrome.cpp Palindrome.h ArrayStack.h StackInterface.h
	g++ -std=gnu++11 -ggdb -c Palindrome.cpp
