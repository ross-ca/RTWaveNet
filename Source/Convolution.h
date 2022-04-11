/*
  ==============================================================================

    Convolution.h
    Created: 10 Apr 2022 8:11:58pm
    Author:  Ross Castledine

  ==============================================================================
*/

#pragma once

#include <Eigen/Core>
#include <Eigen/StdVector>

class Convolution{
public:
    Convolution(size_t inputChannels, size_t outputChannels, int filterWidth, int dilation)
    {
        bias(outputChannels);
        outVec(outputChannels);
        pos = 0;
        dilation = dilation;
        inputChannels = inputChannels;
        outputChannels = outputChannels;
        filterWidth = filterWidth;
        
        resetFifo();
        resetKernel();
    };
    
    int getFilterOrder() const;
    void setParams(size_t inputChannels, size_t outputChannels, int filterWidth, int dilation);
    size_t getNumInputChannels(){ return inputChannels; }
    size_t getNumOutputChannels() { return outputChannels; }
    void process(float* data, int numSamples);
    void setWeight(std::vector<float> W, std::string name);
    
private:
    std::vector<Eigen::MatrixXf, Eigen::aligned_allocator<Eigen::MatrixXf>> kernel;
    Eigen::RowVectorXf bias;
    std::vector<Eigen::RowVectorXf, Eigen::aligned_allocator<Eigen::RowVectorXf>> memory;
    Eigen::RowVectorXf outVec;
    int pos;
    int dilation;
    size_t inputChannels;
    size_t outputChannels;
    int filterWidth;
    
    void resetFifo();
    void resetKernel();
    void processSingleSample(float* data, int i, int numSamples);
    
    int mod(int a, int b);
    int idx(int ch, int i, int numSamples);
    
    void setKernel(std::vector<float> W);
    void setBias(std::vector<float> W);
};
