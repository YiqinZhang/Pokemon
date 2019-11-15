//
// Created by Garfield on 2019-11-11.
//

#include "Pokemon.h"
#include "PokemonCenter.h"
#include "Point2D.h"
#include "Vector2D.h"
#include <string>
#include "math.h"
#include <time.h>

Pokemon::Pokemon():GameObject('P')
{
    speed = 5;
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
    cout << "Pokemon default constructed." << endl;
}
Pokemon::Pokemon(char in_code): GameObject(in_code)
{
    speed = 5;
    cout << "Pokemon constructed." << endl;
    state = '0';
    display_code = in_code;
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
    cout << "Pokemon constructed";
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
    if ((state != '2') && (!IsExhausted()))// MOVING == 1; //Tells the Pokemon to start moving.
    {
        SetupDestination(dest);// Calls the setup_destination() function.
        state = '1'; //Sets the state to MOVING
        if (state == '1')
            UpdateLocation();
        else
            Update();
    }
    if (((location - dest).x== 0) && ((location - dest).y== 0))
    //if ((location.x == dest.x) && (location.y == dest.y))
        //If this Pokemon is already at the destination print
       cout <<  display_code << " " << id_num << " : I’m already there. See? " << endl;
    else if (state == '2') //If this Pokemon is exhausted print
        cout <<  display_code << " " << id_num << " : I am exhausted. I may move but you cannot see me." << endl;
    else
        cout <<  display_code << " " << id_num << " : On my way. " << endl;
}

void Pokemon::StartMovingToCenter(PokemonCenter* center)
{
    if (state != '2')// MOVING == 1; //Tells the Pokemon to start moving.
    {
        SetupDestination(center->GetLocation());// Calls the setup_destination() function.
        state = '6'; //Sets the state to MOVING
    }
    if (state == '2') //If this Pokemon is exhausted print
        cout <<  display_code << " " << id_num << " : I am exhausted so I can’t move to recover stamina…" << endl;
    else if ((location.x == (center->GetLocation().x)) && (location.y == (center->GetLocation().y))){
        //if (((location - center->GetLocation())== 0) && ((location - center).y== 0))
        //If this Pokemon is already at the destination print
        cout <<  display_code << " " << id_num << " : I am already at the Pokemon Center! " << endl;
        state = '4';
    }
    else
        cout <<  display_code << " " << id_num << " : On my way to center " << center->GetId()<< endl;
}

void Pokemon::StartMovingToGym(PokemonGym* gym)
{
    if (state != '2')// MOVING == 1; //Tells the Pokemon to start moving.
    {
        SetupDestination(gym->GetLocation());
        // SetupDestination() function with PokemonGym’s location as the destination.
        state = '5'; //Sets the state to MOVING
    }
    if (state == '2') //If this Pokemon is exhausted print
        cout << display_code << " " << id_num
             << " : I am exhausted so I shouldn’t be going to the gym..." << endl;
    else if ((location.x == (gym->GetLocation().x)) && (location.y == (gym->GetLocation().y)))
        //If this Pokemon is already at the destination print
    {
        cout << display_code << " " << id_num << " : I am already at the Pokemon Gym! " << endl;
        state = '3';
    }
    else
        cout << display_code << " " << id_num << " : On my way to gym " << gym->GetId() << endl;
}

void Pokemon::StartTraining(unsigned int num_training_units)
{
    while (state == '3')
    {
        if (IsExhausted()) //If this Pokemon is exhausted print
            cout << display_code << " " << id_num
                 << " : I am exhausted so no more training for me..." << endl;
        else if (!is_in_gym)
            cout << display_code << " " << id_num << " : I can only train in a Pokemon Gym! " << endl;

        else if((training_units_to_buy < num_training_units)
                ||(stamina_points_to_buy < num_training_units))
        {
            cout << display_code << " " << id_num
                 << " : Not enough stamina and/or money for training " << endl;
            state = '3';
        }
        else if (current_gym->IsBeaten())
            cout << display_code << " " << id_num
                 << " : Cannot train! This Pokemon Gym is already beaten! " << endl;
        else{
            cout << display_code << " Started to train at Pokemon Gym " << current_gym -> GetId()
                 << " with " << num_training_units << " training units" << endl;
            state = '7'; //Sets the state to TRAINING_IN_GYM
            training_units_to_buy = min(num_training_units,current_gym->GetNumTrainingUnitsRemaining());
            //set its training_units_to_buy to the minimum of
            //the requested training units and the remaining training units in the gym.
        }
    }

}

void Pokemon::StartRecoveringStamina( unsigned int num_stamina_points)
{
    while (state == '4')
    {
        if (!current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars))
        {
            cout << display_code << " " << id_num
                 << " :  Not enough money to recover stamina. " << endl;
        }
        else if (!current_center->HasStaminaPoints())
            cout << display_code << " " << id_num
                 << " : Cannot recover! No stamina points remaining in this Pokemon Center " << endl;
        else if (!is_in_center)
            cout << display_code << " " << id_num
                 << " : I can only recover stamina at a Pokemon Center! " << endl;

        else {
            cout << display_code << " " << id_num << " : Started recovering " << num_stamina_points
                 << "stamina point(s) at Pokemon Center " << current_center->GetId() << endl;
            state = '8'; //Sets the state to recovering
            stamina_points_to_buy = min(num_stamina_points, current_center->GetNumStaminaPointsRemaining());
        }
    }

}
//    If this Pokemon can start recovering stamina, set its stamina_points_to_buy to
//    the minimum of the requested stamina points and the remaining stamina points in
//    the center. This will be used when its Update() function is called.


    void Pokemon::Stop()
{
    state = '0';
    cout << display_code << " " << id_num << " : stopping..." << endl;
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
    if (!IsExhausted()) //(stamina)
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
        case 0:
        {//STOPPED
            cout << " stopped ";
            break;
        }
        case 1: {//moving
            cout << " moving at a speed of " << speed << " to destination " << destination
                 << " at each step of " << delta;
            cout << " Stamina: " << stamina;
            cout << " Pokemon Dollars: " << pokemon_dollars;
            cout << " Experience Points: " << experience_points;
            break;
            }
        case 2:{
            cout << " Stamina: " << stamina;
            cout << " Pokemon Dollars: " << pokemon_dollars;
            cout << " Experience Points: " << experience_points;
        }

        case 3: {
            cout << " inside Pokemon Gym " << current_gym->GetId() << endl;
            cout << " Stamina: " << stamina;
            cout << " Pokemon Dollars: " << pokemon_dollars;
            cout << " Experience Points: " << experience_points;
            break;
            }
        case 4:{
                cout << " inside Pokemon Center " << current_center->GetId() << endl;
                break;
            }
        case 5:{
            cout << " heading to Pokemon Gym " << current_gym->GetId() << "  at a speed of "
                 << speed << " at each step of " << delta<< endl;
            cout << " Stamina: " << stamina;
            cout << " Pokemon Dollars: " << pokemon_dollars;
            cout << " Experience Points: " << experience_points;
                break;
            }
        case 6:{
            cout << " heading to Pokemon Center " << current_center->GetId() << "  at a speed of "
                 << speed << " at each step of " << delta<< endl;
            cout << " Stamina: " << stamina;
            cout << " Pokemon Dollars: " << pokemon_dollars;
            cout << " Experience Points: " << experience_points;
        }
        case 7: {
            cout << " training in Pokemon Gym " << current_gym->GetId() << endl;
            cout << " Stamina: " << stamina;
            cout << " Pokemon Dollars: " << pokemon_dollars;
            cout << " Experience Points: " << experience_points;
            break;
            }
        case 8:{
            cout << " recovering stamina in Pokemon Center " << current_center->GetId() << endl;
            cout << " Stamina: " << stamina;
            cout << " Pokemon Dollars: " << pokemon_dollars;
            cout << " Experience Points: " << experience_points;
            break;
            }
        }
            return;
}

bool Pokemon::Update()
{
    switch(state)
    {
        case 0:
            {//STOPPED
                ShowStatus();
                return false;
            }
        case 1:{//moving
                ShowStatus();
                UpdateLocation();
                if ((location.x == destination.x) && (location.y == destination.y))
                    {
                        state = '0';
                        return true;
                    }
                else {
                    state = '1';
                    return false;
                    }
            }
        case 2:{
            ShowStatus();
            return false;
        }
        case 3: {
            ShowStatus();
            return false;
            }

        case 4:{
            ShowStatus();
            return false;
            }
        case 5:{
                ShowStatus();
                UpdateLocation();
                if ((location.x == destination.x) && (location.y == destination.y))
                    {
                    state = '3';
                    return true;
                    }
                else {
                    state = '1';
                    return false;
                }
            }
        case 6: {
            ShowStatus();
            UpdateLocation();
            if ((location.x == destination.x) && (location.y == destination.y))
                {
                state = '4';
                return true;
                }
            else {
                state = '1';
                return false;
                }
            }
        case 7:{
            stamina -= current_gym->GetStaminaCost(stamina_points_to_buy);
            pokemon_dollars -= current_gym->GetDollarCost(training_units_to_buy);
            experience_points +=  current_gym->TrainPokemon(training_units_to_buy);
            cout << "** " << name << " completed " << training_units_to_buy
                 << " training unit(s)! ** " << endl;
            cout << "** " << name << " gained " << experience_points
                 << " experience point(s)! ** " << endl;
            state = '3';
            return true;
        }

        case 8:{
            stamina += current_center->DistributeStamina(stamina_points_to_buy);
            pokemon_dollars -= current_center->GetDollarCost(training_units_to_buy);
            cout << "** " << name << " recovered " << current_center->DistributeStamina(stamina_points_to_buy)
                 << " stamina point(s)! ** " << endl;
            state = '4';
            cout << " Stamina: " << stamina;
            cout << " Pokemon Dollars: " << pokemon_dollars;
            cout << " Experience Points: " << experience_points;
            return true;
        }
        default:
        return 0;
    }
}
bool Pokemon::UpdateLocation()
{
/*    This function first checks to see if the object is within one step of its
    destination (see below).
    If it is, UpdateLocation() sets the object’s location to the destination,
    prints an “arrived” message, and then returns true to indicate that the object arrived.
    If the object is not within a step of destination,
    UpdateLocation() adds the delta to the location, prints a “moved” messaged,
    and returns false to indicate that the object has not yet arrived.
    Thus the object will take a “speed-sized” step on each update “tick” until
    it gets within one step of the destination, and then on the last step,
    goes exactly to the destination.*/
    while (state == '1')
    {
        if ((fabs((destination-location).x) <= fabs(delta.x))&&
            (fabs((destination-location).y) <= fabs(delta.y)))
        {
            location = destination;
            cout << " arrived " <<endl;
            //state = '0';
            return true;
        }
        else
//        while((fabs((destination-location).x) > fabs(delta.x))&&
//              (fabs((destination-location).y) > fabs(delta.y)))
        {
            location = location + delta;
            stamina --;
            pokemon_dollars += GetRandomAmountOfPokemonDollars();
            cout << " moved " <<endl;
            return false;
        }

    }
    cout << display_code << " " << id_num << " : I'm there!" << endl;
    return true;
}
void Pokemon::SetupDestination(Point2D dest)
{
    destination.x = dest.x;
    destination.x = dest.y;
    delta = (destination - location) * (speed / GetDistanceBetween(destination, location));

}


double GetRandomAmountOfPokemonDollars()
{
    return (rand()%101/100*2);
}