cmake_minimum_required(VERSION 3.14)
project(breploader)

set (CMAKE_CXX_STANDARD 14)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

find_package(Eigen3 REQUIRED)
find_package(OpenCASCADE REQUIRED)

set(HEADERS 
  ${CMAKE_CURRENT_SOURCE_DIR}/include/body.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/edge.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/face.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/loop.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/topology.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/types.h
  ${CMAKE_CURRENT_SOURCE_DIR}/include/vertex.h
)
set(SOURCES 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/body.cpp
)
set(OCCT_SOURCES 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/occ/occtbody.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/occ/occtedge.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/occ/occtface.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/occ/occtloop.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/occ/occtvertex.cpp
)

add_library(breploader 
  ${SOURCES}
  ${HEADERS}
  ${OCCT_SOURCES}
)

target_include_directories(breploader PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_include_directories(breploader PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/ext
)

target_link_libraries(breploader PUBLIC
  Eigen3::Eigen 
  TKernel 
  TKXSBase 
  TKSTEP 
  TKBRep 
  TKG3d 
  TKMath 
  TKMesh 
  TKTopAlgo 
  TKShHealing)

target_include_directories(breploader PUBLIC ${OpenCASCADE_INCLUDE_DIR})
target_link_directories(breploader PUBLIC ${OpenCASCADE_LIBRARY_DIR})