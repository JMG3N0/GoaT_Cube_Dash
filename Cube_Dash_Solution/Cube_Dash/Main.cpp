#include "raylib.h"
#include <math.h>
#include <iostream>

struct Pike
{
    Vector2 position;
    float Size;

    Vector2 speed;
    Vector3 collider;
    float rotation;
}pike;

struct Player
{
    Vector2 position;
    Vector2 size;

    int Lives;

    Vector2 Speed;
}player;

static float pikeHeight = 0.0f;
static float gravity = 0.0f;

int main(void)
{
    
    const int screenWidth = 1050;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "Cube Dash / MoonPatrol");

    SetTargetFPS(60);               

    float Baseline = 500;

    // Player-Init
    player.size = Vector2{ 40, 40 };
    player.position = Vector2{ (screenWidth / 2) - (player.size.x / 2) , Baseline - player.size.y / 2 };
    player.Lives = 1;
    player.Speed = Vector2{ 5, 0 };

    //Pike-Init
    pike.position = Vector2{ screenWidth - pike.Size, Baseline + pike.Size };
    pike.Size = 30.f;
    pike.speed = Vector2{ player.Speed.x , 0 };
    pike.collider = Vector3{ pike.position.x, pike.position.y - pikeHeight / 2.0f, 12 };
    pike.rotation = 0;
    pikeHeight = (pike.Size / 2) / tanf(20 * DEG2RAD);


    // Main game loop
    while (!WindowShouldClose())    
    {
        // Update

        //Pike movement right to left
        pike.position.x -= pike.speed.x;
        if (pike.position.x < 0)
        {
            pike.position.x = screenWidth;
        }

        if (IsKeyPressed(KEY_UP))
        {
            player.position.y = player.position.y - 125;
        }
            if (player.position.y < (Baseline - player.size.y/2) )
            {
                player.position.y += 3.5;
            }

        BeginDrawing(); // Draw
        // Draw Pike
        Vector2 v1 = { pike.position.x + sinf(pike.rotation * DEG2RAD) * (pikeHeight), pike.position.y - cosf(pike.rotation * DEG2RAD) * (pikeHeight) };
        Vector2 v2 = { pike.position.x - cosf(pike.rotation * DEG2RAD) * (pike.Size / 2), pike.position.y - sinf(pike.rotation * DEG2RAD) * (pike.Size / 2) };
        Vector2 v3 = { pike.position.x + cosf(pike.rotation * DEG2RAD) * (pike.Size / 2), pike.position.y + sinf(pike.rotation * DEG2RAD) * (pike.Size / 2) };

        DrawRectangle(screenWidth/2 - (player.size.x/2), player.position.y - player.size.y/2, player.size.x, player.size.y, MAROON);
        DrawTriangle(v1, v2, v3, MAROON); // PIKE

        ClearBackground(LIGHTGRAY);

        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Init
    CloseWindow();        

    return 0;
}