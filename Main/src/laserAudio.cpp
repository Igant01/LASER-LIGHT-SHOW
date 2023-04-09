/**
 * @file laserAudio.h
 * @author Laser Light Snow
 * @brief laserAudio control
 * @version 0.1
 * @date 2023-04-9
 *
 * @copyright Copyright (c) 2023
 *
 */



#include "laserAudio.h"

laserAudio::laserAudio(){
    volume = 0.5; //half volume
    output = 0;   //on board default
}

laserAudio::laserAudio(int laserAudioOutput)
{
    output = laserAudioOutput; //0 is on board 1 is external
    volume = 0.5;
    if(output == 0){
        mixer1.gain(0,0);// turn off 
        mixer2.gain(0,0);
    }
    if(output == 1){
        mixer3.gain(0,0);// turn off
        mixer4.gain(0,0);
    }
}

void laserAudio::changeVolume(float newVolume){
    if(output == 0){
        mixer3.gain(0,newVolume);
        mixer4.gain(0,newVolume);
    }
    if(output == 1){
        mixer1.gain(0,newVolume);
        mixer2.gain(0,newVolume);
    }
}

void laserAudio::playFile(const char*fileName){
    playSdWav1.play(fileName);
}

void laserAudio::enable(){
    if(output == 0){
        mixer3.gain(0,volume);
        mixer4.gain(0,volume);
    }
    if(output == 1){
        mixer1.gain(0,volume);
        mixer2.gain(0,volume);
    }
}

void laserAudio::disable(){
    if(output == 0){
        mixer3.gain(0,0);
        mixer4.gain(0,0);
    }
    if(output == 1){
        mixer1.gain(0,0);
        mixer2.gain(0,0);
    }
}