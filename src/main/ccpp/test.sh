#!/bin/bash

cmake -S . -B build -DCMAKE_RUNTIME_OUTPUT_DIRECTORY:PATH="$(pwd)"
cmake --build build
# Remove .exe extension if present (MinGW adds it regardless)
if [[ -f ./ccpp.exe ]]; then
  mv ./ccpp.exe ./ccpp
fi

if [[ "$1" == "--benchmark" || "$1" == "-bm" || "$1" == "-b" || "$1" == "-v" ]]; then
  printf "\nEXECUTION WITH BENCHMARKING RESULT:\n\n"

  # Choose the appropriate `time` implementation and flags across platforms
  TIME_BIN="/usr/bin/time"
  TIME_ARGS="-p"
  if command -v gtime >/dev/null 2>&1; then
    TIME_BIN="$(command -v gtime)"
    TIME_ARGS="-v"
  elif "$TIME_BIN" -v true >/dev/null 2>&1; then
    TIME_ARGS="-v"
  elif "$TIME_BIN" -l true >/dev/null 2>&1; then
    TIME_ARGS="-l"
  else
    TIME_ARGS="-p"
  fi

  for i in {1..10}; do
    first_line=$(awk 'NR==1 {print; exit}' main/input_$i.txt)
    if [[ ! -f main/input_$i.txt || "$first_line" == "" || "$first_line" == "!IGNORE" ]]; then
      break;
    fi
    "$TIME_BIN" $TIME_ARGS ./ccpp < main/input_$i.txt
    expected=$(awk 'END {print}' main/input_$i.txt)
    actual=$(./ccpp < main/input_$i.txt)
    if [[ "$actual" != "$expected" ]]; then
      echo "TEST $i FAILED! - WRONG ANSWER"
      echo "  Expected: $expected"
      echo "  Actual:   $actual"
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
  actual=$(./ccpp < main/input_$i.txt)
  if [[ "$actual" != "$expected" ]]; then
    echo "TEST $i FAILED! - WRONG ANSWER"
    echo "  Expected: $expected"
    echo "  Actual:   $actual"
  else
    echo "TEST $i PASSED!"
  fi
done
