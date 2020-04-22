#include "Character.h"
#include "random.h" 

//Default Constructor, allows stats to be specialized
Character::Character(std::string n, int a, int h,int x, int y,char av, bool f):
name(n), avatar(av), fightAble(f), xPos(x), alive(true), health(h), snared(false)
{    
    int newY = random(y);
    yPos = newY;
}

//Allows me to give more information about a character
Character::Character(std::string n, int s, int a, int h, int x, int y,char av, bool f):
name(n),strength(s),armour(a),health(h),avatar(av),fightAble(f),xPos(x),alive(true), snared(false)
{
    int newY = random(y);
    yPos = newY;
}

Character::~Character()
{
    
}


void Character::fight(Character* c1, Character* c2)
{
    //Make sure there's exactly 1 fightable entity and 1 non-fightable entity (Monsters are fightable)
    if(c1->isFightable() && c2->isFightable() || !c1->isFightable() && !c2->isFightable())
        return;

    c1->hit(c2);
    c2->hit(c1);   
}

void Character::hit(Character* c1)
{
    int dmg = strength - c1->armour;

    //Make sure you can't do negative damage
    c1->health -= (dmg>=0) ? dmg : 0;

    //Set the Health at 0 if they're dead
    c1->health = (c1->health <= 0) ? 0 : c1->health;

    if(c1->health <= 0)
        c1->kill();

}

bool Character::isAlive()
{
    return alive;
}


bool Character::isFightable()
{
    return fightAble;
}

void Character::getPos(int& x, int& y)
{
    x = xPos;
    y = yPos;
}

char Character::getAvatar()
{
    return avatar;
}

void Character::kill()
{
    alive = false;
    avatar = '+';
}

void Character::snare()
{
    snared = true;
}