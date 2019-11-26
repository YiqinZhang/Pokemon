//
// Created by Garfield on 2019-11-08.
//
#include "PokemonGym.h"
#include "PokemonGym.h"

PokemonGym::PokemonGym()
{
    display_code = 'G';
    state = NOT_BEATEN;
    max_number_of_training_units = 10;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = 1;
    dollar_cost_per_training_unit = 1.0;
    experience_points_per_training_unit = 2;
    cout << "\t PokemonGym default constructed" << endl;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost,
                       double dollar_cost, unsigned int exp_points_per_unit,
                       int in_id, Point2D in_loc):Building(' ', in_id, in_loc)
{
    display_code = 'G';
    state = NOT_BEATEN;
    max_number_of_training_units = max_training_units;
    stamina_cost_per_training_unit = stamina_cost;
    dollar_cost_per_training_unit = dollar_cost;
    experience_points_per_training_unit = exp_points_per_unit;
    num_training_units_remaining = max_number_of_training_units;
    cout << "\t PokemonGym constructed" << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
    return unit_qty * dollar_cost_per_training_unit;
}

unsigned int PokemonGym::GetStaminaCost( unsigned int unit_qty)
{
    return unit_qty * stamina_cost_per_training_unit;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
    return num_training_units_remaining;
}

bool PokemonGym::IsAbleToTrain( unsigned int unit_qty, double budget, unsigned int stamina)
{
    if((unit_qty * dollar_cost_per_training_unit <= budget) &&
       (unit_qty * stamina_cost_per_training_unit <= stamina))
//    if((GetStaminaCost(unit_qty)<=stamina) && (GetDollarCost(unit_qty) <= budget))
        return true;
    else
        return false;
}

unsigned int PokemonGym::TrainPokemon( unsigned int training_units)
{

    if (num_training_units_remaining >= training_units)
    {
        num_training_units_remaining -= training_units;
        return training_units * experience_points_per_training_unit;
    }
    else
    {
        return num_training_units_remaining * experience_points_per_training_unit;
    }
}

bool PokemonGym::Update()
{
    if ((num_training_units_remaining ==0) && (state = NOT_BEATEN))
    {
        state = BEATEN;
        display_code = 'g';
        cout<< "\t"<< display_code<< " " << id_num <<  " has been beaten. " << endl;
        return true;
    }
    else if (num_training_units_remaining > 0)
        return false;
    else
        return false;
}

bool PokemonGym::IsBeaten()
{
    if (num_training_units_remaining ==0)
        return true;
    else
        return false;
}

void PokemonGym::ShowStatus()
{
    cout << "Pokemon Gym Status: ";
    GameObject::ShowStatus();
    Building::ShowStatus();
    cout << "\t Max number of training units: " << max_number_of_training_units << endl;
    cout << "\t Stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
    cout << "\t Pokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
    cout << "\t Experience points per training unit: " << experience_points_per_training_unit << endl;
    cout << "\t "<< num_training_units_remaining << " training unit(s) are remaining for this gym \n";
}
PokemonGym::~PokemonGym()
{
    cout << "\t PokemonGym destructed." << endl;
}