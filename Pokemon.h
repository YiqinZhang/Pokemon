//
// Created by Garfield on 2019-11-11.
//

#ifndef PA33_POKEMON_H
#define PA33_POKEMON_H
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include <string>

class Pokemon: public GameObject
{
    enum PokemonStates {
        STOPPED = 0,
        MOVING = 1,
        EXHAUSTED = 2,
        IN_GYM = 3,
        IN_CENTER = 4,
        MOVING_TO_GYM = 5,
        MOVING_TO_CENTER = 6,
        TRAINING_IN_GYM = 7,
        RECOVERING_STAMINA = 8
    };
public:
    Pokemon ();
    Pokemon (char);
    Pokemon (string in_name, int in_id, char in_code, unsigned int in_speed,
             Point2D in_loc);
    void StartMoving(Point2D);
    void StartMovingToCenter(PokemonCenter*);
    void StartMovingToGym( PokemonGym*);
    void StartTraining(unsigned int num_training_units);
    void StartRecoveringStamina( unsigned int num_stamina_points);
    void Stop();
    bool IsExhausted();
    bool ShouldBeVisible();
    void ShowStatus();
    bool Update();
    PokemonGym* getcurrentgym();
    ~Pokemon();
    string GetName();

protected:
    bool UpdateLocation();
    void SetupDestination(Point2D dest);

private:
    double speed;
    bool is_in_gym;
    bool is_in_center ;
    unsigned int stamina;
    unsigned int experience_points;
    double pokemon_dollars;
    unsigned int training_units_to_buy;
    unsigned int stamina_points_to_buy;
    string name;
    PokemonCenter* current_center;
    PokemonGym* current_gym;
    Point2D destination;
    Vector2D delta;
};

static double GetRandomAmountOfPokemonDollars();


#endif //PA33_POKEMON_H
