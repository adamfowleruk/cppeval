cmake_minimum_required(VERSION 3.12)

add_executable(oo-to-tpl
  include/oo.h
  include/tpl.h
  src/oo.cpp
  src/tpl.cpp
  src/main.cpp
)

include_directories(
  include
)

#target_link_libraries(oo-to-tpl PRIVATE "-Wl,--stack,100000000")
add_compile_options(-Wl,--stack,100000000)

target_compile_features(oo-to-tpl PRIVATE cxx_std_17)
