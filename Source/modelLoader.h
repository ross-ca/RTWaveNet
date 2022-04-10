/*
  ==============================================================================

    modelLoader.h
    Created: 8 Apr 2022 5:37:27pm
    Author:  Ross Castledine

  ==============================================================================
*/

#pragma once
#include <string>
#include <vector>
#include "WaveNet.h"

using namespace std;

class modelLoader{
public:
    void loadModel();
    WaveNet createRealTimeModel();
    
private:
    string jsonFilePath = "/Users/ross/Documents/University/Project/Real-Time Implementation/RTWaveNet/Source/modelJSON.json";
    int numChannels;
    int inputChannels;
    int outputChannels;
    string activation;
    int filterWidth;
    vector<int> dilations;
};
