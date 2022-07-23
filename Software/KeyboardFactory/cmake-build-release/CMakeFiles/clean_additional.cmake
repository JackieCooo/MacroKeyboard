# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\KeyboardFactory_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\KeyboardFactory_autogen.dir\\ParseCache.txt"
  "KeyboardFactory_autogen"
  )
endif()
