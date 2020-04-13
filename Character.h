#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

class Character
{
    public:
    Character(std::string="Default", int=10, int =10,int=10,int=10,char='x',bool=true);

    Character(std::string, int, int, int, int, int, char, bool);

    //More complex functions
    static void fight(Character*, Character*);
    virtual void move(int, int) = 0;
    void hit(Character*);

    //Getters and Setters
    bool isFightable();
    bool isAlive();
    void getPos(int&,int&);
    char getAvatar();

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
    bool alive;
    int strength;

};



#endif