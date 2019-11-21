//
// Created by Garfield on 2019-11-19.
//

#ifndef PA32_GAMEOBJECT_H
#define PA32_GAMEOBJECT_H
#include "Point2D.h"

class GameObject
{
protected:
    Point2D location;
    int id_num;
    char display_code;
    char state;
public:
    GameObject(char in_code);
    GameObject(Point2D in_loc, int in_id, char in_code);
    Point2D GetLocation();
    int GetId();
    char GetState();
    void ShowStatus();
//    bool Update();
};

#endif //PA32_GAMEOBJECT_H