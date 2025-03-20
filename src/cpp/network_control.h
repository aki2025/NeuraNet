#ifndef NETWORK_CONTROL_H
#define NETWORK_CONTROL_H

#include <vector>

struct NetworkSlice {
    int slice_id;
    double bandwidth; // MHz
    int priority;     // 1-10 scale
    double latency;   // ms
};

void adjustNetworkSlices(std::vector<NetworkSlice>& slices, std::vector<double> ai_outputs);
void initializeSimulation();
void runSimulation();

#endif // NETWORK_CONTROL_H 
