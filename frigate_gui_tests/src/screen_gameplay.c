/**********************************************************************************************
*
*   raylib - Advance Game template
*
*   Gameplay Screen Functions Definitions (Init, Update, Draw, Unload)
*
*   Copyright (c) 2014-2022 Ramon Santamaria (@raysan5)
*
*   This software is provided "as-is", without any express or implied warranty. In no event
*   will the authors be held liable for any damages arising from the use of this software.
*
*   Permission is granted to anyone to use this software for any purpose, including commercial
*   applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*     1. The origin of this software must not be misrepresented; you must not claim that you
*     wrote the original software. If you use this software in a product, an acknowledgment
*     in the product documentation would be appreciated but is not required.
*
*     2. Altered source versions must be plainly marked as such, and must not be misrepresented
*     as being the original software.
*
*     3. This notice may not be removed or altered from any source distribution.
*
**********************************************************************************************/

#include "raylib.h"
#include "screens.h"

#include <stdio.h>

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;

//----------------------------------------------------------------------------------
// Gameplay Screen Functions Definition
//----------------------------------------------------------------------------------

// Gameplay Screen Initialization logic
void InitGameplayScreen(void)
{
    // TODO: Initialize GAMEPLAY screen variables here!
    framesCounter = 0;
    finishScreen = 0;
}

// Gameplay Screen Update logic
void UpdateGameplayScreen(void)
{
    // TODO: Update GAMEPLAY screen variables here!

    // Press enter or tap to change to ENDING screen
    if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
    {
        finishScreen = 1;
        PlaySound(fxCoin);
    }
}

// Gameplay Screen Draw logic
void DrawGameplayScreen(void)
{
    // TODO: Draw GAMEPLAY screen here!
    ClearBackground(BLACK);
     
    int offsetx = GetScreenWidth() / 10;
    int offsety = GetScreenHeight() / 16;
    
    Vector2 pos2d = (Vector2){0, 0};
     
    for (int i = 0; i < COLS; i++) {
        pos2d = (Vector2){offsetx - 40, offsety + i * cellHeight};
        sprintf(buffer, "%2i", i + 1);
        DrawTextEx(font, buffer, pos2d, 22, 0, WHITE);
        
        pos2d = (Vector2){offsetx + i * cellWidth, offsety - 40};
            
        sprintf(buffer, "%c", i + 'A');
        DrawTextEx(font, buffer, pos2d, 22, 0, WHITE);
        
        for (int j = 0; j < ROWS; j++) {
              
            DrawRectangle(offsetx+i * cellWidth, offsety+j * cellHeight, cellWidth, cellHeight, BLUE);
            //DrawTextEx(font, buffer, pos2d, 20, 0, RAYWHITE);
            
        

            /*
            Vector2 mPos = GetMousePosition();
            int indexI = mPos.x / cellWidth;
            int indexJ = mPos.y / cellHeight;
            
            sprintf(buffer, "x = %i, y = %i", indexI, indexJ);
            DrawTextEx(font, buffer, (Vector2){mPos.x + 5, mPos.y + 15}, 22, 0, BLACK);
            */
            
            DrawRectangleLines(offsetx+i * cellWidth, offsety+j * cellHeight, cellWidth, cellHeight, DARKBLUE);
        }
    }
    
    pos2d = (Vector2){offsetx * 12 / 4, offsety * 16 - 80};
    sprintf(buffer, "%d", 200);
    DrawTextEx(font2, buffer, pos2d, 48, 0, PURPLE);
    
    pos2d = (Vector2){offsetx * 12 / 4, offsety * 16 - 40};
    sprintf(buffer, "%s", "remaining shots");
    DrawTextEx(font, buffer, pos2d, 22, 0, WHITE);
    
    pos2d = (Vector2){offsetx * 12 / 4 + 250, offsety * 16 - 80};
    sprintf(buffer, "%d/%d", 3, 4);
    DrawTextEx(font2, buffer, pos2d, 48, 0, GREEN);
    
    pos2d = (Vector2){offsetx * 12 / 4 + 250, offsety * 16 - 40};
    sprintf(buffer, "%s", "sunken ships");
    DrawTextEx(font, buffer, pos2d, 22, 0, WHITE);
    
}

// Gameplay Screen Unload logic
void UnloadGameplayScreen(void)
{
    // TODO: Unload GAMEPLAY screen variables here!
}

// Gameplay Screen should finish?
int FinishGameplayScreen(void)
{
    return finishScreen;
}