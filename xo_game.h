/*
 * xo_game.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: VIP B
 */

#ifndef XO_GAME_H_
#define XO_GAME_H_

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "compiler.h"

#define ROWS 3
#define COLUMNS 3

typedef enum gameStatus{
	GameWin = 0, GameDraw = 1, GameContinue = 2
}enu_GameStat_t;

/* APIs */

enu_GameStat_t winCheck();
void gridDraw();
void xoGame();
void getPlayerInput(uint8_t Player);

#endif /* XO_GAME_H_ */
