# Generar datos
prog:
	g++ BravoMaria_S7CASA_EDO.cpp -o BravoMaria_S7CASA_EDO
	./BravoMaria_S7CASA_EDO

# Gráficos
plot:
	python PLOTS_MariaBravo_S7CASA_EDO.py

# PDF
pdf:
	pdflatex resultadosEDO.tex

# Regla para limpiar archivos temporales
clean:
	rm -f BravoMaria_S7CASA_EDO *.log *.aux *.out

# Todas las reglas
all: prog plot pdf clean
