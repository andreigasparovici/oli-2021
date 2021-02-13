#!/usr/bin/env bash

PROBLEM="zid"

make

function generate() {
    N_min=$1
    N_max=$2
    i_min=$3
    i_max=$4

    for ((i=$i_min; i<=$i_max; i++)); do
        N=$(shuf -i $N_min-$N_max -n 1)
        echo $N > teste/$PROBLEM-$i.in

        cp teste/$PROBLEM-$i.in $PROBLEM.in
        ./exec/sol_dp

        echo "Test $i"
        echo "IN: $(cat $PROBLEM.in)"
        echo "OUT: $(cat $PROBLEM.out)"
        echo

        cp $PROBLEM.out teste/$PROBLEM-$i.ok

        rm $PROBLEM.in $PROBLEM.out
    done
}

generate 5 30 1 3
generate 30 5000 4 10
