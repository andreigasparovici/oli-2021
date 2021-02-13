#!/usr/bin/env bash

make

function generate() {
    N_min=$1
    N_max=$2
    i_min=$3
    i_max=$4

    for ((i=$i_min; i<=$i_max; i++)); do
        N=$(shuf -i $N_min-$N_max -n 1)
        echo $N > teste/zid-$i.in

        cp teste/zid-$i.in zid.in
        ./exec/sol_dp

        echo "Test $i"
        echo "IN: $(cat zid.in)"
        echo "OUT: $(cat zid.out)"
        echo

        cp zid.out teste/zid-$i.ok

        rm zid.in zid.out
    done
}

generate 5 30 1 3
generate 30 5000 4 10
