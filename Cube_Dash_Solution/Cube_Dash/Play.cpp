#include "raylib.h"

#include <iostream>



struct Player
{
    Vector2 position;
    Vector2 size;

    int Lives;
    bool Jump = false;
    int timer = 0;
    bool Negtimer = false;



}player;



int Play(void)
{

    const int screenWidth = 1050;
    const int screenHeight = 650;

    InitWindow(screenWidth, screenHeight, "Cube Dash / MoonPatrol");

    SetTargetFPS(60);

    float Baseline = 500;

    // Texture2D pike = LoadTexture("resources/pike.png");


     // Player-Init
    
    player.size = Vector2{ 40, 40 };
    player.position = Vector2{ (screenWidth / 2) - (player.size.x / 2) , Baseline - player.size.y / 2 };
    player.Lives = 3;
   


    Rectangle ColRec = { screenWidth - 20, Baseline - 80, 20, 80 };


    // Main game loop
    while (!WindowShouldClose())
    {
        // Update

        //Pike movement right to left
        ColRec.x -= 12;
        if (ColRec.x <= 0)
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

        //if (CheckCollisionRecs(, ObstacleRectangle) == true)
        //{
        //    CubePlayer.x = ;
        //    CubePlayer.y = InitialPosPla[1];
        //    ObstacleRectangle.x = InitialPosObs[0];
        //    ObstacleRectangle.y = InitialPosObs[1];
        //    
        //    if (player.Lives > 0)
        //    {
        //        player.Lives--;
        //    }
        //}
        //if (player.Lives == 0)
        //{
        //    CloseWindow();
        //}


        BeginDrawing(); // Draw
        DrawRectangleRec(ColRec, PURPLE);
        DrawRectangle(screenWidth / 2 - (player.size.x / 2), player.position.y - player.size.y / 2, player.size.x, player.size.y, MAROON);




        ClearBackground(LIGHTGRAY);

        DrawText(TextFormat("Lives: %i", player.Lives), 190, 600, 20, RED);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Init
    CloseWindow();

    return 0;
}