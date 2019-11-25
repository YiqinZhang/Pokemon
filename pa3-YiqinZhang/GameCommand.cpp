//
// Created by Garfield on 2019-11-22.
//
#include "GameCommand.h"
#include "Model.h"
#include "View.h"

#include <iostream>
using namespace std;

void DoMoveCommand( Model & model, int pokemon_id, Point2D p1){
    //the command arguments are valid
    if (model.GetPokemonPtr(pokemon_id)!=0)
        cout<< "Enter command: Moving "<< model.GetPokemonPtr(pokemon_id)->GetName() <<" to "<< p1 <<endl;
    else
        cout << "Error: Please enter a valid command!\n";
    return;
}

void DoMoveToCenterCommand( Model & model, int pokemon_id, int center_id)
{
    if((model.GetPokemonPtr(pokemon_id)!=0) && (model.GetPokemonCenterPtr(center_id)!=0))
        cout<< "Enter command: Moving "<< model.GetPokemonPtr(pokemon_id)->GetName()
            <<" to center "<< center_id <<endl;
        else
            cout << "Error: Please enter a valid command!\n";
    return;
}


void DoMoveToGymCommand( Model & model, int pokemon_id, int gym_id)
{
    if((model.GetPokemonPtr(pokemon_id)!=0) && (model.GetPokemonGymPtr(gym_id)!=0))
        cout<< "Enter command: Moving "<< model.GetPokemonPtr(pokemon_id)->GetName()
            <<" to gym "<< gym_id << endl;
    else
        cout << "Error: Please enter a valid command!\n";
    return;

}

void DoStopCommand( Model & model, int pokemon_id)
{
    if (model.GetPokemonPtr(pokemon_id)!=0)
        cout<< "Enter command: Stopping "<< model.GetPokemonPtr(pokemon_id)->GetName()
            <<model.GetPokemonPtr(pokemon_id)->GetDisplayCode() << pokemon_id <<endl;
    else
        cout << "Error: Please enter a valid command!\n";
    return;
}

void DoTrainInGymCommand( Model & model, int pokemon_id, unsigned int training_units)
{
    if (model.GetPokemonPtr(pokemon_id)!=0)
//   &&(training_units<= model.GetPokemonPtr(pokemon_id)-> training_units_to_buy))
        cout<< "Enter command: Training "<< model.GetPokemonPtr(pokemon_id)->GetName() <<endl;
    else
        cout << "Error: Please enter a valid command!\n";
    return;
}

void DoRecoverInCenterCommand( Model & model, int pokemon_id, unsigned int stamina_points)
{
if (model.GetPokemonPtr(pokemon_id)!=0)
    cout<< "Enter command: Recovering "<< model.GetPokemonPtr(pokemon_id)->GetName() <<"'s stamina \n";
else
    cout << "Error: Please enter a valid command!\n";
return;
}

void DoGoCommand( Model & model, View& view)
{
    model.Update();
    cout << "Enter command: Advancing one tick.\n";
    return;
}

void DoRunCommand( Model & model, View& view)
{
    bool Updated = model.Update();
    int Time = 0;
    do {model.Update();
    Time = model.GetTime();}
    while((!Updated) && (Time < 5));
    cout << "Enter command: Advancing to next event.\n";
    return;
}

