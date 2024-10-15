#include <stdio.h>

#include "raylib.h"
#include "screens.h"    // NOTE: Declares global (extern) variables and screens functions

//----------------------------------------------------------------------------------
// Shared Variables Definition (global)
// NOTE: Those variables are shared between modules through screens.h
//----------------------------------------------------------------------------------
GameScreen currentScreen = MENU;
Font font = {0};
Font font2 = {0};
Music music = { 0 };
Sound fxCoin = { 0 };

const int ROWS = 20;
const int COLS = 20;
char buffer[10];
    
//----------------------------------------------------------------------------------
// Local Variables Definition (local to this module)
//----------------------------------------------------------------------------------
static const int screenHeight = 800;
static const int screenWidth = 800;

const int cellWidth = screenWidth / (ROWS * 1.2);
const int cellHeight = screenHeight / (COLS * 1.2);

// Required variables to manage screen transitions (fade-in, fade-out)
static float transAlpha = 0.0f;
static bool onTransition = false;
static bool transFadeOut = false;
static int transFromScreen = -1;
static GameScreen transToScreen = UNKNOWN;

//----------------------------------------------------------------------------------
// Local Functions Declaration
//----------------------------------------------------------------------------------
static void ChangeToScreen(int screen);     // Change to screen, no transition effect

static void TransitionToScreen(int screen); // Request transition to next screen
static void UpdateTransition(void);         // Update transition effect
static void DrawTransition(void);           // Draw transition effect (full-screen rectangle)

static void UpdateDrawFrame(void);          // Update and draw one frame

//----------------------------------------------------------------------------------
// Main entry point
//----------------------------------------------------------------------------------
int main(void) {
    // Initialization
    //---------------------------------------------------------
    InitWindow(screenWidth, screenHeight, "frigate gui tests");

    InitAudioDevice();      // Initialize audio device

    // Load global data (assets that must be available in all screens, i.e. font)
    font = LoadFontEx("resources/Iosevka-ExtendedSemiBold.ttf", 22, NULL, 0);
    font2 = LoadFontEx("resources/Iosevka-ExtendedSemiBold.ttf", 48, NULL, 0);
    music = LoadMusicStream("resources/ambient.ogg");
    fxCoin = LoadSound("resources/coin.wav");

    SetMusicVolume(music, 0.1f);
    PlayMusicStream(music);

    // Setup and init first screen
    currentScreen = MENU;
    InitScreen(currentScreen);

    SetTargetFPS(60);       // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose()) {    
        // Detect window close button or ESC key
        SetExitKey(KEY_NULL);
        
        UpdateDrawFrame();
    }


    // De-Initialization
    //--------------------------------------------------------------------------------------
    // Unload current screen data before closing
   UnloadScreen(currentScreen); 

   // Unload global data loaded
   UnloadFont(font);
   UnloadFont(font2);
   UnloadMusicStream(music);
   UnloadSound(fxCoin);

   CloseAudioDevice();     // Close audio context

   CloseWindow();          // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

//----------------------------------------------------------------------------------
// Module specific Functions Definition
//----------------------------------------------------------------------------------
// Change to next screen, no transition
static void ChangeToScreen(GameScreen screen) {
    // Unload current screen
   UnloadScreen(currentScreen);

    // Init next screen
   InitScreen(screen);

   currentScreen = screen;
}

// Request transition to next screen
static void TransitionToScreen(GameScreen screen) {
    onTransition = true;
    transFadeOut = false;
    transFromScreen = currentScreen;
    transToScreen = screen;
    transAlpha = 0.0f;
}

// Update transition effect (fade-in, fade-out)
static void UpdateTransition(void) {
    if (!transFadeOut) {
        transAlpha += 0.05f;

        // NOTE: Due to float internal representation, condition jumps on 1.0f instead of 1.05f
        // For that reason we compare against 1.01f, to avoid last frame loading stop
        if (transAlpha > 1.01f) {
            transAlpha = 1.0f;

            // Unload current screen
            UnloadScreen(transFromScreen);
               

            // Load next screen
           InitScreen(transToScreen);

           currentScreen = transToScreen;

           // Activate fade out effect to next loaded screen
           transFadeOut = true;
        }
    } else {  // Transition fade out logic
        transAlpha -= 0.02f;

        if (transAlpha < -0.01f) {
            transAlpha = 0.0f;
            transFadeOut = false;
            onTransition = false;
            transFromScreen = -1;
            transToScreen = UNKNOWN;
        }
    }
}

// Draw transition effect (full-screen rectangle)
static void DrawTransition(void) {
    DrawRectangle(0, 0, GetScreenWidth(), GetScreenHeight(), Fade(BLACK, transAlpha));
}

// Update and draw game frame
static void UpdateDrawFrame(void) {
    // Update
    //----------------------------------------------------------------------------------
    UpdateMusicStream(music);       // NOTE: Music keeps playing between screens

    if (!onTransition) {
        UpdateScreen(currentScreen);
        
        switch(currentScreen) {
            case MENU:
            {


                if (FinishScreen(currentScreen)) TransitionToScreen(GAMEPLAY);

            } break;
            case OPTIONS:
            {


                if (FinishScreen(currentScreen)) TransitionToScreen(MENU);

            } break;
            case GAMEPLAY:
            {

                if (FinishScreen(currentScreen) == 1) TransitionToScreen(ENDING);
                //else if (FinishGameplayScreen() == 2) TransitionToScreen(TITLE);

            } break;
            case ENDING:
            {

                if (FinishScreen(currentScreen) == 1) TransitionToScreen(MENU);

            } break;
            default: break;
        }
    }
    else UpdateTransition();    // Update transition (fade-in, fade-out)
    //----------------------------------------------------------------------------------

    // Draw
    //----------------------------------------------------------------------------------
    BeginDrawing();

        ClearBackground(RAYWHITE);



        DrawScreen(currentScreen);

        // Draw full screen rectangle in front of everything
        if (onTransition) DrawTransition();

        //DrawFPS(10, 10);

    EndDrawing();
    //----------------------------------------------------------------------------------
}