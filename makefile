2048: 2048.o modele.o ncurses_min.o
	g++ 2048.o modele.o ncurses_min.o -lncurses -o 2048
2048.o: 2048.cpp modele.h
	g++ -c 2048.cpp
modele.o: modele.cpp modele.h
	g++ -c modele.cpp
ncurses_min.o: ncurses_min.cpp modele.h
	g++ -c ncurses_min.cpp