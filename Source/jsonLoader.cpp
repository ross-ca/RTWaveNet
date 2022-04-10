/*
  ==============================================================================

    jsonLoader.cpp
    Created: 8 Apr 2022 5:37:27pm
    Author:  Ross Castledine

  ==============================================================================
*/

#include "jsonLoader.h"
#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

void jsonLoader::loadModel(){
    
    //Load and parse json file
    std::ifstream inFile(jsonLoader::jsonFilePath);
    json jf = json::parse(inFile);
    
    //Assign attribute values
    numChannels = jf["residual_channels"];
    inputChannels = jf["input_channels"];
    outputChannels = jf["output_channels"];
    activation = jf["activation"];
    filterWidth = jf["filter_width"];
    
}
