//
// Created by Garfield on 2019-11-06.
//

#ifndef PA33_POKEMONCENTER_H
#define PA33_POKEMONCENTER_H
#include "Point2D.h"
#include "Building.h"
class PokemonCenter: public Building
{
    enum PokemonCenterStates{
        STAMINA_POINTS_AVAILABLE = 0,
        NO_STAMINA_POINTS_AVAILABLE = 1
    };
private:
    unsigned int stamina_capacity;
    unsigned int num_stamina_points_remaining;
    double dollar_cost_per_stamina_point;
public:
    PokemonCenter();
    PokemonCenter(int, double, unsigned int , Point2D in_loc);
    bool HasStaminaPoints();
    unsigned int GetNumStaminaPointsRemaining();
    bool CanAffordStaminaPoints(unsigned int , double);
    double GetDollarCost(unsigned int stamina_points);
    unsigned int DistributeStamina(unsigned int points_needed);
    bool Update();
    void ShowStatus();
    ~PokemonCenter();
};
#endif //PA33_POKEMONCENTER_H
