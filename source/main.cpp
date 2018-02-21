#include <string>
#include <cmath>
#include <vector>
#include <random>

#include <3ds.h>
#include <sf2d.h>
#include <sfil.h>
#include <stdio.h>
#include <stdlib.h>

#include "D0_png.h"
#include "D1_png.h"
#include "D2_png.h"
#include "D3_png.h"
#include "D4_png.h"
#include "number0_png.h"
#include "number1_png.h"
#include "number2_png.h"
#include "number3_png.h"
#include "number4_png.h"
#include "number5_png.h"
#include "number6_png.h"
#include "number7_png.h"
#include "number8_png.h"
#include "number9_png.h"

using namespace std;


int main() {
	// Initialize needed services
	sf2d_init();
	hidInit();

	consoleInit(GFX_TOP, NULL);

	// Load Textures
    sf2d_texture* D0 = sfil_load_PNG_buffer(D0_png, SF2D_PLACE_RAM);
    sf2d_texture* D1 = sfil_load_PNG_buffer(D1_png, SF2D_PLACE_RAM);
    sf2d_texture* D2 = sfil_load_PNG_buffer(D2_png, SF2D_PLACE_RAM);
    sf2d_texture* D3 = sfil_load_PNG_buffer(D3_png, SF2D_PLACE_RAM);
    sf2d_texture* D4 = sfil_load_PNG_buffer(D4_png, SF2D_PLACE_RAM);
    sf2d_texture* number0 = sfil_load_PNG_buffer(number0_png, SF2D_PLACE_RAM);
    sf2d_texture* number1 = sfil_load_PNG_buffer(number1_png, SF2D_PLACE_RAM);
    sf2d_texture* number2 = sfil_load_PNG_buffer(number2_png, SF2D_PLACE_RAM);
    sf2d_texture* number3 = sfil_load_PNG_buffer(number3_png, SF2D_PLACE_RAM);
    sf2d_texture* number4 = sfil_load_PNG_buffer(number4_png, SF2D_PLACE_RAM);
    sf2d_texture* number5 = sfil_load_PNG_buffer(number5_png, SF2D_PLACE_RAM);
    sf2d_texture* number6 = sfil_load_PNG_buffer(number6_png, SF2D_PLACE_RAM);
    sf2d_texture* number7 = sfil_load_PNG_buffer(number7_png, SF2D_PLACE_RAM);
    sf2d_texture* number8 = sfil_load_PNG_buffer(number8_png, SF2D_PLACE_RAM);
    sf2d_texture* number9 = sfil_load_PNG_buffer(number9_png, SF2D_PLACE_RAM);
    
    bool display=true;
    
    int level=3;
    int key=0;
    int delay=10;
    int timeWasted=0;
    int ran=0;
    int pressNum=0;
    bool redraw=false;
    bool neww=true;
    bool correct=true;
    
    vector<int> keyCombo,keyComboAnswer;
    default_random_engine engine;
    uniform_int_distribution<int> distributor(1,4);
//    int keyComboAnswer [level]={};
//    int keyCombo [level]={};

        //Center
    int posx = (320 / 2)-100;
    int posy = (240 / 2)-96;

	// Used for what keys were pressed down this frame
	u32 keyDown;
	// Used for what keys were let go this frame
	u32 keyUp;



	// Debug console


	// Main loop
	while (aptMainLoop()) {

        
        sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);

        if(neww){
        if (ran<level){
            if (display) {
                //if(timeWasted==delay){
                printf("%d\n",ran);
                printf("%d\n",level);
                    svcSleepThread(1000000000);
                    key=distributor(engine);
                    printf("Key: %d\n",key);
                    if (key==1) {
                        keyComboAnswer[ran]=1;
                        sf2d_draw_texture(D1, posx, posy);
                    } else if (key==2){
                        keyComboAnswer[ran]=2;
                        sf2d_draw_texture(D2, posx, posy);
                    } else if (key==3){
                        keyComboAnswer[ran]=3;
                        sf2d_draw_texture(D3, posx, posy);
                    } else if (key==4){
                        keyComboAnswer[ran]=4;
                        sf2d_draw_texture(D4, posx, posy);
                    }
                    ran++;
                    timeWasted=0;
                    redraw=true;
//                }
//                else{
//                    //printf("Time Wasted:%d",timeWasted);
//                    timeWasted++;
//                }
            }
        }
        else{
            display=false;
          //  sf2d_swapbuffers();
            if (redraw){
                sf2d_draw_texture(D0, posx, posy);
                redraw=false;
            }
            printf("Blank");
            neww=false;
        }
        }
        
        
        if (display==false) {
            // Refresh what controls are being pressed
            hidScanInput();
            
            // keyDown stores which keys were just pressed as of this frame
            keyDown = hidKeysDown();
            
            // keyUp stores which keys were just released this frame
            keyUp = hidKeysUp();
            
            if (keyDown & KEY_START) {
                // Exit
                break;
            }
            if (pressNum<level+1){
                bool incorrect=true;
                //printf("Key Combo Answer: %d\n",keyComboAnswer[pressNum]);
                if (keyDown) {
                  //  printf("%d\n",pressNum);
                   // printf("KEYDOWN\n%d\n",pressNum);
                 //   printf("%d\n",keyComboAnswer[pressNum]);
                   // printf("%d\n",keyComboAnswer);
                    if (keyDown&KEY_DLEFT) {
                        keyCombo[pressNum]=1;
                        sf2d_draw_texture(D1, posx, posy);
                        pressNum++;
                      //  printf("%d\n",keyCombo);
                        //printf("%d\n",keyComboAnswer);
                        }
                    else if (keyDown&KEY_DUP) {
                        keyCombo[pressNum]=2;
                        sf2d_draw_texture(D2, posx, posy);
                        pressNum++;
                      //  printf("%d\n",keyCombo);
                        //printf("%d\n",keyComboAnswer);
                    }
                    else if (keyDown&KEY_DRIGHT) {
                        keyCombo[pressNum]=3;
                        sf2d_draw_texture(D3, posx, posy);
                        pressNum++;
                      //  printf("%d\n",keyCombo);
                    //    printf("%d\n",keyComboAnswer);
                    }
                    else if (keyDown&KEY_DDOWN) {
                        keyCombo[pressNum]=4;
                        sf2d_draw_texture(D4, posx, posy);
                        pressNum++;
                        //printf("%d\n",keyCombo);
                        //printf("%d\n",keyComboAnswer);
                    }
                }
            }
            else{
               // printf("%d\n",keyComboAnswer.size());
               // printf("%d\n",keyCombo.size());
                for (int j=0; j<keyComboAnswer.size(); j++) {
                  //  printf("%d\n",keyCombo[j]);
                   // printf("%d\n",keyComboAnswer[j]);
                    //printf("\n");
                }
                //printf("\n");
                
                if (keyCombo.size()==keyComboAnswer.size()) {
                    for (int i=0; i<level+1; i++) {
                        if (keyCombo[i]==keyComboAnswer[i]) {
                            //printf("match\n");
                            correct=true;
                        }
                        else{
                            correct=false;
                            break;
                        }
                    }
                }
                else{
                    //printf("no match size\n");
                    correct=false;
                }
                
                
            }
        }
        
        
        if (correct) {
            printf("correct\n");
            level++;
            display=true;
            ran=0;
            keyCombo.clear();
            keyComboAnswer.clear();
            correct=false;
            neww=true;
            pressNum=0;
        }
        sf2d_end_frame();
        
        sf2d_swapbuffers();

	}

    sf2d_free_texture(D0);
    sf2d_free_texture(D1);
    sf2d_free_texture(D2);
    sf2d_free_texture(D3);
    sf2d_free_texture(D4);
    sf2d_free_texture(number0);
    sf2d_free_texture(number1);
    sf2d_free_texture(number2);
    sf2d_free_texture(number3);
    sf2d_free_texture(number4);
    sf2d_free_texture(number5);
    sf2d_free_texture(number6);
    sf2d_free_texture(number7);
    sf2d_free_texture(number8);
    sf2d_free_texture(number9);
	sf2d_fini();

	return 0;
}
