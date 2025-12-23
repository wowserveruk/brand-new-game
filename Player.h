#pragma once
#include <raylib.h>
#include "Inventory.h"
class Player{public:Vector2 position{400,300};int cash=500;Inventory inventory;void Update(){if(IsKeyDown(KEY_W))position.y-=2;if(IsKeyDown(KEY_S))position.y+=2;if(IsKeyDown(KEY_A))position.x-=2;if(IsKeyDown(KEY_D))position.x+=2;}void Draw(){DrawRectangleV(position,{20,20},BLUE);}};
