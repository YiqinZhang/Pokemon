//
// Created by Garfield on 2019-11-16.
//

#ifndef PA33_MODEL_H
#define PA33_MODEL_H
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "View.h"
#include <stdlib.h>

class Model
{
private:
    int time;
    GameObject * object_ptrs[10];
    int num_objects;
    Pokemon * pokemon_ptrs[10];
    int num_pokemon;
    PokemonCenter * center_ptrs[10];
    int num_centers;
    PokemonGym* gym_ptrs[10];
    int num_gyms;
    Model(const Model&);

public:
    Model();
    ~Model ();
    Pokemon * GetPokemonPtr( int id);
    PokemonCenter * GetPokemonCenterPtr( int id);
    PokemonGym * GetPokemonGymPtr( int id);
    bool Update();
    void Display( View& view);
    void ShowStatus();
    int GetTime();

};
#endif //PA33_MODEL_H
