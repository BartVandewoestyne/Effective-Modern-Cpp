#!/bin/bash

mkdir -p ../build/Effective-Modern-Cpp/gcc-4.9
cd ../build/Effective-Modern-Cpp/gcc-4.9

# url: http://evadeflow.com/2013/11/static-analysis-with-clangscan-build/
cmake ../../../Effective-Modern-Cpp/

cd -