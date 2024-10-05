echo Numeros para el Mejor Caso >> resultados.txt
gcc ProductoDosMayores.c tiempo.c tiempo.h -o pdmM
./pdmM 2500 NumerosMejorCaso.txt >> resultados.txt
./pdmM 5000 NumerosMejorCaso.txt >> resultados.txt

echo Numeros para el Peor Caso >> resultados.txt
gcc ProductoDosMayores.c tiempo.c tiempo.h -o pdmP
./pdmP 2500 NumerosPeorCaso.txt >> resultados.txt
./pdmP 5000 NumerosPeorCaso.txt >> resultados.txt

gcc ProductoDosMayoresC.c tiempo.c tiempo.h -o pdm
for i in {1..1000}; do
    ./pdm 2500 NumerosCasoNormal.txt >> resultadosC.txt
done
for i in {1..1000}; do
    ./pdm 5000 NumerosCasoNormal.txt >> resultadosC2.txt
done

echo Promedios para el Caso Normal>> resultados.txt
gcc Promedios.c -o prom
./prom 1000 resultadosC.txt >> resultados.txt
./prom 1000 resultadosC2.txt >> resultados.txt
