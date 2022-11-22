#include "raylib.h"
#include <math.h>
#include <iostream>

//struct Pike
//{
//    Vector2 position;
//    float Size;
//
//    Vector2 speed;
//    Vector3 collider;
//    float rotation;
//}pike;

struct Player
{
    Vector2 position;
    Vector2 size;

    int Lives;
    bool Jump = false;
    int timer = 0;
    bool Negtimer = false;
    

    Vector2 Speed;
}player;



int main(void)
{

    const int screenWidth = 1050;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "Cube Dash / MoonPatrol");

    SetTargetFPS(60);

    float Baseline = 500;

    Texture2D pike = LoadTexture("resources/pike.png");


    // Player-Init
    player.size = Vector2{ 40, 40 };
    player.position = Vector2{ (screenWidth / 2) - (player.size.x / 2) , Baseline - player.size.y / 2 };
    player.Lives = 1;
    player.Speed = Vector2{ 5, 0 };

    Rectangle ColRec = {(screenWidth-pike.width), (Baseline+pike.height), pike.height, pike.width};

    Rectangle sourceRec = { 0.0f, 0.0f, pike.width , pike.height };
    Rectangle destRec = { screenWidth, Baseline , pike.width * 400.0f, pike.height * 400.0f };
    Vector2 origin = { (float)pike.width, (float)pike.height };

    // Main game loop
    while (!WindowShouldClose())    
    {
        // Update

        //Pike movement right to left
        ColRec.x -= 5;
        if (ColRec.x < 0)
        {
            ColRec.x = screenWidth;
        }

        if (IsKeyPressed(KEY_UP) && player.Jump == false)
        {
            player.timer = 10;
            player.Jump = true;
        }

        if (player.Jump == true)
        {
            if (player.Negtimer == false)
            {
                if (player.timer >= 0)
                {
                    player.position.y -= 12;
                    player.timer--;
                }
                if (player.timer == 0)
                {
                    player.Negtimer = true;
                    player.timer = 10;
                }
            }

            if (player.Negtimer == true)
            {
                if (player.timer >= 0)
                {
                    player.position.y += 12;
                    player.timer--;
                }
                if (player.timer == 0)
                {
                    player.Negtimer = false;
                    player.timer = 0;
                    player.Jump = false;
                }
            }

        }


        BeginDrawing(); // Draw

        DrawRectangle(screenWidth/2 - (player.size.x/2), player.position.y - player.size.y/2, player.size.x, player.size.y, MAROON);
        DrawTexturePro(pike,sourceRec, destRec, origin, 0.0f, WHITE);

        ClearBackground(LIGHTGRAY);

        DrawText(TextFormat("Lives: %i", player.Lives), 190, 600, 20, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Init
    CloseWindow();        

    return 0;
}