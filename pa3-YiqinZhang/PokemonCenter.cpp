//
// Created by Garfield on 2019-11-19.
//

#include "PokemonCenter.h"
#include "Building.h"

PokemonCenter::PokemonCenter():Building()
{
    display_code = 'C';
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = 5;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "\t PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc)
        :Building('C',in_id,in_loc)
{
    // and remainder of the member variables to their default initial values.
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_cap;
    dollar_cost_per_stamina_point = stamina_cost;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "\t PokemonCenter constructed" << endl;
}

//public:
bool PokemonCenter::HasStaminaPoints()
{
    if (num_stamina_points_remaining >= 1)
        return true;
    else
        return false;
}
unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
    return num_stamina_points_remaining;
}
bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
    if(stamina_points * dollar_cost_per_stamina_point <= budget)
        return true;
    else
        return false;
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
    return stamina_points* dollar_cost_per_stamina_point;
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
    if (num_stamina_points_remaining >= points_needed)
    {
        num_stamina_points_remaining -= points_needed;
        return points_needed;
    }
    else
    {
        unsigned int temp = num_stamina_points_remaining;
        num_stamina_points_remaining = 0;
        return temp;
    }
}

bool PokemonCenter::Update()
{
    if ((num_stamina_points_remaining == 0) && (state = STAMINA_POINTS_AVAILABLE))
    {
        state = NO_STAMINA_POINTS_AVAILABLE;
        display_code = 'c';
        cout << "\t PokemonCenter " << id_num << " has ran out of stamina points." << endl;
        return true;
    }
    else
        return false;
}

// This function shouldn’t keep returning true if the PokemonCenter has no stamina points remaining.
//It should return true ONLY at the time when the PokemonCenter runs out of stamina points
// return false for later “Update()” function calls.

void PokemonCenter::ShowStatus()
{
    cout << "Pokemon Center Status: ";
    Building::ShowStatus();
    cout << "\t Pokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl;
    cout <<  "\t has "<< num_stamina_points_remaining << " stamina point(s) remaining." << endl;
}