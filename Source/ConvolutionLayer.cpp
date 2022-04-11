/*
  ==============================================================================

    ConvolutionLayer.cpp
    Created: 11 Apr 2022 5:35:51pm
    Author:  Ross Castledine

  ==============================================================================
*/

#include "ConvolutionLayer.h"

ConvolutionLayer::ConvolutionLayer(size_t inputChannels, size_t outputChannels, int filterWidth, int dilation, bool residual, std::string activationname):
conv(inputChannels, Activations::isGated(activationname) ? outputChannels * 2 : outputChannels, filterWidth, dilation),
out1x1(inputChannels, outputChannels, 1, 1),
residual(residual),
usesGating(Activations::isGated(activationname)),
activation(Activations::getActivationFuncArray(activationname))
{}

void ConvolutionLayer::process(float *data, int numSamples)
{
    conv.process(data, numSamples);
    activation(data, conv.getNumOutputChannels(), numSamples);
    if (residual)
        out1x1.process(data, numSamples);
}

void ConvolutionLayer::process(float *data, float *skipdata, int numSamples)
{
    conv.process(data, numSamples);
    activation(data, conv.getNumOutputChannels(), numSamples);
    copySkipData(data, skipdata, numSamples);
    if (residual)
        out1x1.process(data, numSamples);
}

void ConvolutionLayer::copySkipData(float *data, float *skipData, int numSamples)
{
    size_t skipChannels = usesGating ? conv.getNumOutputChannels() / 2 : conv.getNumOutputChannels();
    for (size_t i = 0; i < (size_t)numSamples * skipChannels; ++ i)
        skipData[i] = data[i];
}

void ConvolutionLayer::setParams(size_t newInputChannels, size_t newOutputChannels, int newFilterWidth, int newDilation, bool newResidual, std::string newActivationName)
{
    activation = Activations::getActivationFuncArray(newActivationName);
    usesGating = Activations::isGated(newActivationName);
    size_t internalChannels = usesGating ? newOutputChannels * 2 : newOutputChannels;
    conv.setParams(newInputChannels, internalChannels, newFilterWidth, newDilation);
    out1x1.setParams(newOutputChannels, newOutputChannels, 1, 1);
    residual = newResidual;
}

void ConvolutionLayer::setWeight(std::vector<float> W, std::string name)
{
    if ((name == "W_conv") || (name == "W"))
        conv.setWeight(W, "W");
    else if ((name == "b_conv") || (name == "b"))
        conv.setWeight(W, "b");
    else if (name == "W_out")
        out1x1.setWeight(W, "W");
    else if (name == "b_out")
        out1x1.setWeight(W, "b");
}
