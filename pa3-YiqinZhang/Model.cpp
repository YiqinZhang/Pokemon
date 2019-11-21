//
// Created by Garfield on 2019-11-17.
//
#include "Model.h"
#include "GameObject.h"


Model::Model()
{
    time = 0;


    pokemon_ptrs[0] = new Pokemon("Pokemon1", 1, 'P', 5, Point2D(5,1));
    object_ptrs[0] = pokemon_ptrs[0];

//   object_ptrs[0] = new GameObject('G');
//   Pokemon::
//
//
//    pokemon_ptrs[0]=  new Pokemon("Pokemon1", 1, 'P', 5, (5,1));
//    //Pokemon("Pokemon1", 1, 'P', 5, (5,1));
//
//
//
//
//    //object_ptrs[0] = new Pokemon("Pokemon1", 1, 'P', 5, (5,1));
//    //pokemon_ptrs[0] = Pokemon("Pokemon1", 1, 'P', 5, (5,1));
//
//    pokemon_ptrs[1] = new Pokemon;
//    Pokemon Pokemon2("Pokemon2", 2, 'P', 5, (10.0,1.0));
//
//
//    PokemonCenter* PokemonCenter1 = new PokemonCenter();
//    PokemonCenter* PokemonCenter2 = new PokemonCenter();
//    PokemonCenter(2, 5, 100, (10,20));
//
//    PokemonGym* gym_ptrs = new PokemonGym[2];
//
//    PokemonGym PokemonGym1();
//    gym_ptrs[0] = PokemonGym1;
//    object_ptrs[4] = &gym_ptrs[0];
//
//    PokemonGym PokemonGym2(unsigned int max_training_units, unsigned int stamina_cost,
//    double dollar_cost, unsigned int exp_points_per_unit, 2, (5,5));
//    gym_ptrs[0] = PokemonGym2();
//    object_ptrs[4] = &gym_ptrs[0];
//    gym_ptrs[1] = PokemonGym2();
//    object_ptrs[5] = &gym_ptrs[1];
//    PokemonGym* PokemonGym1 = new PokemonGym;
//    PokemonGym::PokemonGym();
//    PokemonGym();
//
//    PokemonGym* PokemonGym2 = new PokemonGym;
//    GetPokemonGymPtr( int id)


    num_objects = 6;
    num_pokemon=2;
    num_centers=2;
    num_gyms=2;
    cout << "Model default constructed" << endl;
}





Model::~Model ()
{
    delete pokemon_ptrs[0];
    delete center_ptrs[0];
    delete object_ptrs[0];
    delete gym_ptrs[0];
    cout << "Model destructed." << endl;
}

Pokemon* Model::GetPokemonPtr( int id)
{
    return pokemon_ptrs[id];
}
PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    return center_ptrs[id];
}
PokemonGym* Model::GetPokemonGymPtr(int id)
{
    return gym_ptrs[id];
}
bool Model::Update() {
    time++;
    for (int i = 0; i < num_objects; ++i) {
        if (object_ptrs[i]->Update())
            return true;
    }
    for (int i = 0; i < num_gyms; ++i) {//the player beats all the Pokemon gyms the game should print
        if (gym_ptrs[i]->IsBeaten()) {
            cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
            return false;//exit;
        }
    }
    for (int i = 0; i < num_objects; ++i) {
        if (pokemon_ptrs[i]->IsExhausted()) {
            cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
            return false;//exit;
        }
    }
}

//void Model::Display( View& view)
//{
//    cout << time;
//}

void Model::ShowStatus()
{

    for (int i = 0; i < 6; ++i)
    {
        object_ptrs[i]->ShowStatus();
    }
}