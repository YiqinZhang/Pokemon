//
// Created by Garfield on 2019-11-08.
//
#ifndef PA33_POKEMONGYM_H
#define PA33_POKEMONGYM_H
#include "Point2D.h"
#include "Building.h"
class PokemonGym:public Building
{
    enum PokemonGymStates{
        NOT_BEATEN = 0,
        BEATEN = 1
    };

private:
    unsigned int num_training_units_remaining;
    unsigned int max_number_of_training_units;
    unsigned int stamina_cost_per_training_unit;
    double dollar_cost_per_training_unit;
    unsigned int experience_points_per_training_unit;
public:
    PokemonGym();
    PokemonGym( unsigned int max_training_units, unsigned int stamina_cost,
            double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc);

    double GetDollarCost( unsigned int unit_qty);
    unsigned int GetStaminaCost( unsigned int unit_qty);
    unsigned int GetNumTrainingUnitsRemaining();
    bool IsAbleToTrain( unsigned int unit_qty, double budget, unsigned int stamina);
    unsigned int TrainPokemon( unsigned int training_units);
    bool Update();
    bool IsBeaten();
    void ShowStatus();
    ~PokemonGym();
};

#endif //PA33_POKEMONGYM_H
