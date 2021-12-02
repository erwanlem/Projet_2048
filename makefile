graphics: graph.o modele.o graphic_outils.o variante.o
	g++ graph.o modele.o variante.o graphic_outils.o -lSDL2_ttf -lSDL2 -lSDL2main -o graphics
modele.o: modele.cpp
	g++ -c modele.cpp
graphics.o: graph.cpp
	g++ -c graph.cpp
graphic_outils.o: graphic_outils.cpp
	g++ -c graphic_outils.cpp
variante.o: variante.cpp
	g++ -c variante.cpp