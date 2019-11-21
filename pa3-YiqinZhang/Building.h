//
// Created by Garfield on 2019-11-19.
//

#ifndef PA32_BUILDING_H
#define PA32_BUILDING_H
#include "Point2D.h"
#include "GameObject.h"

class Building: public GameObject
{
private:
    unsigned int pokemon_count;

public:
    Building();
    Building(char in_code, int in_id, Point2D in_loc);
    void AddOnePokemon();
    void RemoveOnePokemon();
    void ShowStatus();
    bool ShouldBeVisible();
};

#endif //PA32_BUILDING_H
