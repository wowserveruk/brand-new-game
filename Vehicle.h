#pragma once
#include <raylib.h>

class Vehicle {
public:
    Vector2 pos{300,300};
    bool active = false;

    void Update() {
        if (!active) return;
        if (IsKeyDown(KEY_W)) pos.y -= 4;
        if (IsKeyDown(KEY_S)) pos.y += 4;
        if (IsKeyDown(KEY_A)) pos.x -= 4;
        if (IsKeyDown(KEY_D)) pos.x += 4;
    }

    void Draw() {
        if (active) DrawRectangleV(pos, {30,15}, ORANGE);
    }
};
