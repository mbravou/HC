# Generar datos
prog:
	g++ MariaBravo_S7C2_EDO2.cpp -o MariaBravo_S7C2_EDO2
	./MariaBravo_S7C2_EDO2

# Gráficos
plot:
	python PLOTS_MariaBravo_S7C2_EDO2.py

# PDF
pdf:
	pdflatex resultados.tex

# Regla para limpiar archivos temporales
clean:
	rm -f MariaBravo_S7C2_EDO2 *.log *.aux *.out

# Todas las reglas
all: prog plot pdf clean
