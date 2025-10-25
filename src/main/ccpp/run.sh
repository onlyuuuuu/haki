#!/bin/bash

./build.sh
printf "\nExecution Result:\n"
/usr/bin/time -v ./ccpp < main/input.txt
