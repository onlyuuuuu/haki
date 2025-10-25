#!/bin/bash

./build.sh
if [[ "$1" == "--benchmark" || "$1" == "-bm" || "$1" == "-b" || "$1" == "-v" ]]; then
  printf "\nEXECUTION WITH BENCHMARKING RESULT:\n\n"
  for i in {1..10}; do
    first_line=$(awk 'NR==1 {print; exit}' main/input_$i.txt)
    if [[ ! -f main/input_$i.txt || "$first_line" == "" || "$first_line" == "!IGNORE" ]]; then
      break;
    fi
    /usr/bin/time -v ./ccpp < main/input_$i.txt
    expected=$(awk 'END {print}' main/input_$i.txt)
    if [[ "$(./ccpp < main/input_$i.txt)" != "$expected" ]]; then
      echo "TEST $i FAILED! - WRONG ANSWER - EXPECTED: $expected"
    else
      echo "TEST $i PASSED!"
    fi
  done
fi
printf "\nOVERALL TEST RESULT:\n\n"
for i in {1..10}; do
  first_line=$(awk 'NR==1 {print; exit}' main/input_$i.txt)
  if [[ ! -f main/input_$i.txt || "$first_line" == "" || "$first_line" == "!IGNORE" ]]; then
    break;
  fi
  expected=$(awk 'END {print}' main/input_$i.txt)
  if [[ "$(./ccpp < main/input_$i.txt)" != "$expected" ]]; then
    echo "TEST $i FAILED! - WRONG ANSWER - EXPECTED: $expected"
  else
    echo "TEST $i PASSED!"
  fi
done