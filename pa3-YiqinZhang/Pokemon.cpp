//
// Created by Garfield on 2019-11-19.
//

#include "Pokemon.h"
#include "PokemonCenter.h"
#include "Building.h"
#include "Point2D.h"
#include "Vector2D.h"
#include <string>
#include "math.h"
#include <time.h>

Pokemon::Pokemon():GameObject('P')
{
    speed = 5;
    state = STOPPED;
    cout << "Pokemon default constructed." << endl;
    name = "Default Pokemon";
    is_in_gym = false;
    is_in_center = false ;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy= 0;
    stamina_points_to_buy= 0;
    current_center = 0;
    current_gym= 0;
    destination.x = 0.0;
    destination.y = 0.0;
}
Pokemon::Pokemon(char in_code): GameObject(in_code)
{
    speed = 5;
    state = STOPPED;
    display_code = in_code;
    cout << "Pokemon constructed." << endl;
    name = "Default Pokemon";
    is_in_gym = false;
    is_in_center = false ;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy= 0;
    stamina_points_to_buy= 0;
    current_center = 0;
    current_gym= 0;
    destination.x = 0.0;
    destination.y = 0.0;
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed,
                 Point2D in_loc): GameObject(in_loc, in_id, in_code)
{
    speed = in_speed;
    name = in_name;
    state = STOPPED;
    cout << "Pokemon constructed." << endl;
    is_in_gym = false;
    is_in_center = false ;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy= 0;
    stamina_points_to_buy= 0;
    current_center = 0;
    current_gym= 0;
    destination.x = 0.0;
    destination.y = 0.0;
}

void Pokemon::StartMoving(Point2D dest)
{
    if (stamina)// MOVING == 1; Tells the Pokemon to start moving.
    {
        SetupDestination(dest);// Calls the setup_destination() function.

        if (((location - dest).x== 0) && ((location - dest).y== 0))
            //if ((location.x == dest.x) && (location.y == dest.y))
            //If this Pokemon is already at the destination print
            cout << "\t " << display_code << " " << id_num << " : I’m already there. See? " << endl;
        else{
            state = MOVING; //Sets the state to MOVING
            cout << "\t " << display_code << " " << id_num << " : On my way. " << endl;
        }
    }
    else{//If this Pokemon is exhausted print
        state = EXHAUSTED;
        cout << "\t " <<display_code << " " << id_num
             << " : I am exhausted. I may move but you cannot see me." << endl;
    }
}

void Pokemon::StartMovingToCenter(PokemonCenter* center) {
    if (stamina)// MOVING == 1; //Tells the Pokemon to start moving.
    {
        current_center = center;
        SetupDestination(current_center->GetLocation());// Calls the setup_destination() function.

        if ((location.x == (current_center->GetLocation().x)) && (location.y == (current_center->GetLocation().y)))
            //if (((location - center->GetLocation())== 0) && ((location - center).y== 0))
            //If this Pokemon is already at the destination print
        {
            cout << "\t " << display_code << " " << id_num << " : I am already at the Pokemon Center! " << endl;
            state = IN_CENTER;
            is_in_center = 1;
            current_center->AddOnePokemon();
        } else{
            state = MOVING_TO_CENTER; //Sets the state to MOVING
            cout << "\t " << display_code << " " << id_num << " : On my way to center " << current_center->GetId() << endl;
        }
    } else {//If this Pokemon is exhausted print
        state = EXHAUSTED;
        cout << "\t " << display_code << " " << id_num << " : I am exhausted so I can’t move to recover stamina…"
             << endl;
    }
}

void Pokemon::StartMovingToGym(PokemonGym* gym)
{
    if (stamina)// MOVING == 1; //Tells the Pokemon to start moving.
    {
        current_gym = gym;
        SetupDestination(current_gym->GetLocation());
        // SetupDestination() function with PokemonGym’s location as the destination.
        if ((location.x == (current_gym->GetLocation().x)) && (location.y == (current_gym->GetLocation().y)))
            //If this Pokemon is already at the destination print
        {
            cout << "\t " << display_code << " " << id_num << " : I am already at the Pokemon Gym! " << endl;
            state = IN_GYM;
            is_in_gym = 1;
            current_gym->AddOnePokemon();
        }
        else{
            state = MOVING_TO_GYM; //Sets the state to MOVING
            cout << "\t " << display_code << " " << id_num << " : On my way to gym " << gym->GetId() << endl;
        }
    }
    else{
        state = EXHAUSTED;
        cout << "\t " <<display_code << " " << id_num
             << " : I am exhausted so I shouldn’t be going to the gym..." << endl;
    }
}

void Pokemon::StartTraining(unsigned int num_training_units) {
    if (state == IN_GYM) {
        if (IsExhausted()) //If this Pokemon is exhausted print
            cout << "\t " << display_code << " " << id_num
                 << " : I am exhausted so no more training for me..." << endl;
        else if (!is_in_gym)
            cout << "\t " << display_code << " " << id_num << " : I can only train in a Pokemon Gym! " << endl;

        else if ((pokemon_dollars < (current_gym->GetDollarCost(num_training_units)))
                 || (stamina < (current_gym->GetStaminaCost(num_training_units))))
//        else if((training_units_to_buy < num_training_units)
//                ||(stamina_points_to_buy < num_training_units))
        {
            cout << "\t " << display_code << " " << id_num
                 << " : Not enough stamina and/or money for training " << endl;
            state = IN_GYM;
        } else if (current_gym->IsBeaten())
            cout << "\t " << display_code << " " << id_num
                 << " : Cannot train! This Pokemon Gym is already beaten! " << endl;
        else {
            cout << "\t " << display_code << " Started to train at Pokemon Gym " << current_gym->GetId()
                 << " with " << num_training_units << " training units" << endl;
            state = TRAINING_IN_GYM; //Sets the state to TRAINING_IN_GYM
            training_units_to_buy = fmin(num_training_units, current_gym->GetNumTrainingUnitsRemaining());
            //set its training_units_to_buy to the minimum of
            //the requested training units and the remaining training units in the gym.
        }
    }

}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
    if (state == IN_CENTER) {
            if (!(current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars))) {
                cout << "\t " << display_code << " " << id_num
                     << " : Not enough money to recover stamina. " << endl;
            } else if (!current_center->HasStaminaPoints())
                cout << "\t " << display_code << " " << id_num
                     << " : Cannot recover! No stamina points remaining in this Pokemon Center " << endl;
            else if (!is_in_center)
                cout << "\t " << display_code << " " << id_num
                     << " : I can only recover stamina at a Pokemon Center! " << endl;

            else {
                cout << "\t " << display_code << " " << id_num << " : Started recovering " << num_stamina_points
                     << "stamina point(s) at Pokemon Center " << current_center->GetId() << endl;
                state = RECOVERING_STAMINA; //Sets the state to recovering
                stamina_points_to_buy = fmin(num_stamina_points, current_center->GetNumStaminaPointsRemaining());
            }
    }

}

//    If this Pokemon can start recovering stamina, set its stamina_points_to_buy to
//    the minimum of the requested stamina points and the remaining stamina points in
//    the center. This will be used when its Update() function is called.


void Pokemon::Stop()
{
    state = STOPPED;
    cout << "\t " <<display_code << " " << id_num << " : stopping..." << endl;
    return;
}

bool Pokemon::IsExhausted()
{
    if (!stamina)
        return true;
    else
        return false;
}

bool Pokemon::ShouldBeVisible()
{
    if (stamina)
        return true;
    else
        return false;
}

void Pokemon::ShowStatus()
{
    cout<< name << " status: ";
    GameObject::ShowStatus();

    switch(state)
    {
        case STOPPED:
        {//STOPPED
            cout << "\t stopped \n";
            break;
        }
        case MOVING: {//moving
            cout << "\t moving at a speed of " << speed << " to destination " << destination
                 << " at each step of " << delta<< endl;
            cout << "\t Stamina: " << stamina<< endl;
            cout << "\t Pokemon Dollars: " << pokemon_dollars<< endl;
            cout << "\t Experience Points: " << experience_points<< endl;
            break;
        }
        case EXHAUSTED:{
            cout << "	 Stamina: 0 \n" ;
            cout << "	 Pokemon Dollars: " << pokemon_dollars<< endl;
            cout << "	 Experience Points: " << experience_points<< endl;
            break;
        }

        case IN_GYM: {
            cout << "\t inside Pokemon Gym " << current_gym->GetId() << endl;
            cout << "\t Stamina: " << stamina<< endl;
            cout << "\t Pokemon Dollars: " << pokemon_dollars<< endl;
            cout << "\t Experience Points: " << experience_points<< endl;
            break;
        }
        case IN_CENTER:{
            cout << "\t inside Pokemon Center " << current_center->GetId() << endl;
            break;
        }
        case MOVING_TO_GYM:{
            cout << "\t heading to Pokemon Gym " << current_gym->GetId() << "  at a speed of "
                 << speed << " at each step of " << delta<< endl;
            cout << "\t Stamina: " << stamina<< endl;
            cout << "\t Pokemon Dollars: " << pokemon_dollars<< endl;
            cout << "\t Experience Points: " << experience_points<< endl;
            break;
        }
        case MOVING_TO_CENTER:{
            cout << "\t heading to Pokemon Center " << current_center->GetId() << "  at a speed of "
                 << speed << " at each step of " << delta<< endl;
            cout << "\t Stamina: " << stamina<< endl;
            cout << "\t Pokemon Dollars: " << pokemon_dollars<< endl;
            cout << "\t Experience Points: " << experience_points<< endl;
        }
        case TRAINING_IN_GYM: {
            cout << "\t training in Pokemon Gym " << current_gym->GetId() << endl;
            cout << "\t Stamina: " << stamina<< endl;
            cout << "\t Pokemon Dollars: " << pokemon_dollars<< endl;
            cout << "\t Experience Points: " << experience_points<< endl;
            break;
        }
        case RECOVERING_STAMINA:{
            cout << "\t recovering stamina in Pokemon Center " << current_center->GetId() << endl;
            cout << "\t Stamina: " << stamina<< endl;
            cout << "\t Pokemon Dollars: " << pokemon_dollars<< endl;
            cout << "\t Experience Points: " << experience_points<< endl;
            break;
        }
        default:
            return;
    }
    return;
}

bool Pokemon::Update()
{
    bool arrived = UpdateLocation();
    switch(state)
    {
        case STOPPED:
        {//STOPPED
            return false;
        }
        case MOVING:{//moving
          if (stamina)
          {
              if(is_in_gym)
                  current_gym->Building::RemoveOnePokemon();
              if(is_in_center)
                  current_center->Building::RemoveOnePokemon();
              UpdateLocation();
              if(arrived)
              {
                  state = STOPPED;
                  return true;
              }
              else {
                  state = MOVING;
                  return false;
              }
          }
          else {
              state = EXHAUSTED;
              return false;
          }
        }

        case EXHAUSTED:
            {
            return false;
            }
        case IN_GYM: {
            return false;
        }

        case IN_CENTER:{
            return false;
        }
        case MOVING_TO_GYM: {
            if (stamina) {
                UpdateLocation();
                if (arrived) {
                    state = IN_GYM;
                    current_gym->Building::AddOnePokemon();
                    return true;
                }
                else {
                    state = MOVING;
                    return false;
                }
            }
            else {
                state = EXHAUSTED;
                return false;
            }
        }
        case MOVING_TO_CENTER: {
            if (stamina) {
                UpdateLocation();
                if (arrived)
                {
                    state = IN_CENTER;
                    current_center->Building::AddOnePokemon();
                return true;
                }
            else {
                state = MOVING;
                return false;
            }
            }
            else {
                state = EXHAUSTED;
                return false;
            }
        }
        case TRAINING_IN_GYM:{
            stamina -= current_gym->GetStaminaCost(training_units_to_buy);
            pokemon_dollars -= current_gym->GetDollarCost(training_units_to_buy);
            experience_points +=  current_gym->TrainPokemon(training_units_to_buy);
            cout << "** " << name << " completed " << training_units_to_buy
                 << " training unit(s)! ** " << endl;
            cout << "** " << name << " gained " << experience_points
                 << " experience point(s)! ** " << endl;
            state = IN_GYM;
            return true;
        }

        case RECOVERING_STAMINA:{
            stamina += current_center->DistributeStamina(stamina_points_to_buy);
            pokemon_dollars -= current_center->GetDollarCost(stamina_points_to_buy);
            cout << "** " << name << " recovered " << current_center->DistributeStamina(stamina_points_to_buy)
                 << " stamina point(s)! ** " << endl;
            state = IN_CENTER;
            cout << " Stamina: " << stamina<< endl;
            cout << " Pokemon Dollars: " << pokemon_dollars<< endl;
            cout << " Experience Points: " << experience_points<< endl;
            return true;
        }
        default:
            return false;
    }
}
bool Pokemon::UpdateLocation()
{
    cout << " \t location is " << location<< endl;
    cout << " \t destination is " << destination<< endl;
    if ((location.x == destination.x) && (location.y == destination.y))
    {
        cout <<"\t "<< display_code << " " << id_num << " : I'm there!" << endl;
        return true;
    }

    else if ((fabs((destination-location).x) <= fabs(delta.x))&&
        (fabs((destination-location).y) <= fabs(delta.y)))
    {
        location = destination;
        cout << "\t arrived \n";
        //state = STOPPED;
        return true;
    }
    else{
        location = location + delta;
        stamina --;
        pokemon_dollars += GetRandomAmountOfPokemonDollars();
        cout << "\t moved \n";
        return false;
    }

}

void Pokemon::SetupDestination(Point2D dest)
{
    destination.x = dest.x;
    destination.y = dest.y;
    delta = (destination - location) * (speed / GetDistanceBetween(destination, location));
    cout << " \t location is " << location<< endl;
    cout << " \t destination is " << destination<< endl;
    cout << " \t delta is " << delta<< endl;
}


static double GetRandomAmountOfPokemonDollars()
{
    srand((int)time(0));
    return (rand()% 201/100);
}