#!/bin/bash

assert_equals () {
  if [ "$1" = "$2" ]; then
    echo -e "$Green $Check_Mark Success $Color_Off"
  else
    echo -e "$Red Failed $Color_Off"
    echo -e "$Red Expected -$1- to equal -$2- $Color_Off"
    Errors=$((Errors  + 1))
    exit 1
  fi
}

response=$(./calculator d2 + d2)
assert_equals "$response" 4

response=$(./calculator d7 - d2)
assert_equals "$response" 5

response=$(./calculator b1010 + b11 )
assert_equals "$response" 13

response=$(./calculator b11 - b1111)
assert_equals "$response" -13

response=$(./calculator d2 - b10 + d6 - d2)
assert_equals "$response" 4

response=$(./calculator d5 + d-2)
assert_equals "$response" 3

response=$(./calculator b1010 - d-5)
assert_equals "$response" 15

response=$(./calculator b1010 - b1011)
assert_equals "$response" -1

response=$(./calculator d11 - d-1 + d+10)
assert_equals "$response" 2