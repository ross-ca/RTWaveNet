/*
  ==============================================================================

    WaveNet.h
    Created: 10 Apr 2022 7:13:10pm
    Author:  Ross Castledine

  ==============================================================================
*/

#pragma once
#include <string>
#include <vector>

using namespace std;

class WaveNet{
public:
    //Define Constructor
    WaveNet(int convChannels, int inputChannels, int outputChannels, string activation, vector<int> dilations)
    {
        convChannels = convChannels;
        inputChannels = inputChannels;
        outputChannels = outputChannels;
        activation = activation;
        dilations = dilations;
    };
private:
    int convChannels;
    int inputChannels;
    int outputChannels;
    string activation;
    vector<int> dilations;
};
