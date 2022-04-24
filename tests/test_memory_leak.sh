##
## EPITECH PROJECT, 2022
## LET-ME-IN-mirror
## File description:
## test_memory_leak
##

#!/bin/bash

make debug

for i in $(find -type f -path "./tests/maps/*.map");
do
    valgrind --error-exitcode=3 ./lem_in < $i
    return_value=$?
    if (($return_value == 3)); then
        printf '\033[31m********memory leak found with this file********\n\n%36s\n\n******************push disable******************\n\033[0m' $i
    else
        printf '\033[32m********no memory leak found********\n************push enable*************\n\033[0m'
    fi;
done
