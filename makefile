graphics: graph.o modele.o
	g++ graph.o modele.o -lSDL2_ttf -lSDL2 -lSDL2main -o graphics
modele.o: modele.cpp
	g++ -c modele.cpp
graphics.o: graph.cpp
	g++ -c graph.cpp