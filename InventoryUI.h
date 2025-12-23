#pragma once
#include <raylib.h>
#include "Player.h"

class InventoryUI {
public:
    void Draw(Player& p) {
        DrawRectangle(50, 50, 300, 400, BLACK);
        DrawText("Inventory", 140, 60, 20, GREEN);

        int y = 100;
        for (auto& i : p.inventory.items) {
            DrawText(TextFormat("%s x%d", i.first.c_str(), i.second), 70, y, 18, WHITE);
            y += 24;
        }
    }
};
