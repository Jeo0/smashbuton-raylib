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
                leftPlayer.Ready_check();
                rightPlayer.Ready_check();
                
                if(leftPlayer.amready && rightPlayer.amready){
                    leftPlayer.ResetAlpha();
                    rightPlayer.ResetAlpha(); 

                    leftPlayer.Reset_lkey();
                    rightPlayer.Reset_lkey();
                    mode.state = COOLDOWN;
                }

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
                if(IsKeyPressed(KEY_SPACE)){
                    mode.pause = !mode.pause;
                    mode.state = PAUSE;
                }
                else {
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
                if(mode.CheckIf_onePlayer_reached_5_matchPoints()) 
                    mode.state = RESULTS;

            } break;

            case PAUSE: {
                if(IsKeyPressed(KEY_SPACE)){
                    mode.pause = !mode.pause;
                    mode.state = SHOWDOWN;
                }
            }

            // case RESULTS: {
                // Update END screen data here!
                
            //} break;
            default: break;
        }
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            switch(mode.state) {
                case READY: {
                    leftPlayer.Draw_IsReady('L');
                    rightPlayer.Draw_IsReady('R');
                } break;

                case COOLDOWN: {
                    // TODO: Draw TITLE screen here!
                    mode.DrawPogisijessie();
                    DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth() / 2, GetScreenHeight() * 0.25, 50, ORANGE);

                } break;
                
                case SHOWDOWN: {
                    DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth() / 2, GetScreenHeight() * 0.25, 50, ORANGE);
                    mode.DrawPogisijessie();
                    leftPlayer.DrawOptions('L');
                    leftPlayer.DrawRegisters('L');
                    leftPlayer.DrawHealth('L');
                    leftPlayer.DrawAnimateRegisters('L');

                    rightPlayer.DrawOptions('R');
                    rightPlayer.DrawRegisters('R');
                    rightPlayer.DrawHealth('R');

                    
                } break;
                case PAUSE: {
                    float fontSize = 50;
                    DrawText("paused", 
                        (GetScreenWidth()/2) - (6*fontSize*0.25), 
                        GetScreenHeight()/2, 
                        fontSize, BLACK);
                }break;

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