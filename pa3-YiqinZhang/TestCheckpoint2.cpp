#include <iostream>
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "Building.h"
#include "Point2D.h"
#include "Pokemon.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"

using namespace std;

int main(int argc, char** argv) {

    char* program_name = argv[0];
    char* path = argv[1];

    // ./PA3 /tmp/myfile.txt

    Model model;
    Point2D p1(10,10);
//    model.ShowStatus();
//    DoMoveCommand( model, 1, p1);
//    DoMoveToGymCommand(model, 1, 1);
//    DoTrainInGymCommand(model, 1, 1);
//    DoGoCommand (model, 2, 2);
//    DoMoveToCenterCommand(model, 2, 2);
//    DoRecoverInCenterCommand(model, 2, 1);
    char input;
    int ID1=0;
    int ID2=0;
    Point2D P0;
    int stamina_amount = 0;
    int unit_amount = 0;
    View view;
    model.Display(view);
        view.Clear();
    view.Plot(model.GetPokemonPtr(1));
    view.Draw();

    cout<< "Start to play: \n";

    while(input == 0) {
        // prompt
        cin >> input;
        switch(input) {
            case 'm': {
                cin >> ID1;
                cin >> P0.x;
                cin >> P0.y;
                DoMoveCommand(model, ID1, P0);
                break;
            }
            case 'g': {
                cin >> ID1;
                cin >> ID2;
                DoMoveToGymCommand(model, ID1, ID2);
                break;
            }
            case 'c': {
                cin >> ID1;
                cin >> ID2;
                DoMoveToCenterCommand(model, ID1, ID2);
                break;
            }
            case 's': {
                cin >> ID1;
                DoStopCommand(model, ID1);
                break;
            }
            case 'r': {
                cin >> ID1;
                cin >> stamina_amount;
                DoRecoverInCenterCommand(model, ID1, stamina_amount);
                break;
            }
            case 't': {
                cin >> ID1;
                cin >> stamina_amount;
                DoRecoverInCenterCommand(model, ID1, stamina_amount);
                break;
            }
            case 'v': {
                DoGoCommand(model, view);
                break;
            }
            case 'x': {
                DoRunCommand(model, view);
                break;
            }
            case 'q': {
                exit(0);
            }
        }
    }
    return 0;
}
