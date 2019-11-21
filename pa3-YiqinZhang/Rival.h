//
// Created by Garfield on 2019-11-18.
//

#ifndef PA44_RIVAL_H
#define PA44_RIVAL_H
#include "GameObject.h"
#include "BattleArena.h"

class Rival: public GameObject
{
protected:
    double health;
    double physical_damage;
    double magical_damage;
    double defense;
    double stamina_cost_per_fight;
    bool is_in_arena;
    BattleArena * current_arena;
public:
    Rival(string name, double speed, double hp, double phys_dmg,double
    magic_dmg, double def, int id, Point2D in_loc) :GameObject('R', id, in_loc));
    void TakeHit(int physical_damage, int magical_damage, int defense);
    double get_phys_dmg();
    double get_magic_dmg();
    double get_defense();
    double get_health();
    bool Update();

};
#endif //PA44_RIVAL_H
