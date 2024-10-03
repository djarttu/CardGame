#!/bin/sh

git submodule add https://github.com/google/googletest.git
git submodule update --init --recursive

cmake -S . -B build

if [ "$1" = "play" ]; 
then
    cmake --build build --target CardGame
    ./build/CardGame

elif [ "$1" = "build-tests" ]; 
    then
        cmake --build build --target Tests

elif [ "$1" = "run-tests" ];
    then
        ./build/Tests
else
echo "Add arguments \n
     play         =     to build app and play
     build-tests  =     build tests
     run-tests    =     run tests"
fi