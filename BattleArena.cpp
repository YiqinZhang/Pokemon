//
// Created by Garfield on 2019-11-18.
//

#include "BattleArena.h"


BattleArena::BattleArena()
{
    display_code = 'A';
    pokemon_count = 0;
    max_num_rivals = 3;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    state = RIVALS_AVAILABLE;

    cout << " BattleArena default constructed.\n";
}
BattleArena::BattleArena(unsigned int max_rivals , unsigned int stamina_cost , double dollar_cost , int
in_id , Point2D in_loc ): Building('A',in_id,in_loc)
{
    pokemon_count = 0;
    max_num_rivals = max_rivals;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = dollar_cost;
    stamina_cost_per_fight = stamina_cost;
    state = RIVALS_AVAILABLE;
    cout << "BattleArena constructed.\n";
}

unsigned int BattleArena::GetNumRivalsRemaining()
{
    num_rivals_remaining--;
    return num_rivals_remaining;
}
bool BattleArena::HasEnoughRivals()
{
    if(num_rivals_remaining> 0)
        return true;
    else
        return false;
}
double BattleArena::GetDollarCost()
{
    return dollar_cost_per_fight; //* num_rivals_remaining;
}
unsigned int BattleArena::GetStaminaCost()
{
    return stamina_cost_per_fight; //* num_rivals_remaining;
}

bool BattleArena::IsAbleToFight( double budget, unsigned int stamina)
{
    unsigned int cost_by_stamina = stamina / stamina_cost_per_fight;
    unsigned int cost_by_budget = (int)(budget / dollar_cost_per_fight);
    unsigned int allowable_units = min(cost_by_budget, cost_by_stamina);
    if (allowable_units >0)
        return true;
    else
        return false;
}
bool BattleArena::Update(){
    if ((num_rivals_remaining == 0) && (state = RIVALS_AVAILABLE))
    {
        state = NO_RIVALS_AVAILABLE;
        return true;
    }
    else
        return false;
}

bool BattleArena::IsBeaten(){
    if (num_rivals_remaining == 0)
        return true;
    else
        return false;
}
void BattleArena::ShowStatus()
{
    cout << "Battle Arena Status: ";
    Building::ShowStatus();
    cout << "\tMax number of rivals: " << num_rivals_remaining << endl;
    cout << "\tStamina cost per fight: " << stamina_cost_per_fight << endl;
    cout << "\tPokemon dollar per fight: " <<dollar_cost_per_fight << endl;
    if (num_rivals_remaining <= 1)
        cout << "\t"<< num_rivals_remaining <<" rival is remaining for this arena.\n";
    else
        cout << "\t"<< num_rivals_remaining <<" rivals are remaining for this arena.\n";
}
