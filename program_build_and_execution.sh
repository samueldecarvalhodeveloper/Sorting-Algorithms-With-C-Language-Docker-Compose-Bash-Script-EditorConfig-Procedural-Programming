#!/bin/bash

BUILD_DIR="build"
EXECUTABLE="$(pwd)/build/SortingAlgorithms"

if [ ! -d "$BUILD_DIR" ]; then
  echo "Build directory does not exist. Creating one..."

  mkdir $BUILD_DIR
else
  echo "Build directory exists."
fi

cd $BUILD_DIR

echo "Running CMake..."

cmake ..

if [ $? -ne 0 ]; then
  echo "CMake generation failed."

  exit 1
fi

echo "Building the project..."

make

if [ $? -ne 0 ]; then
  echo "Build failed."

  exit 1
fi

if [ -f "$EXECUTABLE" ]; then
  echo "Running Program:"

  echo ""

  $EXECUTABLE

  echo ""
  echo ""

  echo "Program Finished!"
else
  echo "Executable $EXECUTABLE not found!"

  exit 1
fi
