# Configuración general
set terminal pngcairo size 800,600 enhanced font 'Arial,11'
set grid
set key top left

# ==================================================================
# 1. AJUSTE Y GRÁFICA DE OPERACIONES BÁSICAS (OB) - QuickSort_median
# ==================================================================
# Modelo teórico en caso promedio: O(N log2 N)
f_ob(x) = a * x * (log(x) / log(2)) + b * x

# Semillas iniciales no nulas (teóricamente a ~ 1.188 para mediana de tres)
a = 1.2
b = -1.0

# Ajuste usando columna 1 (N) y columna 4 (average_ob)
fit f_ob(x) 'quicksort_median.log' using 1:4 via a, b

set output 'qs_median_ob.png'
set title 'Operaciones Básicas (OB) - QuickSort\_median y Ajuste Teórico O(N log_2 N)'
set xlabel 'Tamaño de entrada (N)'
set ylabel 'Número de ejecuciones de la OB'
set yrange [0:*]

plot 'quicksort_median.log' using 1:4 with points pt 7 ps 1.2 lc rgb 'blue' title 'Promedio medido (average\_ob)', \
     'quicksort_median.log' using 1:5 with linespoints lw 1.5 pt 9 lc rgb 'green' title 'Mínimo (min\_ob)', \
     'quicksort_median.log' using 1:6 with linespoints lw 1.5 pt 11 lc rgb 'red' title 'Máximo (max\_ob)', \
     f_ob(x) with lines lw 2 dt 2 lc rgb 'black' title sprintf('Ajuste: %.3f N log_2(N) + %.3f N', a, b)

# ==================================================================
# 2. AJUSTE Y GRÁFICA DE TIEMPO MEDIO DE CPU - QuickSort_median
# ==================================================================
# Modelo teórico proporcional a N log2(N)
f_time(x) = c * x * (log(x) / log(2))

# Semilla inicial no nula acorde al orden de segundos
c = 1.1e-8

# Ajuste usando columna 1 (N) y columna 3 (time)
fit f_time(x) 'quicksort_median.log' using 1:3 via c

set output 'qs_median_time.png'
set title 'Tiempo Medio de CPU - QuickSort\_median y Ajuste Teórico O(N log_2 N)'
set xlabel 'Tamaño de entrada (N)'
set ylabel 'Tiempo medio de CPU (s)'
set yrange [0:*]

plot 'quicksort_median.log' using 1:3 with linespoints lw 1.5 pt 7 ps 1.2 lc rgb 'dark-orange' title 'Tiempo medio medido (s)', \
     f_time(x) with lines lw 2 dt 2 lc rgb 'black' title sprintf('Ajuste: %.2e N log_2(N)', c)