reset
set xlabel 'numerical distribution'
set ylabel 'time(cycles)'
set title 'performance comparison'
set term png enhanced font 'Verdana,10'
set output 'cycles.png'
set format x "%10.0f"
set xtic 2000
set xtics rotate by 45 right

plot [:][:]'iteration-cycles.perf' using 1:2 with points title 'iteration', \
'byte-cycles.perf' using 1:2 with points title 'byte',  \
'binary-cycles.perf' using 1:2 with points title 'binary',  \
'recursive-cycles.perf' using 1:2 with points title 'recursive',    \
'harley-cycles.perf' using 1:2 with points title 'harley'

