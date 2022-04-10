/*
  ==============================================================================

    jsonLoader.h
    Created: 8 Apr 2022 5:37:27pm
    Author:  Ross Castledine

  ==============================================================================
*/

#pragma once
#include <string>
#include <vector>
using namespace std;

class jsonLoader{
public:
    void loadModel();
    int numChannels;
    int inputChannels;
    int outputChannels;
    string activation;
    int filterWidth;
    std::vector<int> dilations;
    
private:
    string jsonFilePath = "/Users/ross/Documents/University/Project/Real-Time Implementation/RTWaveNet/Source/modelJSON.json";
};
