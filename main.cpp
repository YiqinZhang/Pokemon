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
    PokemonCenter Center2(2,1,50,Point2D(1,20));
    Center1.ShowStatus();
    Center2.ShowStatus();

    PokemonGym Gym1;
    Gym1.ShowStatus();
    PokemonGym Gym3(6,2,3,4,3,Point2D(10,20));
    Gym3.TrainPokemon(3);
    Gym3.ShowStatus();

    Pokemon Pica('K');
    Pica.ShowStatus();
    Pokemon Picachu("Picachu", 2, 'Q', 5 , Point2D(5,20));
    Picachu.ShowStatus();
//    GetRandomAmountOfPokemonDollars();
    Picachu.StartMoving(Point2D(5,20));
    Picachu.Update();
    Picachu.StartMovingToGym(&Gym3);
    Picachu.Update();
    Picachu.ShowStatus();
    Picachu.StartTraining(1);
    cout <<"Picachu state:"<< Picachu.GetState()<< endl;
    cout << "after training:";
    Picachu.Update();
    Picachu.ShowStatus();

    Picachu.StartMovingToGym(&Gym1);
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


    Gym3.Update();
    Gym3.ShowStatus();
    Center2.Update();
    Center2.ShowStatus();
    return 0;
}