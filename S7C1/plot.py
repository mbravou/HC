import csv
import matplotlib.pyplot as plt

# Listas para Arreglos que almacenan los datos
Tiempo_A = []
Sol_A = []
Tiempo = []
Euler = []
RK4 = []

# Extraer datos del csv
with open('datos.csv', 'r') as file:
    reader = csv.reader(file)
    next(reader)  # Saltar primera fila
    for row in reader:
        Tiempo_A.append(float(row[0]))
        Sol_A.append(float(row[1]))
        Tiempo.append(float(row[2]))
        Euler.append(float(row[3]))
        RK4.append(float(row[4]))

# Gráfica
plt.figure(figsize = (10, 6))
plt.plot(Tiempo_A, Sol_A, label='Solución Analítica', linestyle='-', color='blue')
plt.plot(Tiempo, Euler, label='Euler', linestyle='--', color='green')
plt.plot(Tiempo, RK4, label='Runge-Kutta 4', linestyle='-.', color='red')
plt.title('Soluciones Numéricas para dy(t)/dt = -y(t) \n Intervalo de Iteración h = 0.1')
plt.xlabel('Tiempo')
plt.ylabel('Solución y(t)')
plt.legend()
plt.grid(True)
plt.savefig("plot_sol.pdf")
