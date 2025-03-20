#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include "network_control.h"

void update_slices_py(std::vector<double> ai_outputs) {
    std::vector<NetworkSlice> slices = {
        {1, 20.0, 5, 10.0},
        {2, 100.0, 8, 1.0}
    };
    adjustNetworkSlices(slices, ai_outputs);
}

PYBIND11_MODULE(aerial_sdk_bridge, m) {
    m.def("update_slices", &update_slices_py, "Update network slices with AI outputs");
} 
