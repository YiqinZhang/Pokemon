//
// Created by Garfield on 2019-11-16.
//

#ifndef PA33_GAMECOMMAND_H
#define PA33_GAMECOMMAND_H

#include "Model.h"
#include "View.h"

void DoMoveCommand( Model & model, int pokemon_id, Point2D p1);
void DoMoveToCenterCommand( Model & model, int pokemon_id, int center_id);
void DoMoveToGymCommand( Model & model, int pokemon_id, int gym_id);
void DoStopCommand( Model & model, int pokemon_id);
void DoTrainInGymCommand( Model & model, int pokemon_id, unsigned int
training_units);
void DoRecoverInCenterCommand( Model & model, int pokemon_id, unsigned int
stamina_points);
void DoGoCommand( Model & model, View& view);
void DoRunCommand( Model & model, View& view);

#endif //PA33_GAMECOMMAND_H
