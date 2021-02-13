#!/usr/bin/env bash

PROBLEM="zid"

src_file=$1
pts=0

g++ $src_file -std=c++11 -O2 &> /dev/null
if [ $? != 0 ]; then
    echo "Compilation error"
fi

for ((i=1; i<=10; i++)); do
    echo -n "Test $i: "
    cp teste/$PROBLEM-$i.in $PROBLEM.in
    timeout 0.1s ./a.out

    if [ $? == 124 ]; then
        echo -e "\e[31mTLE\e[39m"
        continue
    fi

    expected=$(cat teste/$PROBLEM-$i.ok)
    actual=$(cat $PROBLEM.out)

    if [ "$expected" == "$actual" ]; then
        echo -e "\e[32mOK\e[39m"
        pts=$((pts+10))
    else
        echo -e "\e[31mWA\e[39m"
    fi
done

rm $PROBLEM.in $PROBLEM.out a.out

echo -e "\nPunctaj: $pts/100"
