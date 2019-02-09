cmake_minimum_required(VERSION 3.10)

set(CUDA_TOOLKIT_ROOT_DIR "/usr/local/cuda-9.2")
find_package(OpenCV REQUIRED)

add_executable(proc_frame proc.cpp)
target_link_libraries(proc_frame PUBLIC ${OpenCV_LIBRARIES})
target_include_directories(proc_frame PUBLIC ${OpenCV_INCLUDE_DIRS})
target_compile_features(proc_frame PUBLIC cxx_std_17)
