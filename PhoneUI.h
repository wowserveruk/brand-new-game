#pragma once
// Ensure raylib.h is found by providing the correct relative or absolute path.
// If raylib is installed system-wide, use <raylib.h>.
// If raylib is in a local directory, use "raylib.h" and adjust include directories in your project settings.
#include <raylib.h> // If this fails, try: #include "raylib.h"

// If you still get E1696, add raylib's include directory to your project's include paths:
// In Visual Studio: Project Properties > C/C++ > General > Additional Include Directories
// Example: C:\raylib\src or wherever raylib.h is located

class PhoneUI {
public:
    void Draw() {
        DrawRectangle(600, 50, 180, 500, BLACK);
        DrawText("PHONE", 650, 60, 20, GREEN);
        DrawText("Contacts", 620, 120, 16, WHITE);
        DrawText("Map", 620, 160, 16, WHITE);
        DrawText("Quests", 620, 200, 16, WHITE);
    }
};
