# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: berhugue <berhugue@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/03 17:19:40 by ugutierr          #+#    #+#              #
#    Updated: 2026/05/07 18:45:43 by berhugue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

TESTS=50
SIZE=100
CHECKER=./checker_linux #./checker

GREEN="\e[32m"
RED="\e[31m"
YELLOW="\e[33m"
BLUE="\e[34m"
RESET="\e[0m"
FLAGS="--simple"

MAX=0
TOTAL=0

for ((i=1; i<=TESTS; i++))
do
    ARG=$(shuf -i 1-1000 -n $SIZE | tr '\n' ' ')
    
    OPS=$(./push_swap $FLAG $ARG | wc -l)
    RESULT=$(./push_swap $FLAG $ARG | $CHECKER $ARG)

    TOTAL=$((TOTAL + OPS))

    if [ $OPS -gt $MAX ]; then
        MAX=$OPS
    fi

    echo -e "${BLUE}Test $i${RESET}"

    if [ "$RESULT" = "OK" ]; then
        echo -e "Result: ${GREEN}OK${RESET}"
    else
        echo -e "Result: ${RED}KO ❌${RESET}"
    fi

    echo -e "Operations: ${YELLOW}$OPS${RESET}"
    echo "-----------------------------"
done

AVG=$((TOTAL / TESTS))

echo -e "${BLUE}Resumen:${RESET}"
echo -e "Media de operaciones: ${YELLOW}$AVG${RESET}"
echo -e "Peor caso: ${RED}$MAX${RESET}"
