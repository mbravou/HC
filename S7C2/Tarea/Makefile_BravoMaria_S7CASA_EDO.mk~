# Generar datos
prog:
	g++ MariaBravo_S7C1_EDO.cpp -o MariaBravo_S7C1_EDO
	./MariaBravo_S7C1_EDO

# Gráficos
plot:
	python PLOTS_MariaBravo_S7C1_EDO.py

# PDF
pdf:
	pdflatex resultados.tex

# Regla para limpiar archivos temporales
clean:
	rm -f MariaBravo_S7C1_EDO *.log *.aux *.out

# Todas las reglas
all: prog plot pdf clean
