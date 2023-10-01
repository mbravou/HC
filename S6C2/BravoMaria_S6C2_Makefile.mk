# Generar datos
data_py:
	python makedatos.py > datos.dat

data_cpp:
	g++ makedatos1.cpp -o makedatos1
	./makedatos1 > datos1.dat

# Gráficos
plots_py:
	python plotdatos.py

plots_cpp:
	python plotdatos1.py

# PDF
pdf:
	pdflatex resultados.tex

# Regla para limpiar archivos temporales
clean:
	rm -f makedatos1 *.log *.aux *.out

# Todas las reglas
all: data_py data_cpp plots_py plots_cpp pdf clean
