#include "Model.h"
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include "Rival.h"
#include <list>

Model::Model() {
    time = 0;
    //Pikachu 1
    Pokemon* pokemon1 = new Pokemon("Pikachu", 1, 'P', 2.0, Point2D(5, 1));
    Pokemon* pokemon2 = new Pokemon("Bulbasaur", 2, 'P', 1.0, Point2D(10, 1));
    pokemon_ptrs.push_back(pokemon1);
    pokemon_ptrs.push_back(pokemon2);
    object_ptrs.push_back(pokemon1);
    object_ptrs.push_back(pokemon2);
    active_ptrs.push_back(pokemon1);
    active_ptrs.push_back(pokemon2);
    Rival* rival1= new Rival("Burhack", 5.0, 16,3,4,12, 1, Point2D(15,12));
    object_ptrs.push_back (rival1);
    Rival* rival2 = new Rival("Mmark9", 5.0, 20,3,7.2,20, 2, Point2D(15,12));
    object_ptrs.push_back (rival2);
    Rival* rival3= new Rival("Densmore(aka BigBoss)", 5, 41,6,8.2,18, 3, Point2D(15,12));
    object_ptrs.push_back (rival3);
    rival_ptrs.push_back (rival1);
    rival_ptrs.push_back (rival2);
    rival_ptrs.push_back (rival3);
    active_ptrs.push_back(rival1);
    active_ptrs.push_back(rival2);
    active_ptrs.push_back(rival3);
    //PokemonCenter 1
    PokemonCenter* center1= new PokemonCenter(1, 1, 100, Point2D(1, 20));
    object_ptrs.push_back (center1);
    //PokemonCenter 2
    PokemonCenter* center2 = new PokemonCenter(2, 2, 200,  Point2D(10, 20));
    object_ptrs.push_back (center2);
    center_ptrs.push_back (center1);
    center_ptrs.push_back (center2);
    active_ptrs.push_back (center1);
    active_ptrs.push_back (center2);
    //PokemonGym
    PokemonGym* gym1 = new PokemonGym(10, 1.0,
                                      2.0, 3, 1, Point2D(0, 0));
    object_ptrs.push_back (gym1);
    PokemonGym* gym2 = new PokemonGym(20, 5,
                                      7.5, 8, 2, Point2D(5, 5));
    object_ptrs.push_back (gym2);
    gym_ptrs.push_back (gym1);
    gym_ptrs.push_back (gym2);
    active_ptrs.push_back (gym1);
    active_ptrs.push_back (gym2);
    arena = new BattleArena(3, 3,2.5, 1, Point2D(15, 12));
    object_ptrs.push_back (arena);
    active_ptrs.push_back (arena);
    cout << "Model default constructed. " << endl;
}

Model::~Model() {
    for(auto it = object_ptrs.begin(); it != object_ptrs.end(); it++) {
        delete (*it);
        }
    cout << "Model destructed. " << endl;
}

Pokemon *Model::GetPokemonPtr(int id) {
    list<Pokemon*>::iterator it;
    for (it=pokemon_ptrs.begin(); it!=pokemon_ptrs.end(); it++) {
        if (id == (*it)->GetId()) {
            return *it;
        }
    }
    return 0;
}

PokemonCenter *Model::GetPokemonCenterPtr(int id) {
    list<PokemonCenter*>::iterator it;
    for (it=center_ptrs.begin(); it!=center_ptrs.end(); it++) {
        if (id == (*it)->GetId()) {
            return (*it);
        }
    }
    return 0;
}

PokemonGym *Model::GetPokemonGymPtr(int id) {
    list<PokemonGym*>::iterator it;
    for (it=gym_ptrs.begin(); it!=gym_ptrs.end(); it++) {
        if (id == (*it)->GetId()) {
            return (*it);
        }
    }
    return 0;
}

BattleArena* Model::GetBattleArenaPtr(int id) {
    if (id == arena->GetId()) {
        return arena;
    }
    return 0;
}


Rival* Model::GetRivalPtr(int id) {
    list<Rival*>::iterator it;
    for (it=rival_ptrs.begin(); it!=rival_ptrs.end(); ++it) {
        if (id == (*it)->GetId()) {
            return (*it);
        }
    }
    return 0;
}

bool Model::Update() {
    time++;
    int gyms_beaten = 0;
    int pokemon_exhausted = 0;
//    int rivals_beaten = 0;
    //Calculating number of gyms beaten
    if (gyms_beaten != gym_ptrs.size()) {
        for (auto it=gym_ptrs.begin(); it!=gym_ptrs.end(); ++it) {
            if ((*it)->GetState() == BEATEN)
                gyms_beaten++;
        }
    }
    // Calculating number of pokemon that are tired
    if (pokemon_exhausted != pokemon_ptrs.size()) {
        for (auto it=pokemon_ptrs.begin(); it!=pokemon_ptrs.end(); ++it)  {
            if ((*it)->IsExhausted())
                pokemon_exhausted++;
        }
    }

    bool event = false;
    // continue to update all
    if (gyms_beaten == gym_ptrs.size()) {
        cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
        exit(EXIT_SUCCESS);
    }
    if (pokemon_exhausted == pokemon_ptrs.size()) {
        cout << "GAME OVER: You lose! All of your Pokemon are exhausted!" << endl;
        exit(EXIT_SUCCESS);
    }
    for(auto it = active_ptrs.begin(); it != active_ptrs.end(); ++it) {
        if (!(*it)->ShouldBeVisible()) {
            it = active_ptrs.erase(it);
            cout << "Dead object removed " << *it <<endl;
        }
    }
    for (auto it=object_ptrs.begin(); it!=object_ptrs.end(); ++it) {
        bool temp = (*it)->Update();
        if (temp) {
            event = temp;
        }
    }
    return event;
}

void Model::Display(View &view) {
    view.Clear();
   // cout << "Active ptrs size = " << active_ptrs.size() << endl;
    for(auto it = active_ptrs.begin(); it != active_ptrs.end(); it++) {
        view.Plot(*it);
    }
    view.Draw();
}

void Model::ShowStatus() {
    cout << "Time: " << time << endl;
    for (auto it=object_ptrs.begin(); it!=object_ptrs.end(); it++) {
        (*it)->ShowStatus();
    }
}
