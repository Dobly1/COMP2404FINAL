main : Main2.cc Array.h random.o Character.o Fighter.o Player.o Game.o Dragon.o Porc.o Borc.o Dorc.o playerLogger.o View.o
	g++ -o main Main2.cc random.o Character.o Fighter.o Player.o Game.o Dragon.o Porc.o Borc.o Dorc.o playerLogger.o View.o

random.o : random.h random.cc
	g++ -c random.cc

Character.o : Character.cc Character.h
	g++ -c Character.cc

Fighter.o : Fighter.cc Fighter.h Character.cc Character.h
	g++ -c Fighter.cc

Player.o : Player.cc Player.h Character.cc Character.h
	g++ -c Player.cc

Dragon.o : Dragon.cc Dragon.h Character.cc Character.h
	g++ -c Dragon.cc

Game.o : Game.cc Game.h
	g++ -c Game.cc

Borc.o : Borc.cc Borc.h Fighter.cc Fighter.h Character.cc Character.h
	g++ -c Borc.cc

Dorc.o : Dorc.cc Dorc.h Fighter.cc Fighter.h Character.cc Character.h
	g++ -c Dorc.cc

Porc.o : Porc.cc Porc.h Fighter.cc Fighter.h Character.cc Character.h
	g++ -c Porc.cc

playerLogger.o : playerLogger.cc playerLogger.h
	g++ -c playerLogger.cc

View.o : View.cc View.h
	g++ -c View.cc

clean : 
	rm *.o main
