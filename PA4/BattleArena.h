//
// Created by Garfield on 2019-11-18.
//

#ifndef PA44_BATTLEARENA_H
#define PA44_BATTLEARENA_H
#include "GameObject.h"
#include "Building.h"


enum BattleArenaStates {
    RIVALS_AVAILABLE = 0,
    NO_RIVALS_AVAILABLE = 1
};

class BattleArena : public Building
{
private:
    unsigned int max_num_rivals;
    double dollar_cost_per_fight;
    unsigned int stamina_cost_per_fight;
    unsigned int pokemon_count;

public:
    BattleArena();
    BattleArena(unsigned int max_rivals , unsigned int stamina_cost , double dollar_cost ,
                int in_Id , Point2D in_loc );
    unsigned int num_rivals_remaining;
    unsigned int GetNumRivalsRemaining();
    bool HasEnoughRivals();
    double GetDollarCost();
    unsigned int GetStaminaCost();
    bool IsAbleToFight( double budget, unsigned int stamina);
//    unsigned int GetMaxAllowablefigntUnits(double budget, unsigned int stamina);
    bool Update();
    bool IsBeaten();
    void ShowStatus();
};


#endif //PA44_BATTLEARENA_H
