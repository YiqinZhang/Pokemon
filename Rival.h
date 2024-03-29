//
// Created by Garfield on 2019-11-18.
//

#ifndef PA44_RIVAL_H
#define PA44_RIVAL_H
#include "GameObject.h"
#include "BattleArena.h"
#include "Point2D.h"
#include "Vector2D.h"
#include <string>


enum RivalStates {
    ALIVE_RIVAL = 0,
    FAINTED_RIVAL = 1
};

class Rival: public GameObject
{
protected:
    double speed;
    double health;
    double physical_damage;
    double magical_damage;
    double defense;
    double stamina_cost_per_fight;
    bool is_in_arena;
    BattleArena* current_arena;
    string name;

public:
    Rival();
    Rival(string name, double speed, double hp, double phys_dmg,double
    magic_dmg, double def, int id, Point2D in_loc);
    void TakeHit(double physical_damage, double magical_damage, double defense);
    bool IsAlive();
    double get_phys_dmg();
    double get_magic_dmg();
    double get_defense();
    double get_health();
    bool Update() ;
    bool ShouldBeVisible();
    void ShowStatus();
    ~Rival();
};
#endif //PA44_RIVAL_H
