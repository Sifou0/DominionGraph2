CPP = g++
SFML = -g -lsfml-graphics -lsfml-window -lsfml-system


main: Carte.o Joueur.o CarteTresor.o CarteVictoire.o CarteRoyaume.o CarteReversed.o Deck.o Screen.o Arrow.o Button.o Menu.o Game.o LancementJeu.o main.o
	$(CPP) -o $@ $^ $(SFML)

%.o : %.cpp
	$(CPP) -o $@ -c $<

run: main
	./$<
clean:
	rm -f *.o *~ *.core