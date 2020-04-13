main : Main.cc Array.h random.o Character.o Fighter.o Player.o
	g++ -o main Main.cc random.o Character.o Fighter.o Player.o

random.o : random.h random.cc
	g++ -c random.cc

Character.o : Character.cc Character.h
	g++ -c Character.cc

Fighter.o : Fighter.cc Fighter.h Character.cc Character.h
	g++ -c Fighter.cc

Player.o : Player.cc Player.h Character.cc Character.h
	g++ -c Player.cc

clean : 
	rm *.o main
