//
// Created by Garfield on 2019-11-05.
//

#ifndef PA33_GAMEOBJECT_H
#define PA33_GAMEOBJECT_H
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
    virtual Point2D GetLocation();
    int GetId();
    char GetState();
    virtual void ShowStatus();
};


#endif //PA33_GAMEOBJECT_H
