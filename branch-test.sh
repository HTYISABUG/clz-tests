#!/bin/bash
for i in $(seq $2 $3); do \
    perf stat -e cycles,instructions,branches,branch-misses \
        -o .tmp/${i}.perf \
        taskset -c 1 ./$1 ${i} $[${i}+1] > /dev/null; \
done
