#!/bin/bash

# Variables
BUILD_DIR="build"
BUILD_TYPE="Debug" # Default build type

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
  mkdir -p $BUILD_DIR
  echo "Build directory created."
fi

# Handle configuration modes
if [ "$1" == "debug" ]; then
  BUILD_TYPE="Debug"
  echo "Configuring CMake for Debug mode..."
  cmake -S . -B $BUILD_DIR -DCMAKE_BUILD_TYPE=Debug
  echo "CMake configuration for Debug mode finished."
  exit 0
elif [ "$1" == "release" ]; then
  BUILD_TYPE="Release"
  echo "Configuring CMake for Release mode..."
  cmake -S . -B $BUILD_DIR -DCMAKE_BUILD_TYPE=Release
  echo "CMake configuration for Release mode finished."
  exit 0
fi

# Default behavior: build and execute
echo "Building project..."
cmake --build $BUILD_DIR
echo "Build finished."

echo "Running the executable..."
echo ""
echo ""
$BUILD_DIR/game
