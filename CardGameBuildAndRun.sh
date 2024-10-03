#!/bin/sh

help(){
    echo "Add arguments, only first argument and --clean flag are used \n
     build-and-play       =     build app and play
     build-and-run-tests  =     build tests
     run-tests            =     run tests
     play                 =     play
     --clean              =     configures cmake files"
}

if [ ! -d build/CMakeFiles ]; then
    cmake -S . -B build;
fi

if [ ! -d googletest ] || [ ! -f .gitmodules ];then
    git submodule add https://github.com/google/googletest.git
    git submodule update --init --recursive;
fi

for arg in "$@"; do
    case "$arg" in
        '--clean')                cmake -S . -B build;;
        '--help')                 help;;
    esac
done

for arg in "$@"; do
    shift
    case "$arg" in
        'build-and-play')
            if [ -f build/CardGame ]; then
                rm build/CardGame
            fi           
            cmake --build build --target CardGame
            ./build/CardGame   
            exit;;
        'build-and-run-tests')
            if [ -f build/Tests ]; then
                rm build/Tests
            fi
            cmake --build build --target Tests
            ./build/Tests 
            exit;;
        'run-tests')
            ./build/Tests 
            exit;;
        'play')
            ./build/CardGame   
            exit;;
    esac
done
