2048_IA: 2048_IA.o modeleIA.o 
	g++ 2048_IA.o modeleIA.o -o 2048IA
2048_IA.o: 2048_IA.cpp
	g++ -c 2048_IA.cpp
modeleIA.o: modeleIA.cpp
	g++ -c modeleIA.cpp
