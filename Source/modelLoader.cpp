/*
  ==============================================================================

    modelLoader.cpp
    Created: 8 Apr 2022 5:37:27pm
    Author:  Ross Castledine

  ==============================================================================
*/

#include "modelLoader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

WaveNet modelLoader::loadModel(){
    
    //Load and parse json file
    std::ifstream inFile(modelLoader::jsonFilePath);
    json jf = json::parse(inFile);
    
    //Assign attribute values
    numChannels = jf["residual_channels"];
    inputChannels = jf["input_channels"];
    outputChannels = jf["output_channels"];
    activation = jf["activation"];
    filterWidth = jf["filter_width"];
    
    for (int i = 0; i < jf["dilations"].size(); i++)
    {
        dilations.push_back(jf["dilations"][i]);
    }
    
    WaveNet returnModel(inputChannels, outputChannels, numChannels, filterWidth, activation, dilations);
    returnModel.setParams(inputChannels, outputChannels, numChannels, filterWidth, activation, dilations);
    
    json variables = jf["variables"];
    
    for (int i = 0; i < variables.size(); i++)
    {
        json currentLayer = variables[i];
        
        int layerIdx = currentLayer["layer_idx"];
        string name = currentLayer["name"];
        std::vector<float> data;
        
        for (int j = 0; j < currentLayer["data"].size(); j++)
        {
            data.push_back(std::stof(currentLayer["data"][j].get<string>()));
        }
        
        returnModel.setWeight(data, layerIdx, name);
    }
    
    return returnModel;
}
