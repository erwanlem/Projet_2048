graphics: graph.o modele.o graphic_outils.o
	g++ graph.o modele.o graphic_outils.o -lSDL2_ttf -lSDL2 -lSDL2main -o graphics
modele.o: modele.cpp
	g++ -c modele.cpp
graphics.o: graph.cpp
	g++ -c graph.cpp
graphic_outils.o: graphic_outils.cpp
	g++ -c graphic_outils.cpp