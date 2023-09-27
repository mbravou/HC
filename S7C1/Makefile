# Generar datos
prog:
	g++ prog.cpp -o prog
	./prog

# Gráficos
plot:
	python plot.py

# PDF
pdf:
	pdflatex resultados.tex

# Regla para limpiar archivos temporales
clean:
	rm -f prog *.log *.aux *.out

# Todas las reglas
all: prog plot pdf clean
