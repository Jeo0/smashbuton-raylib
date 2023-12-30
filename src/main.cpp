#include "globalVariables.h"

int main()
{
    mode.InitializeFirstGameState();
    
    // Main game loop
    while (!WindowShouldClose())    
    {
        switch(mode.state) 
        {
            case READY: {
                mode.state = COOLDOWN;

            } break;
            case COOLDOWN: {
                // Update TITLE screen data here!

                mode.GenerateNew_pogisijessie(); 
                mode.GenerateNew_numbers();

                // for 1.5 seconds
                framesCounter++;
                if(framesCounter >= GetFPS() * 1.5){
                    mode.state = SHOWDOWN;
                    framesCounter = 0;
                }

            } break;
            case SHOWDOWN: { 
                // Update GAMEPLAY screen data here!

                mode.CheckIfPause_and_PauseAccordingly();
                if (!mode.pause)
                {
                    // TODO: Gameplay logic
                    leftPlayer.BindIfKeyPressed();
                    rightPlayer.BindIfKeyPressed();

                    leftPlayer.Register();
                    rightPlayer.Register();
                }

                if(mode.CheckIf_showdownModeDone_andAdd_points()) {
                    leftPlayer.ResetHealth();
                    rightPlayer.ResetHealth();
                    mode.state = COOLDOWN;
                }
                if(mode.CheckIf_onePlayer_reached_5_matchPoints()) mode.state = RESULTS;

            } break;
            // case RESULTS: {
            //     // Update END screen data here!
                
            //     framesCounter++;
                
            //     // LESSON 03: Inputs management (keyboard, mouse)
            //     if (IsKeyPressed(KEY_ENTER)) screen = TITLE;

            // } break;
            default: break;
        }
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            switch(mode.state) {
                case READY: {
                    // TODO: Draw LOGO screen here!
                    // DrawText("LOGO SCREEN", 20, 20, 40, LIGHTGRAY);
                    // DrawText("WAIT for 3 SECONDS...", 290, 220, 20, GRAY);
                } break;
                case COOLDOWN: {
                    // TODO: Draw TITLE screen here!
                    mode.DrawPogisijessie();
                    DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth() / 2, GetScreenHeight() * 0.25, 50, ORANGE);

                } break;
                case SHOWDOWN: {
                    // TODO: Draw GAMEPLAY screen here!
                    DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth() / 2, GetScreenHeight() * 0.25, 50, ORANGE);
                    if (!mode.pause){
                        mode.DrawPogisijessie();
                        leftPlayer.DrawOptions('L');
                        leftPlayer.DrawRegisters('L');
                        leftPlayer.DrawHealth('L');

                        rightPlayer.DrawOptions('R');
                        rightPlayer.DrawRegisters('R');
                        rightPlayer.DrawHealth('R');

                    }
                    else
                        DrawText("paused", screenWidth/2, screenHeight/2, 40, BLACK);
                } break;
                // case RESULTS: {
                //     // TODO: Draw ENDING screen here!
                //     DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                //     DrawText("ENDING SCREEN", 20, 20, 40, DARKBLUE);
                //     DrawText("PRESS ENTER or TAP to RETURN to TITLE SCREEN", 120, 220, 20, DARKBLUE);

                // } break;
                default: break;
            }
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    // NOTE: Unload any loaded resources (texture, fonts, audio)

    CloseWindow();              // Close window and OpenGL context
    
    return 0;
}