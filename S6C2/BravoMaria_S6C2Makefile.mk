# Archivos de entrada y salida
DATOS_PY := makedatos.py
DATOS_CPP := makedatos1.cpp
GRAFICOS_PY := plotdatos.py
GRAFICOS_CPP := plotdatos1.py
TEX := resultados.tex
PDF := resultados.pdf

# Generar datos
data_py:
    python $(DATOS_PY)

data_cpp:
    g++ $(DATOS_CPP) -o makedatos1
    ./makedatos1

# Gráficos
plots_py:
    python $(GRAFICOS_PY)

plots_cpp:
    python $(GRAFICOS_CPP)

# PDF
pdf:
    pdflatex $(TEX)

# Todas las reglas
all: data_py data_cpp plots_py plots_cpp pdf

# Regla para limpiar archivos temporales
#clean:
#    rm -f makedatos1 *.pdf *.log *.aux

#.PHONY: data_py data_cpp datos plots_py plots_cpp plots pdf all clean
