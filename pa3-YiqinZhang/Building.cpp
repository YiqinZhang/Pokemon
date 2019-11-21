//
// Created by Garfield on 2019-11-19.
//

#include "Building.h"
#include "Point2D.h"
#include "GameObject.h"

Building::Building(): GameObject('B')
{
    pokemon_count = 0;
    cout << "Building default constructed." << endl;
}
Building::Building(char in_code, int in_id, Point2D in_loc):GameObject(in_loc, in_id, in_code)
{
    pokemon_count = 0;
    cout << "Building constructed."<< endl;
}

void Building:: AddOnePokemon()
{
    pokemon_count ++;
}
void Building::RemoveOnePokemon()
{
    pokemon_count --;
}
void Building::ShowStatus()
{
    //cout << display_code <<" " << id_num << " located at " << location << endl;
    if(pokemon_count <= 1 )
        cout << "\t"<< pokemon_count << " pokemen is in this building." << endl;
    else
        cout << "\t"<< pokemon_count << " pokemen are in this building."<< endl;
}

bool Building::ShouldBeVisible()
{
    return true;

}