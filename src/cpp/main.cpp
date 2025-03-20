#include "network_control.h"
#include <vector>

int main() {
    initializeSimulation();

    // Example slices
    std::vector<NetworkSlice> slices = {
        {1, 20.0, 5, 10.0}, // Slice 1: IoT
        {2, 100.0, 8, 1.0}  // Slice 2: Broadband
    };

    // Simulated AI outputs (bandwidth, priority for each slice)
    std::vector<double> ai_outputs = {25.0, 6, 120.0, 9};

    // Adjust slices dynamically
    adjustNetworkSlices(slices, ai_outputs);

    // Run simulation
    runSimulation();
    return 0;
} 
