#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;

/*
Class: Character
Author: Callum M

Purpose:
    -Character provides a template as to what a character is in the reference of the game
    -It provides all the neccesary stats and attributes to define what a character is and manipulate them in the game
    -As well it is an abstract class at the move function is pure virtual

Data Members:
    -std::string name
        -The name of the player, not currently used, but I kept it incase I wanted to print out their names when they battled or something
    -int health
        -The health of a player in integer value
    -int armour 
        -The armour value of a player represented as an int
    -char avatar
        -The char that represents how a character is displayed on the board
    -bool fightAble
        -A boolean that represents whether or not a character can be fought by a player - for this progam our heroes are not fightable, while monsters are
    -int xPos
        -An integer that holds the current X position of a player in the game
    -int yPos
        -An integer that holds the current Y position of a player in the game
    -bool alive
        -A boolean that is used to determine whether a character is still alive,
    -int strength
        -A integer that holds the strength of a character
    -bool snared
        -A bool representing whether a player is snared or not, importnat for one of the monster types that can slow players down

Member Functions:
    -Character(string, int, int, int, int, char, bool)
        -A constructor used to create a character with little information provided, allowing derived classes to handle much of that on their own
         also generates a random Y position to be spawned at
    -Character(string, int, int, int, int, int, char, bool)
        -A constructor to provide ease of creating character with all information provided directly, also generates a random y position to be spawned a
    -static void fight(Character*, Character*)
        -A static function that allows to characters to fight, it's static so it work regardless of what the character is, it doesn't need to know
         anything about who's fighting
    -virtual void move(int, int)
        -The "polymorphic" function that the game requires to move characters, each class derviced from Character has to implement it to define movement
         behaviour
    -virtual void hit(Character*)
        -A function to simulate one character attacking another, it has an implementation, but one kind of monster has a different behaviour, so it's
         virtual so it can be overriden
    -bool isFightable()
        -A getter to return whether or not a character is fightable
    -bool isAlive()
        -A getter to return whether or not a character is alive
    -void getPos(int&,int&)
        -Returns two ints as output parameters, representing the X and Y coordinate of a character so collisions and drawing can be handled by other classes
    -char getAvatar()
        -A getter to return a characters avatar, allowing them to be drawn onto the game grid by other classes
    -void kill()
        -Called when a character is killed, and preforms all the appropiate setting changes to ensure that the character is out of play
    -void snare()
        -"Snares" a player, used by one of the monsters as an alternate to doing damage

*/

class Character
{
    public:
        //Constructors
        Character(std::string="Default", int=10, int =10,int=10,int=10,char='x',bool=true);
        Character(std::string, int, int, int, int, int, char, bool);
        virtual ~Character();
        //More complex functions
        static void fight(Character*, Character*);
        virtual void move(int, int) = 0;
        virtual void hit(Character*);

        //Getters and Setters
        bool isFightable();
        bool isAlive();
        void getPos(int&,int&);
        char getAvatar();

        //Fighting behaviour
        void kill();
        void snare();

    private:
        //Personal Info
        std::string name;

        //Stats
        int health;
        int armour;
        

        //Avatar
        char avatar;

        //Extra Information
        bool fightAble;
        

        protected:
        //Position Information
        int xPos;
        int yPos;

        //Attrivutes that derived classes need to access
        bool alive;
        int strength;
        bool snared;

};



#endif