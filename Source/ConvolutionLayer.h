/*
  ==============================================================================

    ConvolutionLayer.h
    Created: 11 Apr 2022 5:35:51pm
    Author:  Ross Castledine

  ==============================================================================
*/

#pragma once
#include <string>
#include "Convolution.h"
#include "Activations.h"

class ConvolutionLayer
{
public:
    ConvolutionLayer(size_t inputChannels, size_t outputChannels, int filterWidth, int dilation, bool residual, std::string activationName);
    void process(float* data, int numSamples);
    void process(float* data, float* skipdata, int numSamples);
    void setParams(size_t newInputChannels, size_t newOutputChannels, int newFilterWidth, int newDilation, bool newResidual, std::string newActivationName);
    void setWeight(std::vector<float> W, std::string name);
    
private:
    Convolution conv;
    Convolution out1x1;
    bool residual;
    bool usesGating;
    typedef void (*activationFunction)(float *x, size_t rows, size_t cols);
    activationFunction activation;
    void copySkipData(float *data, float *skipData, int numSamples);
};
