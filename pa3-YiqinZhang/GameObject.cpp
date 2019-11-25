//
// Created by Garfield on 2019-11-05.
//

#include "Point2D.h"
#include "GameObject.h"


GameObject::GameObject(char in_code)
{
    display_code = in_code;
    id_num = 1;
    state = '0';
    cout << "\t GameObject constructed." << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    state = '0';
    cout << "\t GameObject constructed." << endl;
}


Point2D GameObject::GetLocation()
{
    return location;
}

int GameObject::GetId()
{
    return id_num;
}

char GameObject::GetState()
{
    return state;
}

void GameObject::ShowStatus()
{
    cout<< display_code<< " " << id_num <<  " " << " at " << location<< endl;
}

GameObject::~GameObject()
{
    cout << "\t GameObject destructed." << endl;
}
char GameObject::GetDisplayCode()
{
    return display_code;
}
void GameObject::DrawSelf( char* ptr)
{
//    display_code = *ptr;
    ptr[0] = display_code;
    if ((id_num >= 0)&& (id_num <=9))
    ptr[1]=+id_num+48;
    return;
    //    The function puts the display_code at the character pointed to by ptr, and then
//    the ASCII character for the id_num in the next character.
}