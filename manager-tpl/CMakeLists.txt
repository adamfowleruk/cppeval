cmake_minimum_required(VERSION 3.12)

add_executable(manager-tpl
  include/manager.h
  src/subdevice.cpp
  src/main.cpp
)

include_directories(
  include
)

target_compile_features(manager-tpl PRIVATE cxx_std_17)
