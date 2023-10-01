# Generar datos
data:
	g++ BravoMaria_S6CASA_repasoC.cpp -o BravoMaria_S6CASA_repasoC
	./BravoMaria_S6CASA_repasoC

# Gráficos
plots:
	python BravoMaria_S6CASA_repasoC.py

# Regla para limpiar archivos temporales
clean:
	rm -f BravoMaria_S6CASA_repasoC *.log *.aux *.out

# Todas las reglas
all: data plots clean
