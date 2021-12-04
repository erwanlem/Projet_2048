2048: 2048.o modele.o 
	g++ 2048.o modele.o -lncurses -o 2048
2048.o: 2048.cpp
	g++ -c 2048.cpp
modele.o: modele.cpp
	g++ -c modele.cpp