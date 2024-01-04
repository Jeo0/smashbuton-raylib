#include "raylib.h"
#include "cube.hpp"

/* need to use inline since the camera is of the same object/instance being used on the main function
 * https://stackoverflow.com/questions/4837267/member-function-definition
 * do not do the following as it only just creates a separate instance/object of the camera:
 Camera cameracube = { 0 };
Vector3 cubePositioncube = { 0 };
*/

void UpdateDrawFrame(void)
{
    // Update
    //UpdateCamera(&cameracube, CAMERA_ORBITAL);
    UpdateCamera(&camera, CAMERA_ORBITAL);

    // Draw
    BeginDrawing();

        ClearBackground(RAYWHITE);

        //BeginMode3D(cameracube);
        BeginMode3D(camera);

            //DrawCube(cubePositioncube, 2.0f, 2.0f, 2.0f, RED);
            //DrawCubeWires(cubePositioncube, 2.0f, 2.0f, 2.0f, MAROON);
            DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
            DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
            DrawGrid(10, 1.0f);

        EndMode3D();

        //DrawText("This is a raylib example", 10, 40, 20, DARKGRAY);

        DrawFPS(10, 10);

    EndDrawing();
}
