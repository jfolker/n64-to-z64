#!/bin/zsh
if [ ! -f n64-to-z64 ]; then
    clang++ -std=c++17 -o n64-to-z64 n64-to-z64.cpp
fi

if [ -n "$1" ]; then    
    cd $1
fi
./n64-to-z64 * || exit $?

mkdir -p little-endian16/
for file in *.n64; do
    mv -f $file little-endian16/
done
echo "Moved all .n64 files to $PWD/little-endian16/"
