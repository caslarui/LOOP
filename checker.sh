#!/bin/bash

## CONSTANTS ##
# shellcheck disable=SC2006
CURRENT_DIRECTORY=`pwd`
RESOURCES_DIRECTORY="$CURRENT_DIRECTORY/checker/resources"
GOOD_TESTS=0

## FUNCTIONS ##
function cleanHomework
{
  make clean
	rm -rf "$RESOURCES_DIRECTORY/out"
	rm -rf "$CURRENT_DIRECTORY/CMakeFiles"
	rm cmake_install.cmake
	rm CMakeCache.txt
}

function compileHomework
{
  make

	mkdir "$RESOURCES_DIRECTORY/out"
}

function checkTest
{
    echo -ne "Test\t$1\t.....................................\t"
    ./LOOP "$RESOURCES_DIRECTORY/in/$1.in" "$RESOURCES_DIRECTORY/out/$1.out" > /dev/null

	# shellcheck disable=SC2181
	if [ $? -eq 0 ]; then
        # shellcheck disable=SC2092
        # shellcheck disable=SC2006
        `diff -Bw -u --ignore-all-space "$RESOURCES_DIRECTORY"/out/$1.out "$RESOURCES_DIRECTORY"/res/$1.in.res &> /dev/null`
        DIFF_RESULT=$?

        if [ $DIFF_RESULT -eq 0 ]; then
        	echo -ne "OK\n"

			if [[ $1 == *x* ]]; then
            	GOOD_TESTS=$((GOOD_TESTS+5))
        	elif [[ $1 == *dense* ]]; then
            	GOOD_TESTS=$((GOOD_TESTS+21))
        	else
            	GOOD_TESTS=$((GOOD_TESTS+1))
        	fi
        else
           echo -ne "FAIL (files differ)\n"
        fi
    else
        echo -ne 'FAIL (program error)\n'
    fi
}

function calculateScore
{
	GOOD_TESTS=$((60-GOOD_TESTS*6/10))

	GOOD_TESTS=`echo "scale=2; $GOOD_TESTS" | bc -l`

	echo -ne "\n-$GOOD_TESTS failed tests"
}

## MAIN EXECUTION ##
#cleanHomework
compileHomework

checkTest "3x3"
checkTest "4x4"
checkTest "5x5"
checkTest "dense"
checkTest "fightKKD"
checkTest "fightKKL"
checkTest "fightKKV"
checkTest "fightKKW"
checkTest "fightKPD"
checkTest "fightKPL"
checkTest "fightKPV"
checkTest "fightKPW"
checkTest "fightKRD"
checkTest "fightKRL"
checkTest "fightKRV"
checkTest "fightKRW"
checkTest "fightKWD"
checkTest "fightKWL"
checkTest "fightKWV"
checkTest "fightKWW"
checkTest "fightPKD"
checkTest "fightPKL"
checkTest "fightPKV"
checkTest "fightPKW"
checkTest "fightPPD"
checkTest "fightPPL"
checkTest "fightPPV"
checkTest "fightPPW"
checkTest "fightPRD"
checkTest "fightPRL"
checkTest "fightPRV"
checkTest "fightPRW"
checkTest "fightPWD"
checkTest "fightPWL"
checkTest "fightPWV"
checkTest "fightPWW"
checkTest "fightRKD"
checkTest "fightRKL"
checkTest "fightRKV"
checkTest "fightRKW"
checkTest "fightRPD"
checkTest "fightRPL"
checkTest "fightRPV"
checkTest "fightRPW"
checkTest "fightRRD"
checkTest "fightRRL"
checkTest "fightRRV"
checkTest "fightRRW"
checkTest "fightRWD"
checkTest "fightRWL"
checkTest "fightRWV"
checkTest "fightRWW"
checkTest "fightWKD"
checkTest "fightWKL"
checkTest "fightWKV"
checkTest "fightWKW"
checkTest "fightWPD"
checkTest "fightWPL"
checkTest "fightWPV"
checkTest "fightWPW"
checkTest "fightWRD"
checkTest "fightWRL"
checkTest "fightWRV"
checkTest "fightWRW"
checkTest "fightWWD"
checkTest "fightWWL"
checkTest "fightWWV"
checkTest "fightWWW"

calculateScore

cleanHomework
