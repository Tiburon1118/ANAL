# Configuración del archivo de salida
set terminal png size 800,600
set output 'histograma_uniforme.png'

# Títulos y etiquetas
set title "Histograma de Frecuencias (100 Muestras - Rango 1 al 10)" font ",14"
set xlabel "Valores generados (1 al 10)"
set ylabel "Número de apariciones"

# Configuración de los ejes y barras
set style data histograms
set style fill solid 0.6 border -1
set boxwidth 0.6
set grid ytics

# Ajuste del rango del eje Y para 100 muestras
set yrange [0:20] 

# Nueva frecuencia teórica esperada: 100 muestras / 10 valores posibles (del 0 al 9)
frecuencia_esperada = 10
set arrow from -1, frecuencia_esperada to 11, frecuencia_esperada nohead lc rgb "red" lw 2

# Graficar los datos
set key samplen 2
plot 'histograma.dat' using 2:xtic(1) title 'Frecuencia Observada' lc rgb "blue", \
     NaN title 'Frecuencia Esperada (Teórica = 10)' with lines lc rgb "red" lw 2

