#include <iostream>
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Building.h"
#include "Point2D.h"
#include "Pokemon.h"
using namespace std;

int main(int argc, char** argv) {

    Building b2('z',222,Point2D());
    b2.ShowStatus();

    char* program_name = argv[0];
    char* path = argv[1];

    // ./PA3 /tmp/myfile.txt

    PokemonCenter Center1;
    PokemonCenter Center2(2,1,10,Point2D(1,20));
    Center1.ShowStatus();
    Center2.ShowStatus();

    PokemonGym Gym1;
    Gym1.ShowStatus();
    PokemonGym Gym2(6,2,3,4,3,Point2D(10,20));
    Gym2.TrainPokemon(3);
    Gym2.ShowStatus();

    Pokemon Pica('K');
    Pica.ShowStatus();
    Pokemon Picachu("Picachu", 2, 'Q', 5 , Point2D(5,20));
    Picachu.ShowStatus();
//    GetRandomAmountOfPokemonDollars();
    Picachu.StartMoving(Point2D(5,20));
    Picachu.Update();
    Picachu.StartMovingToGym(&Gym2);
    Picachu.Update();
    Picachu.ShowStatus();
    Picachu.StartTraining(1);
    cout <<"Picachu state:"<< Picachu.GetState()<< endl;
    cout << "after training:";

    Picachu.StartMovingToGym(&Gym2);
    Picachu.Update();
    Picachu.ShowStatus();
    Picachu.StartTraining(1);
    Picachu.Update();
    Picachu.ShowStatus();

    Pokemon Picaya("Picaya", 3, 'Y', 5 , Point2D(10,20));
    Picaya.ShowStatus();
//    GetRandomAmountOfPokemonDollars();
    Picaya.StartMovingToCenter(&Center2);
    Picaya.Update();
    Picaya.ShowStatus();
    Center2.Update();
    Center2.ShowStatus();
    Picaya.StartRecoveringStamina(2);

    Picaya.Update();
    Picaya.ShowStatus();
    Picaya.StartTraining(1);
    Picaya.Update();
    Picaya.ShowStatus();


    Gym2.Update();
    Gym2.ShowStatus();
    Center2.Update();
    Center2.ShowStatus();
    return 0;
}