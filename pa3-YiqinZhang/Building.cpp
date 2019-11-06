#include "Building.h"
#include "Point2D.h"

unsigned int Building::pokemon_count = 0;

Building::Building()
    {
    display_code = 'B';
    cout << " Building default constructed."
    }
Building::Building(char in_code, int in_Id, Point2D in_loc)
{
    id_num = in_Id;
    location = in_loc;
    display_code = in_code;
    cout << " Building constructed."
}

void Building:: AddOnePokemon();
{
    pokemon_count ++;
}	
void Building::RemoveOnePokemon();
{
    pokemon_count --;
}	
void Building::ShowStatus();
{
    cout << display_code <<" " << id << " located at " << location << endl;
    if(pokemon_count <= 1 ) 
    cout << pokemon_count << " pokemen is in this building." << endl;
    else 
    cout << pokemon_count << " pokemen are in this building."<< endl;
}	
	
void Building::ShouldBeVisible()
{
return true;

}
