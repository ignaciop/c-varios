
#include <stdio.h>

#include "raylib.h"
#include "screens.h"

//----------------------------------------------------------------------------------
// Module Variables Definition (local)
//----------------------------------------------------------------------------------
static int framesCounter = 0;
static int finishScreen = 0;



//----------------------------------------------------------------------------------
// Screen Functions Definition
//----------------------------------------------------------------------------------

// Screen Initialization logic
void InitScreen(GameScreen screen) {
    switch (screen) {
    case MENU:
        framesCounter = 0;
        finishScreen = 0;
        
        break;
    case OPTIONS:
        framesCounter = 0;
        finishScreen = 0;
        
        break;
    case GAMEPLAY:
        framesCounter = 0;
        finishScreen = 0;
        
        break;
    case ENDING:
        // TODO: Initialize ENDING screen variables here!
        framesCounter = 0;
        finishScreen = 0;
        
        break;
    default:
        break;
    }
}

// Screen Update logic
void UpdateScreen(GameScreen screen, int *shells) {
    // TODO: Update screen variables here!
    switch (screen) {
    case MENU:
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
        //finishScreen = 1;   // OPTIONS
            finishScreen = 2;   // GAMEPLAY
            PlaySound(bomb);
        }
        
        break;
    case OPTIONS:
        break;
    case GAMEPLAY:
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
            finishScreen = 0;
            PlaySound(water);
            (*shells)--;
        }
        
        break;
    case ENDING:
        // Press enter or tap to return to TITLE screen
        if (IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) {
            finishScreen = 1;
            PlaySound(water);
        }
        
        break;
    default:
        break;
    }


    
}

// Screen Draw logic
void DrawScreen(GameScreen screen, int *shells) {
    // TODO: Draw screen here!
    switch (screen) {
    case MENU:
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), GREEN);
        Vector2 pos = (Vector2){ GetScreenWidth() / 3, GetScreenHeight() / 2};
        DrawTextEx(font, "Frigate", pos, 72, 4, DARKGREEN);
        DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, DARKGREEN);
        
        break;
    case OPTIONS:
        break;
    case GAMEPLAY:
        // TODO: Draw GAMEPLAY screen here!
        ClearBackground(BLACK);
     
        int offsetx = GetScreenWidth() / 10;
        int offsety = GetScreenHeight() / 16;
    
        Vector2 pos2d = (Vector2){0, 0};
     
        for (int i = 0; i < COLS; i++) {
            pos2d = (Vector2){offsetx - 40, offsety + i * cellHeight + cellHeight / 3};
            sprintf(buffer, "%2i", i + 1);
            DrawTextEx(font, buffer, pos2d, 22, 0, WHITE);
        
            pos2d = (Vector2){offsetx + i * cellWidth + cellWidth / 3, offsety - 40};
            
            sprintf(buffer, "%c", i + 'A');
            DrawTextEx(font, buffer, pos2d, 22, 0, WHITE);
        
            for (int j = 0; j < ROWS; j++) {
              
                DrawRectangle(offsetx+i * cellWidth, offsety+j * cellHeight, cellWidth, cellHeight, BLUE);
                //DrawTextEx(font, buffer, pos2d, 20, 0, RAYWHITE);
                pos2d = (Vector2){offsetx+i * cellWidth + cellWidth / 3, offsety+j * cellHeight + cellHeight / 4};
            
                sprintf(buffer, "%c", grid[i + j]);
                DrawTextEx(font, buffer, pos2d, 22, 0, WHITE);
        

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
    
        pos2d = (Vector2){offsetx, offsety * 16 - 80};
        sprintf(buffer, "%d", *shells);
        DrawTextEx(font2, buffer, pos2d, 48, 0, PURPLE);
        
        pos2d = (Vector2){offsetx *10 / 2 - 15, offsety * 16 - 80};
        sprintf(buffer, "B12");
        DrawTextEx(font2, buffer, pos2d, 48, 0, WHITE);
        
        pos2d = (Vector2){offsetx *10 / 2 - 14 - 15, offsety * 16 - 40};
        sprintf(buffer, "is a miss!");
        DrawTextEx(font, buffer, pos2d, 22, 0, GREEN);
    
        pos2d = (Vector2){offsetx, offsety * 16 - 40};
        sprintf(buffer, "%s", "remaining shots");
        DrawTextEx(font, buffer, pos2d, 22, 0, WHITE);
    
        pos2d = (Vector2){offsetx * 8.40, offsety * 16 - 80};
        sprintf(buffer, "%d/%d", 3, 4);
        DrawTextEx(font2, buffer, pos2d, 48, 0, GOLD);
    
        pos2d = (Vector2){offsetx * 7.61, offsety * 16 - 40};
        sprintf(buffer, "%s", "sunken ships");
        DrawTextEx(font, buffer, pos2d, 22, 0, WHITE);
        
        break;
    case ENDING:
        DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), BLUE);

        Vector2 pos3 = (Vector2){ 20, 10 };
        DrawTextEx(font, "ENDING SCREEN", pos3, font.baseSize*3.0f, 4, DARKBLUE);
        DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);
        
        break;
    default:
        break;
    }
    
    
}

// Screen Unload logic
void UnloadScreen(GameScreen screen) {
    // TODO: Unload ENDING screen variables here!
}

// Screen should finish?
int FinishScreen(GameScreen screen) {
    return finishScreen;
}