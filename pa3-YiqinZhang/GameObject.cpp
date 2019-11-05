//
// Created by Garfield on 2019-11-05.
//

#include "Point2D.h"
#include "GameObject.h"


GameObject::GameObject(char in_code)
{
    display_code = in_code;
    id_num = 1;
    state = 0;
    cout << "GameObject constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    state = 0;
    cout << "GameObject constructed" << endl;
}


Point2D GameObject::GetLocation()
{
    return location;
}

int GameObject::GetId()
{
    return id_num;
}

bool GameObject::GetState()
{
    return state;
}


void GameObject::ShowStatus()
{
    cout<< display_code << id_num << " at " << location;
}