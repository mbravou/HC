import matplotlib.pyplot as plt

# Listas para Arreglos que almacenan los datos
Tiempo_A = []
Sol_A = []
Tiempo = []
Euler = []
RK4 = []
Error_Euler = []
Error_RK4 = []

# Extraer datos
with open('analitica.dat', 'r') as file:
    next(file)  # Saltar primera fila
    for line in file:
        data = line.strip().split()
        Tiempo_A.append(float(data[0]))
        Sol_A.append(float(data[1]))
with open('metodos.dat', 'r') as file:
    next(file)  # Saltar primera fila
    for line in file:
        data = line.strip().split()
        Tiempo.append(float(data[0]))
        Euler.append(float(data[1]))
        RK4.append(float(data[2]))
        Error_Euler.append(float(data[3]))
        Error_RK4.append(float(data[4]))

# Gráfica soluciones
plt.figure(figsize = (10, 6))
plt.plot(Tiempo_A, Sol_A, label='Solución Analítica', linestyle='-', color='blue')
plt.plot(Tiempo, Euler, label='Euler', linestyle='-', color='green')
plt.plot(Tiempo, RK4, label='Runge-Kutta 4', linestyle='-.', color='red')
plt.title('Soluciones Numéricas para dy(t)/dt = -y(t) \n Intervalo de Iteración h = 0.1')
plt.xlabel('Tiempo')
plt.ylabel('Solución y(t)')
plt.legend()
plt.grid(True)
plt.savefig("plot_sol.pdf")

# Gráfica errores
plt.figure(figsize=(10, 6))
plt.plot(Tiempo, Error_Euler, label='Error Euler', linestyle='-', color='green')
plt.plot(Tiempo, Error_RK4, label='Error Runge-Kutta 4', linestyle='-.', color='red')
plt.title('Errores en las Soluciones Numéricas')
plt.xlabel('Tiempo')
plt.ylabel('Error')
plt.legend()
plt.grid(True)
plt.savefig("plot_errores.pdf")
