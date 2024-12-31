#!/bin/bash

# Variables
BUILD_DIR="build"
BUILD_TYPE="Debug"

# Use argument as build type if provided
if [ $# -ge 1 ]; then
  BUILD_TYPE=$1
fi

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
  mkdir -p $BUILD_DIR
  echo "Build directory created."
fi

# Run CMake and build quietly by redirecting output to /dev/null
echo "Running CMake configuration..."
cmake -S . -B $BUILD_DIR --log-level=ERROR
echo "CMake configuration finished."

echo "Building project..."
cmake --build $BUILD_DIR --config $BUILD_TYPE
echo "Build finished."

# Run the executable and show its output
echo "Running the executable..."
echo ""
echo ""
$BUILD_DIR/$BUILD_TYPE/game
