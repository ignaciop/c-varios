void SetWindowPosition(int x, int y); // Set window position on screen (only PLATFORM_DESKTOP)
int GetScreenWidth(void);             // Get current screen width
int GetScreenHeight(void);            // Get current screen height

bool IsKeyPressed(int key);           // Check if a key has been pressed once
bool IsKeyPressedRepeat(int key);     // Check if a key has been pressed again (Only PLATFORM_DESKTOP)
bool IsKeyDown(int key);              // Check if a key is being pressed
bool IsKeyReleased(int key);          // Check if a key has been released once
bool IsKeyUp(int key);                // Check if a key is NOT being pressed
int GetKeyPressed(void);              // Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty
int GetCharPressed(void);             // Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty
void SetExitKey(int key);             // Set a custom key to exit program (default is ESC)

bool IsMouseButtonPressed(int button);    // Check if a mouse button has been pressed once
bool IsMouseButtonDown(int button);       // Check if a mouse button is being pressed
bool IsMouseButtonReleased(int button);   // Check if a mouse button has been released once
bool IsMouseButtonUp(int button);         // Check if a mouse button is NOT being pressed
int GetMouseX(void);                      // Get mouse position X
int GetMouseY(void);                      // Get mouse position Y
Vector2 GetMousePosition(void);           // Get mouse position XY
Vector2 GetMouseDelta(void);              // Get mouse delta between frames

void DrawRectangle(int posX, int posY, int width, int height, Color color);  // Draw a color-filled rectangle
void DrawRectangleV(Vector2 position, Vector2 size, Color color);            // Draw a color-filled rectangle (Vector version)
void DrawRectangleRec(Rectangle rec, Color color);                           // Draw a color-filled rectangle
void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color);  // Draw a color-filled rectangle with pro parameters

void DrawRectangleLines(int posX, int posY, int width, int height, Color color);    // Draw rectangle outline
void DrawRectangleLinesEx(Rectangle rec, float lineThick, Color color);             // Draw rectangle outline with extended parameters

 bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2);                          // Check collision between two rectangles
bool CheckCollisionPointRec(Vector2 point, Rectangle rec);                         // Check if point is inside rectangle

Font LoadFont(const char *fileName);         // Load font from file into GPU memory (VRAM)
Font LoadFontEx(const char *fileName, int fontSize, int *codepoints, int codepointCount);  // Load font from file with extended parameters, use NULL for codepoints and 0 for codepointCount to load the default character set
void UnloadFont(Font font);                  // Unload font from GPU memory (VRAM)
void DrawText(const char *text, int posX, int posY, int fontSize, Color color);  // Draw text (using default font)
void DrawTextEx(Font font, const char *text, Vector2 position, float fontSize, float spacing, Color tint); // Draw text using font and additional parameters

void InitAudioDevice(void);                          // Initialize audio device and context
void CloseAudioDevice(void);                         // Close the audio device and context
void SetMasterVolume(float volume);                  // Set master volume (listener)
float GetMasterVolume(void);                         // Get master volume (listener)
Sound LoadSound(const char *fileName);               // Load sound from file
void UnloadSound(Sound sound);                       // Unload sound
void PlaySound(Sound sound);                         // Play a sound
void StopSound(Sound sound);                         // Stop playing a sound
void PauseSound(Sound sound);                        // Pause a sound
void ResumeSound(Sound sound);                       // Resume a paused sound
bool IsSoundPlaying(Sound sound);                    // Check if a sound is currently playing
void SetSoundVolume(Sound sound, float volume);      // Set volume for a sound (1.0 is max level)
Music LoadMusicStream(const char *fileName);         // Load music stream from file
void UnloadMusicStream(Music music);                 // Unload music stream
void PlayMusicStream(Music music);                   // Start music playing
void StopMusicStream(Music music);                   // Stop music playing
void PauseMusicStream(Music music);                  // Pause music playing
void ResumeMusicStream(Music music);                 // Resume playing paused music

struct Vector2;                // Vector2, 2 components
struct Rectangle;              // Rectangle, 4 components