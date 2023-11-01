# Generar datos
prog: 
	g++ BravoMaria_S9CASA_EDP.cpp -o BravoMaria_S9CASA_EDP
	./BravoMaria_S9CASA_EDP

# Gráficos
plot:
	python PLOTS_BravoMaria_S9CASA_EDP.py

# Regla para limpiar archivos temporales
clean:
	rm -f BravoMaria_S9CASA_EDP *.log *.aux *.out

# Todas las reglas
all: prog plot clean
