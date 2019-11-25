//
// Created by Garfield on 2019-11-23.
//

#ifndef PA33_USERINPUT_H
#define PA33_USERINPUT_H
#include "GameCommand.h"
class UserInput
{
public:
    char Inputcommand;
    int ID1=0;
    int ID2=0;
    Point2D P0;
    GetCommandCode();

};

void ParseUserInput(UserInput& out, istream& input);

#endif //PA33_USERINPUT_H
