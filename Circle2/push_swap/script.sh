#!/bin/bash

# Lire chaque possibilité d'ordre depuis le fichier test_cases.txt
while read -r arg; do
    # Exécuter le programme push_swap avec l'argument courant
    result=$(./push_swap $arg | ./checker $arg)

    	echo "Argument: $arg"
        echo "$result"
    	echo "----------------------------------------------"

done < "test_cases3.txt"

while read -r arg; do
    # Exécuter le programme push_swap avec l'argument courant
    result=$(./push_swap $arg | ./checker $arg)

    	echo "Argument: $arg"
        echo "$result"
    	echo "----------------------------------------------"

done < "test_cases4.txt"


while read -r arg; do
    # Exécuter le programme push_swap avec l'argument courant
    result=$(./push_swap $arg | ./checker $arg)

    	echo "Argument: $arg"
        echo "$result"
    	echo "----------------------------------------------"

done < "test_cases5.txt"