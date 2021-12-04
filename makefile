2048: main.o modele.o graphic_outils.o variante.o windows.o
	g++ main.o modele.o windows.o variante.o graphic_outils.o -lSDL2_ttf -lSDL2 -lSDL2main -o 2048
modele.o: modele.cpp
	g++ -c modele.cpp
main.o: main.cpp
	g++ -c main.cpp
graphic_outils.o: graphic_outils.cpp
	g++ -c graphic_outils.cpp
variante.o: variante.cpp
	g++ -c variante.cpp
windows.o: windows.cpp
	g++ -c windows.cpp