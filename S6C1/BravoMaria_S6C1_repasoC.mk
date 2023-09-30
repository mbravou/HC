# Generar datos
data:
	g++ BravoMaria_S6C1_repasoC.cpp -o BravoMaria_S6C1_repasoC
	./BravoMaria_S6C1_repasoC

# Gráficos
plots:
	python BravoMaria_S6C1_repasoC.py

# Regla para limpiar archivos temporales
clean:
	rm -f BravoMaria_S6C1_repasoC *.log *.aux *.out

# Todas las reglas
all: data plots clean
