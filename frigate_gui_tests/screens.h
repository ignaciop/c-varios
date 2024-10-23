#ifndef SCREENS_H
#define SCREENS_H

/* Types and Structures Definition */
typedef enum GameScreen {UNKNOWN = -1, MENU, OPTIONS, GAMEPLAY, ENDING} GameScreen;

/* Global Variables Declaration (shared by several modules) */
extern GameScreen currentScreen;
extern Font font;
extern Font font2;
extern Music music;
extern Sound water;
extern Sound bomb;
extern const int ROWS;
extern const int COLS;
extern char buffer[10];

extern char grid[100];
    
extern const int cellWidth;
extern const int cellHeight;

/* Screen Functions Declaration */
void InitScreen(GameScreen screen);
void UpdateScreen(GameScreen screen, int *shells);
void DrawScreen(GameScreen screen, int *shells);
void UnloadScreen(GameScreen screen);
int FinishScreen(GameScreen screen);

#endif