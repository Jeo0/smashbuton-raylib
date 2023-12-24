#include "raylib.h"
#include "cube.hpp"

/* need to use inline
 * https://stackoverflow.com/questions/4837267/member-function-definition
inline Camera camera = { 0 };
inline Vector3 cubePosition = { 0 };
*/

const int screenWidth = 800;
const int screenHeight = 480;
//const string what = "what";
//const char what[] = "what";


int main(int asdf, char* pogi[])
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    camera.position = (Vector3){ 10.0f, 10.0f, 8.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    
    SetTargetFPS(60);

	//const char* what = "what";
    while (!WindowShouldClose())
    {
        //BeginDrawing();
        	UpdateDrawFrame();

            //ClearBackground(RAYWHITE);
            //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
            //DrawText(what, screenWidth /2 - MeasureText(what, 32) /2, screenHeight /2 - 32/2, 32, LIGHTGRAY);
			
        //EndDrawing();
    }

    CloseWindow();

    return 0;
}


