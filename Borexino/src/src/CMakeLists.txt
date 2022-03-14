find_package(ROOT REQUIRED)

find_package(pybind11 CONFIG REQUIRED)

add_library(strip_input_c STATIC strip_input.C)
target_link_libraries(strip_input_c PRIVATE ROOT::Core ROOT::RIO)
set_target_properties(strip_input_c PROPERTIES POSITION_INDEPENDENT_CODE TRUE)

pybind11_add_module(strip_input strip_input_python.C)
target_link_libraries(strip_input PRIVATE strip_input_c)
install(TARGETS strip_input)
