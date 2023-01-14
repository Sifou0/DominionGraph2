CPP = g++
SFML = -g -lsfml-graphics -lsfml-window -lsfml-system


main: main.o Game.o Card.o
	$(CPP) -o $@ $^ $(SFML)

%.o : %.cpp
	$(CPP) -o $@ -c $< 