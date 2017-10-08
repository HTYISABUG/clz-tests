reset
set xlabel 'numerical distribution'
set ylabel 'branch-misses(%)'
set title 'performance comparison'
set term png enhanced font 'Verdana,10'
set output 'branch-misses.png'
set format x "%10.0f"
set xtic 2000
set xtics rotate by 45 right

plot [:][3.5:4.5]'iteration-branch-misses.perf' using 1:2 with points title 'iteration', \
'byte-branch-misses.perf' using 1:2 with points title 'byte',  \
'binary-branch-misses.perf' using 1:2 with points title 'binary',  \
'recursive-branch-misses.perf' using 1:2 with points title 'recursive',    \
'harley-branch-misses.perf' using 1:2 with points title 'harley'

