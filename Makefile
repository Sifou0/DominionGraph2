CPP = g++
SFML = -g -lsfml-graphics -lsfml-window -lsfml-system


main: Carte.o CarteVictoire.o CarteRoyaume.o CarteTresor.o CarteReversed.o Deck.o Joueur.o PlateformeGame.o Screen.o Arrow.o Button.o Menu.o Game.o main.o
	$(CPP) -o $@ $^ $(SFML)

%.o : %.cpp
	$(CPP) -o $@ -c $<

clean:
	rm -f *.o *~ *.core