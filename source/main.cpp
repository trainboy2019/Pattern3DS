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
#include "D5_png.h"
#include "start_png.h"
#include "stop_png.h"

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
    sf2d_texture* D5 = sfil_load_PNG_buffer(D5_png, SF2D_PLACE_RAM);
    sf2d_texture* start = sfil_load_PNG_buffer(start_png, SF2D_PLACE_RAM);
    sf2d_texture* stop = sfil_load_PNG_buffer(stop_png, SF2D_PLACE_RAM);
    
    bool display=true;
    
    int level=3;
    int key=0;
    int ran=0;
    int pressNum=0;
    bool redraw=false;
    bool neww=true;
    bool correct=true;
    bool finishedCheck=false;
    bool debug=false;
    
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
    // Used for what keys were held down this frame
    u32 keyHeld;



	// Debug console


	// Main loop
	while (aptMainLoop()) {

        
        sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);

        if(neww){
        if (ran<level){
            if (display) {
                if(debug){
                printf("Ran: %d\n",ran);
                printf("Level: %d\n",level);
                }
                    key=distributor(engine);
                if(debug){
                    printf("Key: %d\n",key);
                }
                    if (key==1) {
                        keyComboAnswer.push_back(1);
                        sf2d_draw_texture(D0, posx, posy);
                        sf2d_draw_texture(stop, 8, 8);
                        svcSleepThread(500000000);
                        sf2d_end_frame();
                        sf2d_swapbuffers();
                        sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
                        sf2d_draw_texture(D1, posx, posy);
                        sf2d_draw_texture(stop, 8, 8);
                        svcSleepThread(1000000000);
                    } else if (key==2){
                        keyComboAnswer.push_back(2);
                        sf2d_draw_texture(D0, posx, posy);
                        sf2d_draw_texture(stop, 8, 8);
                        svcSleepThread(500000000);
                        sf2d_end_frame();
                        sf2d_swapbuffers();
                        sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
                        sf2d_draw_texture(D2, posx, posy);
                        sf2d_draw_texture(stop, 8, 8);
                        svcSleepThread(1000000000);
                    } else if (key==3){
                        keyComboAnswer.push_back(3);
                        sf2d_draw_texture(D0, posx, posy);
                        sf2d_draw_texture(stop, 8, 8);
                        svcSleepThread(500000000);
                        sf2d_end_frame();
                        sf2d_swapbuffers();
                        sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
                        sf2d_draw_texture(D3, posx, posy);
                        sf2d_draw_texture(stop, 8, 8);
                        svcSleepThread(1000000000);
                    } else if (key==4){
                        keyComboAnswer.push_back(4);
                        sf2d_draw_texture(D0, posx, posy);
                        sf2d_draw_texture(stop, 8, 8);
                        svcSleepThread(500000000);
                        sf2d_end_frame();
                        sf2d_swapbuffers();
                        sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
                        sf2d_draw_texture(D4, posx, posy);
                        sf2d_draw_texture(stop, 8, 8);
                        svcSleepThread(1000000000);
                    }
                    ran++;
                    redraw=true;
            }
        }
        else{
            display=false;
            if (redraw){
                sf2d_draw_texture(D0, posx, posy);
                sf2d_draw_texture(stop, 8, 8);
                svcSleepThread(500000000);
                sf2d_end_frame();
                sf2d_swapbuffers();
                sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
                redraw=false;
            }
            
            if(debug){
            printf("Blank\n");
            }
            neww=false;
        }
        }
        
        
        
        if (display==false) {
            // Refresh what controls are being pressed
            hidScanInput();
            
            // keyDown stores which keys were just pressed as of this frame
            keyDown = hidKeysDown();
            
            // keyHeld stores which keys were held this frame
            keyHeld = hidKeysHeld();
            
            if (keyDown & KEY_START) {
                // Exit
                break;
            }
            if (pressNum<level){
                //printf("Key Combo Answer: %d\n",keyComboAnswer[pressNum]);
                if (keyDown) {
                    //  printf("%d\n",pressNum);
                    // printf("KEYDOWN\n%d\n",pressNum);
                    //   printf("%d\n",keyComboAnswer[pressNum]);
                    // printf("%d\n",keyComboAnswer);
                    if (keyDown&KEY_DLEFT) {
                        keyCombo.push_back(1);
                        sf2d_draw_texture(D1, posx, posy);
                        sf2d_draw_texture(start, 8, 8);
                        pressNum++;
                        //  printf("%d\n",keyCombo);
                        //printf("%d\n",keyComboAnswer);
                    }
                    else if (keyDown&KEY_DUP) {
                        keyCombo.push_back(2);
                        sf2d_draw_texture(D2, posx, posy);
                        sf2d_draw_texture(start, 8, 8);
                        pressNum++;
                        //  printf("%d\n",keyCombo);
                        //printf("%d\n",keyComboAnswer);
                    }
                    else if (keyDown&KEY_DRIGHT) {
                        keyCombo.push_back(3);
                        sf2d_draw_texture(D3, posx, posy);
                        sf2d_draw_texture(start, 8, 8);
                        pressNum++;
                        //  printf("%d\n",keyCombo);
                        //    printf("%d\n",keyComboAnswer);
                    }
                    else if (keyDown&KEY_DDOWN) {
                        keyCombo.push_back(4);
                        sf2d_draw_texture(D4, posx, posy);
                        sf2d_draw_texture(start, 8, 8);
                        pressNum++;
                        //printf("%d\n",keyCombo);
                        //printf("%d\n",keyComboAnswer);
                    }
                }
                else if (keyHeld) {
                    if (keyHeld&KEY_DLEFT) {
                        sf2d_draw_texture(D1, posx, posy);
                        sf2d_draw_texture(start, 8, 8);
                    }
                    else if (keyHeld&KEY_DUP) {
                        sf2d_draw_texture(D2, posx, posy);
                        sf2d_draw_texture(start, 8, 8);
                    }
                    else if (keyHeld&KEY_DRIGHT) {
                        sf2d_draw_texture(D3, posx, posy);
                        sf2d_draw_texture(start, 8, 8);
                    }
                    else if (keyHeld&KEY_DDOWN) {
                        sf2d_draw_texture(D4, posx, posy);
                        sf2d_draw_texture(start, 8, 8);
                    }
                }
                else{
                    
                    sf2d_draw_texture(D0, posx, posy);
                    sf2d_draw_texture(start, 8, 8);
                    svcSleepThread(500000);
                }
            }
            else{
                
                if (keyCombo.size()==keyComboAnswer.size()) {
                    for (int i=0; i<level; i++) {
                        
                        if(debug){
                        printf("Answer: %d\n",keyComboAnswer.at(i));
                        printf("User  : %d\n",keyCombo.at(i));
                        }
                        if (keyCombo.at(i)==keyComboAnswer.at(i)) {
                            
                            if(debug){
                            printf("Yup\n");
                            }
                            correct=true;
                        }
                        else{
                            if(debug){
                            printf("Nope\n");
                            }
                            correct=false;
                        }
                        
                        if(debug){
                        printf("NextFor\n");
                        }
                    }
                    
                    if(debug){
                    printf("Checked\n");
                    }
                    finishedCheck=true;
                    
                }
                else{
                    if(debug){
                    printf("no match size\n");
                    }
                    correct=false;
                    finishedCheck=true;
                }
                
                
            }
        }
        
        
        if (finishedCheck) {
            if(debug){
            printf("CheckStart\n");
            }
            if (correct) {
                if(debug){
                printf("correct\n");
                }level++;
                display=true;
                ran=0;
                if(debug){
                for (int t=0; t<keyCombo.size(); t++) {
                    printf("User:   %d\n",keyCombo.at(t));
                }
                for (int u=0; u<keyComboAnswer.size(); u++) {
                    printf("Answer: %d\n",keyComboAnswer.at(u));
                }
                printf("\n");
                }
                keyCombo.clear();
                keyComboAnswer.clear();
                if(debug){
                for (int t=0; t<keyCombo.size(); t++) {
                    printf("User:   %d\n",keyCombo.at(t));
                }
                for (int u=0; u<keyComboAnswer.size(); u++) {
                    printf("Answer: %d\n",keyComboAnswer.at(u));
                }
                }
                correct=false;
                neww=true;
                pressNum=0;
                finishedCheck=false;
            }
            else{
                sf2d_end_frame();
                sf2d_swapbuffers();
                sf2d_start_frame(GFX_BOTTOM, GFX_LEFT);
                sf2d_draw_texture(D5, posx, posy);
                svcSleepThread(1000000000);
                if(debug){
                printf("incorrect\n");
                for (int t=0; t<keyCombo.size(); t++) {
                    printf("User:   %d\n",keyCombo.at(t));
                }
                for (int u=0; u<keyComboAnswer.size(); u++) {
                    printf("Answer: %d\n",keyComboAnswer.at(u));
                }
                }
                break;
            }
        }
        sf2d_end_frame();
        
        sf2d_swapbuffers();

	}

    sf2d_free_texture(D0);
    sf2d_free_texture(D1);
    sf2d_free_texture(D2);
    sf2d_free_texture(D3);
    sf2d_free_texture(D4);
    sf2d_free_texture(D5);
    sf2d_free_texture(start);
    sf2d_free_texture(stop);
	sf2d_fini();

	return 0;
}
