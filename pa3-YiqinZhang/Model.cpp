//
// Created by Garfield on 2019-11-17.
//
#include "Model.h"
#include <stdlib.h>


Model::Model()
{
    time = 0;
    pokemon_ptrs[0] = new Pokemon("Pikachu", 1, 'P', 5, Point2D(5,1));
    object_ptrs[0] = pokemon_ptrs[0];
    pokemon_ptrs[1] = new Pokemon("Bulbasaur", 2, 'P', 5, Point2D(10,1));
    object_ptrs[1] = pokemon_ptrs[1];
    center_ptrs[0] = new PokemonCenter(1, 5, 100, Point2D(1,20));
    object_ptrs[2] = center_ptrs[0];
    center_ptrs[1] = new PokemonCenter(2, 5, 100, Point2D(10,20));
    object_ptrs[3] = center_ptrs[1];
    gym_ptrs[0] = new PokemonGym(10,1,2,3,1, Point2D(0,0));
    object_ptrs[4] =  gym_ptrs[0];
    gym_ptrs[1] = new PokemonGym(20,5,7.5,8,2, Point2D(5,5));
    object_ptrs[5] = gym_ptrs[1];
    num_objects = 6;
    num_pokemon=2;
    num_centers=2;
    num_gyms=2;
    cout << "\t Model default constructed" << endl;
}


Model::~Model ()
{
for (int i = 0; i < num_objects; i++)
    delete object_ptrs[i];
    cout << "\t Model destructed.\n " ;
}

Pokemon* Model::GetPokemonPtr(int id) {
    for (int i = 0; i < num_pokemon; i++) {
        if (id == pokemon_ptrs[i]->GetId())
        {
            return pokemon_ptrs[i];
        }
        else
            continue;
    }
    return 0;
}
PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
    for (int i = 0; i < num_centers; i++) {
        if (id == center_ptrs[i]->GetId())
            return center_ptrs[i];
        else
            continue;
    }
    return 0;
}
PokemonGym* Model::GetPokemonGymPtr(int id)
{
    for (int i = 0; i < num_gyms; i++) {
        if (id == gym_ptrs[i]->GetId())
            return gym_ptrs[i];
        else
            continue;
    }
    return 0;
}

bool Model::Update() {
    time++;
    bool Updated = Update();
    for (int i = 0; i < num_objects; i++) {
        object_ptrs[i]->Update();}
    if (Updated)
            return true;
    for (int i = 0, j=0; i < num_gyms; i++) {//the player beats all the Pokemon gyms the game should print
        if (gym_ptrs[i]->IsBeaten()) {
            j++;}
        if (j== (num_objects -1))
        {
            cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
            exit(0);
        }
    }
    for (int i = 0, j=0; i < num_objects; i++) {
        if (pokemon_ptrs[i]->IsExhausted()) {
            j++;}
        if (j== (num_objects -1))
        {
            cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
            exit( 0);
        }
    }
    return 0;
}

void Model::Display( View& view)
{
    cout << "Time: "<< time << endl;
    view.Clear();
for (int i = 0; i < num_objects; i++)
{
    view.Plot(object_ptrs[i]);
}
    view.Draw();
return;
}

void Model::ShowStatus()
{

    for (int i = 0; i < num_objects; i++)
    {
        object_ptrs[i]->ShowStatus();
    }
}

int Model::GetTime()
{
    return time;
}