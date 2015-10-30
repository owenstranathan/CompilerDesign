#!/bin/bash

# a simple bash script for running tests on calc
# can take a test file as input and will run tests on
# that file

function pause()
{
    read -p "$*"
}

echo "Now running tests for Extended Calc";

if [ -z ${1+x} ];
    then
        echo "Using test input from file 'test/input/test-file1.txt'";
        echo "Input is: ";
        cat test/input/test-file1.txt;
        pause "Press [Enter] key to continue...";

        echo "Translating and evaluating input...";
        ./build/ext_calc_eval < test/input/test-file1.txt;
        pause "Press [Enter] to quit...";

    else
        echo "Using test input from file $1";
        echo "Input is: ";
        cat $1;
        pause "Press [Enter] key to continue...";

        echo "Translating and evaluating input...";
        ./build/ext_calc_eval < $1;
        pause "Press [Enter] to view inputs quit...";

fi

echo "The testing is complete! Goodbye!";
