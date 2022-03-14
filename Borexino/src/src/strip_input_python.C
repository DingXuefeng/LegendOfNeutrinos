/*****************************************************************************/
// Author: Xuefeng Ding <xuefeng.ding.physics@gmail.com>
// Insitute: Gran Sasso Science Institute, L'Aquila, 67100, Italy
// Date: 2019 March 8th
// Version: v1.0
// Description: strip_L1: program for making input for moving average fitting
//
// All rights reserved. 2018 copyrighted.
/*****************************************************************************/
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
void strip_input(std::string input_fc,std::string output_fc,std::vector<std::string> hists,bool keepQ = true, bool keepNpmt = false, bool keepNhit = false, bool keepMV = false);

PYBIND11_MODULE(strip_input, m) {
  m.doc() = "pybind11 strip fitter input plugin"; // optional module docstring
  m.def("strip_input", &strip_input, "Strip CNO ntuples",
            pybind11::arg("input") = "./TFCMI_pepFV_2017_Jan_01_2021_Mar_14.root", 
            pybind11::arg("output") = "./TFCMI_pepFV_2017_Jan_01_2021_Mar_14_charge_49dfc.root",
            pybind11::arg("hists"),
            pybind11::arg("keepQ") = true,
            pybind11::arg("keepNpmt") = false,
            pybind11::arg("keepNhit") = false,
            pybind11::arg("keepMV") = false);
}
