cmake_minimum_required(VERSION 3.0)
project(TrackerExample)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add executable
add_executable(tracker tracker.cpp)

# Link OpenCV libraries
target_link_libraries(tracker ${OpenCV_LIBS})
