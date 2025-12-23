// To fix E1696: cannot open source file "raylib.h"
// 1. Make sure raylib is installed on your system.
// 2. In Visual Studio, go to Project Properties:
//    - C/C++ > General > Additional Include Directories
//      Add the path to raylib's include folder (e.g., C:\raylib\include).
//    - Linker > General > Additional Library Directories
//      Add the path to raylib's lib folder (e.g., C:\raylib\lib).
//    - Linker > Input > Additional Dependencies
//      Add: raylib.lib
// 3. Ensure your #include <raylib.h> line remains in your code.

#include <raylib.h>
#include "Player.h"
#include "Shop.h"
#include "NPC.h"
#include "SaveSystem.h"
#include "InventoryUI.h"
#include "PhoneUI.h"
#include "HeatSystem.h"
#include "Vehicle.h"
#include "GameState.h"

int main() {
    InitWindow(1000, 700, "Contraband Simulator - Full");
    SetTargetFPS(60);

    Player player;
    Shop shop;
    NPC npc({200, 300});
    InventoryUI inventoryUI;
    PhoneUI phone;
    HeatSystem heat;
    Vehicle vehicle;
    GameState state = GameState::WORLD;

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_I)) state = GameState::INVENTORY;
        if (IsKeyPressed(KEY_P)) state = GameState::PHONE;
        if (IsKeyPressed(KEY_ESCAPE)) state = GameState::WORLD;

        if (state == GameState::WORLD) {
            player.Update();
            npc.Update();
            vehicle.Update();
            heat.CoolDown();
        }

        if (IsKeyPressed(KEY_V)) vehicle.active = !vehicle.active;

        BeginDrawing();
        ClearBackground(DARKGRAY);

        if (state == GameState::WORLD) {
            player.Draw();
            npc.Draw();
            vehicle.Draw();
            shop.Draw(player);
        }

        if (state == GameState::INVENTORY) {
            inventoryUI.Draw(player);
        }

        if (state == GameState::PHONE) {
            phone.Draw();
        }

        DrawText(TextFormat("Cash: $%d", player.cash), 10, 10, 20, GREEN);
        DrawText(TextFormat("Heat: %d", heat.heat), 10, 40, 20, RED);

        if (heat.IsPoliceChasing()) {
            DrawText("POLICE CHASING YOU!", 350, 10, 24, RED);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
