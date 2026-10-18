# Configuración general de salida
set terminal pngcairo size 800,600 enhanced font 'Arial,11'
set grid

# ------------------------------------------------------------------
# GRÁFICA 1: Comparativa de Tiempos Medios de CPU (InsertSort vs BubbleSort)
# ------------------------------------------------------------------
set output 'comparacion_tiempos.png'
set title 'Comparativa de Tiempos de Ejecución (CPU)'
set xlabel 'Tamaño de entrada (N)'
set ylabel 'Tiempo medio de CPU (s)'
set key top left

plot 'insert_sort_times.dat' using 1:3 with linespoints lw 2 pt 7 title 'InsertSort', \
     'bubble_sort_times.dat' using 1:3 with linespoints lw 2 pt 5 title 'BubbleSort'

# ------------------------------------------------------------------
# GRÁFICA 2: Operaciones Básicas (OB) - InsertSort
# ------------------------------------------------------------------
set output 'ob_insert_sort.png'
set title 'Ejecuciones de la Operación Básica - InsertSort'
set xlabel 'Tamaño de entrada (N)'
set ylabel 'Número de ejecuciones de la OB'
set key top left

plot 'insert_sort_times.dat' using 1:4 with linespoints lw 2 pt 7 lc rgb 'blue' title 'Promedio (average_ob)', \
     'insert_sort_times.dat' using 1:5 with linespoints lw 2 pt 9 lc rgb 'green' title 'Mínimo (min_ob)', \
     'insert_sort_times.dat' using 1:6 with linespoints lw 2 pt 11 lc rgb 'red' title 'Máximo (max_ob)'

# ------------------------------------------------------------------
# GRÁFICA 3: Operaciones Básicas (OB) - BubbleSort
# ------------------------------------------------------------------
set output 'ob_bubble_sort.png'
set title 'Ejecuciones de la Operación Básica - BubbleSort'
set xlabel 'Tamaño de entrada (N)'
set ylabel 'Número de ejecuciones de la OB'
set key top left

plot 'bubble_sort_times.dat' using 1:4 with linespoints lw 2 pt 7 lc rgb 'blue' title 'Promedio (average_ob)', \
     'bubble_sort_times.dat' using 1:5 with linespoints lw 2 pt 9 lc rgb 'green' title 'Mínimo (min_ob)', \
     'bubble_sort_times.dat' using 1:6 with linespoints lw 2 pt 11 lc rgb 'red' title 'Máximo (max_ob)'