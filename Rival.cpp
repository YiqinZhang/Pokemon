//
// Created by Garfield on 2019-11-18.
//

#include "Rival.h"
#include <iostream>


Rival::Rival(){
    this->name = "Rival";
    this->speed = 5.0;
    health=20;
    physical_damage=5;
    magical_damage =4;
    state = ALIVE_RIVAL;
    defense= 15;
    cout << "Rival default constructed. " << endl;
}


Rival::Rival(string name, double speed, double hp, double phys_dmg,double
        magic_dmg, double def, int id, Point2D in_loc):GameObject('R', id, in_loc){

    this->name = name;
    this->speed = speed;
    health = hp;
    physical_damage = phys_dmg;
    magical_damage = magic_dmg;
    defense = def;
    state = ALIVE_RIVAL;
    defense= def;
    cout << "Rival constructed. " << endl;
}



void Rival::TakeHit(double physical_damage, double magical_damage, double defense){
    double damage = 0.0;
    if (rand()%2)
    {
        damage = (100.0 - defense)/ 100 * physical_damage;
        cout <<"Aaagh, no physical pain no gain!\n";
    }
    else
    {
        cout <<"Ouch, I don't believe magic!\n";
        damage = (100.0 - defense)/ 100 * magical_damage;
    }
    health -= damage;
    cout<< "Damage: "<< damage << endl;
    cout<< "Health: "<< health << endl;
    cout<< "*******\n";
}

double Rival::get_phys_dmg(){
    return physical_damage;
}

double Rival::get_magic_dmg()
{
    return physical_damage;
}
double Rival::get_defense()
{
    return defense;
}
double Rival::get_health()
{
    return health;
}
bool Rival::Update()
{
if ((health <=0) && ( state == ALIVE_RIVAL)){
    state = FAINTED_RIVAL;
    return true;
}
else
    return false;
}
void Rival::ShowStatus(){
    cout << name << " status: ";
    GameObject::ShowStatus();
    cout << "\n\tHealth: " << health << endl;
    cout << "\tPhysical Damage: " << physical_damage << endl;
    cout << "\tMagical Damage: " << magical_damage << endl;
    cout << "\tDefense: " << defense << endl;
    if (IsAlive())
        cout << "\tRival is alive.\n ";
    else
        cout << "\tRival is not alive.\n ";
}

bool Rival::IsAlive() {
    if (state == ALIVE_RIVAL)
        return true;
    else
        return false;
}

bool Rival::ShouldBeVisible() {
    return IsAlive();
}

Rival::~Rival() {
    cout << "Rival destructed. " << endl;
}