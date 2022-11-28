#include "raylib.h"
int menu()
{
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "Menu");



    Rectangle Play = { 100, 200, 200, 80 };
    Rectangle Credits = { 100, 400, 200, 80 };
    Rectangle Exit = { 100, 600, 200, 80 };

    Vector2 mousePosition = { 0 };

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        mousePosition = GetMousePosition();

        if (CheckCollisionPointRec(mousePosition, Play))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                return 0;

            }
        }
        if (CheckCollisionPointRec(mousePosition, Credits))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                return 1;

            }
        }
        if (CheckCollisionPointRec(mousePosition, Exit))
        {
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                return 2;

            }
        }


        BeginDrawing();

        ClearBackground(GRAY);

        DrawRectangleRec(Play, RED);
        DrawText("Play", 120, 215, 50, WHITE);
        DrawRectangleRec(Credits, RED);
        DrawRectangleRec(Exit, RED);
        EndDrawing();
    }
}