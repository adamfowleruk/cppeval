cmake_minimum_required(VERSION 3.12)

add_executable(manager-tpl
  include/manager.h
  src/subdevice.cpp
  src/main.cpp
)

include_directories(
  include
)

#target_link_libraries(manager-tpl PRIVATE "-Wl,--stack,100000000")
add_compile_options(-Wl,--stack,100000000)

target_compile_features(manager-tpl PRIVATE cxx_std_17)
