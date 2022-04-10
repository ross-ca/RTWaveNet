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
    };
    
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
};
