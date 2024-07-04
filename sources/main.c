#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000
#define WINDOW_TITLE "ani3D Engine"
#define TARGET_FPS 120


#include <stdio.h>
#include "raylib.h"

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);

    Camera3D cam;
    cam.position = (Vector3){10.0f,10.0f,10.0f};
    cam.target = (Vector3){0.0f,0.0f,0.0f};
    cam.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    cam.fovy = 45.0f;
    cam.projection = CAMERA_PERSPECTIVE;

    Vector3 cubePosition = { 0.0f, 0.0f, 0.0f };

    //This moves the camera relative to cursor.
    //if this is not enabled, then you get really erratic behavior because
    //it will use the number of pixels your cursor travelled as a value instead
    //DisableCursor();
    while (!WindowShouldClose())
    {
        UpdateCamera(&cam, CAMERA_ORBITAL);


        BeginDrawing();
        ClearBackground(RAYWHITE);

        //Being Drawing CAM
        BeginMode3D(cam);

        DrawSphere(cubePosition, 5.0f, (Color) {100,100,100,255});
        DrawGrid(10, 1.0f);

        //END Cam drawing
        EndMode3D();

        //UI Start (if you want)

        EndDrawing();
    }
    return 0;
}
