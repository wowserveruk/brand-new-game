#pragma once
#include <raylib.h>
class NPC{public:Vector2 pos,dir;NPC(Vector2 p):pos(p),dir{1,0}{}void Update(){pos.x+=dir.x;if(pos.x>760||pos.x<40)dir.x*=-1;}void Draw(){DrawCircleV(pos,8,RED);}};
