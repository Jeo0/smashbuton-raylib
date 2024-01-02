#include "globalVariables.h"

int main()
{
    mode.InitializeFirstGameState();
    Image image = LoadImage("textures/instructions.png");     // Loaded in CPU memory (RAM)
    Texture2D texture = LoadTextureFromImage(image);          // Image converted to texture, GPU memory (VRAM)

    bool instructions_shown_at_ready = false;
    
    // Main game loop
    while (!WindowShouldClose())    
    {
        switch(mode.state) 
        {
            case READY: {
                if (IsKeyPressed(KEY_SPACE)) {
                    instructions_shown_at_ready = true;
                }

                if(instructions_shown_at_ready){

                    leftPlayer.Ready_check();
                    rightPlayer.Ready_check();

                    if (leftPlayer.amready && rightPlayer.amready) {
                        leftPlayer.ResetAlpha();
                        rightPlayer.ResetAlpha();

                        leftPlayer.Reset_lkey();
                        rightPlayer.Reset_lkey();
                        mode.state = COOLDOWN;
                    }
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
                    //mode.pause = !mode.pause;       // pause now -> TRUE
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
                    //mode.pause = !mode.pause;           // pause was true, now becomes false
                    mode.state = SHOWDOWN;
                }
            }break;

            case RESULTS: {
                if(leftPlayer.point >= MAXPOINTS)
                    mode.winnerFlag = 'L';
                if (rightPlayer.point >= MAXPOINTS) 
                    mode.winnerFlag = 'R';
                
                if(IsKeyPressed(KEY_ESCAPE)){
                    leftPlayer.ResetHealth();
                    rightPlayer.ResetHealth();

                    leftPlayer.ResetPoints();
                    rightPlayer.ResetPoints();
                    mode.state = COOLDOWN;
                }
            } break;
            default: break;
        }
        //----------------------------------------------------------------------------------
        
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            switch(mode.state) {
                case READY: {
                    
                    float scale = 0.78;
                    if(instructions_shown_at_ready){
                        leftPlayer.Draw_IsReady('L');
                        rightPlayer.Draw_IsReady('R');
                        mode.DrawInstructions(READY);
                    }
                    else{
                        DrawTextureEx(texture, {screenWidth/2 - (texture.width/2 * scale), screenHeight/2 - (texture.height/2 * scale)}, 0, scale, WHITE);
                        // same show
                        mode.DrawInstructions(PAUSE);
                    }
                    
                } break;

                case COOLDOWN: {
                    // TODO: Draw TITLE screen here!
                    mode.DrawPogisijessie();
                    DrawText(TextFormat("%i : %i", leftPlayer.point, rightPlayer.point), GetScreenWidth() / 2, GetScreenHeight() * 0.25, 50, ORANGE);

                } break;
                
                case SHOWDOWN: {
                    mode.DrawShowdown();
                    mode.DrawInstructions(SHOWDOWN);
                } break;

                case PAUSE: {
                    float fontSize = 50;
                    DrawText("paused", 
                        (GetScreenWidth()/2) - (6*fontSize*0.25), 
                        GetScreenHeight()/2, 
                        fontSize, BLACK);

                    mode.DrawShowdown();

                    // draw instructions
                    float scale = 0.78;
                    DrawTextureEx(texture, {screenWidth/2 - (texture.width/2 * scale), screenHeight/2 - (texture.height/2 * scale)}, 0, scale, WHITE);
                    mode.DrawInstructions(PAUSE);
                    
                }break;

                case RESULTS: {
                    // TODO: Draw ENDING screen here!
                    if (mode.winnerFlag == 'L')
                        leftPlayer.DrawResults();
                    else
                        rightPlayer.DrawResults();
                    
                    mode.DrawInstructions(RESULTS);

                } break;
                default: break;
            }
        
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    
    // NOTE: Unload any loaded resources (texture, fonts, audio)
    UnloadImage(image);
    UnloadTexture(texture);

    CloseWindow();              // Close window and OpenGL context
    
    return 0;
}