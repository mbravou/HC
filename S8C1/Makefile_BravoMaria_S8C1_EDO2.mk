# Generar datos
prog:
	g++ BravoMaria_S8C1_EDO2.cpp -o BravoMaria_S8C1_EDO2
	./BravoMaria_S8C1_EDO2

# Gráficos
plot:
	python PLOTS_MariaBravo_S8C1_EDO2.py

# PDF
pdf:
	pdflatex resultados.tex

# Regla para limpiar archivos temporales
clean:
	rm -f BravoMaria_S8C1_EDO2 *.log *.aux *.out

# Todas las reglas
all: prog plot pdf clean
