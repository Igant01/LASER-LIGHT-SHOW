/**
 * @file laserAudio.h
 * @author Laser Light Snow
 * @brief Audio control
 * @version 0.1
 * @date 2023-04-9
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef LASERAUDIO_H
#define LASERAUDIO_H


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

AudioPlaySdWav           playSdWav1;     //xy=221,236
AudioMixer4              mixer2;         //xy=472,154
AudioMixer4              mixer3;         //xy=472,292
AudioMixer4              mixer1;         //xy=473,82
AudioMixer4              mixer4;         //xy=474,370
AudioOutputI2S2          i2s2_1;         //xy=688,337
AudioOutputPT8211        pt8211_1;       //xy=689,122
AudioConnection          patchCord1(playSdWav1, 0, mixer1, 0);
AudioConnection          patchCord2(playSdWav1, 0, mixer3, 0);
AudioConnection          patchCord3(playSdWav1, 1, mixer2, 0);
AudioConnection          patchCord4(playSdWav1, 1, mixer4, 0);
AudioConnection          patchCord5(mixer2, 0, pt8211_1, 1);
AudioConnection          patchCord6(mixer3, 0, i2s2_1, 0);
AudioConnection          patchCord7(mixer1, 0, pt8211_1, 0);
AudioConnection          patchCord8(mixer4, 0, i2s2_1, 1);

class laserAudio
{

private:

    int output; //internal or external audio
    float volume; //0 through 1

public:

    void changeVolume(float newvolume);

    void playFile(const char*fileName);

    void enable();

    void disable();

    laserAudio();

    laserAudio(int audioOutput);

};

#endif