cmake_minimum_required(VERSION 3.12)

add_executable(manager-oo
  src/subdevice.cpp
  src/manager.cpp
  src/main.cpp
)

include_directories(
  include
)

target_compile_features(manager-oo PRIVATE cxx_std_17)
