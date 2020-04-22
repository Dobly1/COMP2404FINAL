main : Main.cc Array.h random.o Character.o Fighter.o Player.o Game.o Dragon.o Porc.o Borc.o Dorc.o playerLogger.o View.o PathFinding.o Seeker.o Miner.o Snarer.o
	g++ -g -o main Main.cc random.o Character.o Fighter.o Player.o Game.o Dragon.o Porc.o Borc.o Dorc.o playerLogger.o View.o PathFinding.o Seeker.o Miner.o Snarer.o

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
	g++ -g -c Game.cc

Borc.o : Borc.cc Borc.h Fighter.cc Fighter.h Character.cc Character.h
	g++ -c Borc.cc

Dorc.o : Dorc.cc Dorc.h Fighter.cc Fighter.h Character.cc Character.h
	g++ -c Dorc.cc

Porc.o : Porc.cc Porc.h Fighter.cc Fighter.h Character.cc Character.h
	g++ -c Porc.cc

playerLogger.o : playerLogger.cc playerLogger.h LList.h
	g++ -c playerLogger.cc

View.o : View.cc View.h
	g++ -c View.cc

PathFinding.o : PathFinding.cc PathFinding.h
	g++ -c PathFinding.cc

Seeker.o : Seeker.cc Seeker.h Character.cc Character.h
	g++ -c Seeker.cc

Miner.o : Miner.cc Miner.h Seeker.cc Seeker.h Character.cc Character.h
	g++ -c Miner.cc

Snarer.o : Snarer.cc Snarer.h Seeker.cc Seeker.h Character.cc Character.h
	g++ -c Snarer.cc

clean : 
	rm *.o main
