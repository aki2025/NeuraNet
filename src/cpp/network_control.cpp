#include "network_control.h"
#include <iostream>
#include <aerial_sdk.h> // Hypothetical NVIDIA Aerial SDK header

void adjustNetworkSlices(std::vector<NetworkSlice>& slices, std::vector<double> ai_outputs) {
    for (size_t i = 0; i < slices.size(); ++i) {
        slices[i].bandwidth = ai_outputs[i * 2];      // AI output: bandwidth
        slices[i].priority = static_cast<int>(ai_outputs[i * 2 + 1]); // AI output: priority
        std::cout << "Slice " << slices[i].slice_id << ": Bandwidth = " << slices[i].bandwidth 
                  << " MHz, Priority = " << slices[i].priority << "\n";
    }
    // Apply changes to the Aerial SDK network simulation
    aerial_sdk::updateSlices(slices); // Hypothetical API call
}

void initializeSimulation() {
    aerial_sdk::initialize();
}

void runSimulation() {
    aerial_sdk::runSimulation();
} 
