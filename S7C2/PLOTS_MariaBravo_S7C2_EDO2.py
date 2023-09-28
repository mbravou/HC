import matplotlib.pyplot as plt
import numpy as np

# Extraer datos
data = np.loadtxt("EDO2.dat", skiprows=1)
tiempo = data[:, 0]
posicion_euler = data[:, 1]
velocidad_euler = data[:, 2]
posicion_leapfrog = data[:, 3]
velocidad_leapfrog = data[:, 4]

# Graficas posiciones en función del tiempo
plt.figure(figsize=(10, 6))
plt.plot(tiempo, posicion_euler, label="Posición (Euler)")
plt.plot(tiempo, posicion_leapfrog, label="Posición (Leapfrog)")
plt.xlabel("Tiempo")
plt.ylabel("Posición")
plt.title("Posición vs. Tiempo")
plt.legend()
plt.grid(True)
plt.savefig("pos.pdf")

# Graficas velocidades en función del tiempo
plt.figure(figsize=(10, 6))
plt.plot(tiempo, velocidad_euler, label="Velocidad (Euler)")
plt.plot(tiempo, velocidad_leapfrog, label="Velocidad (Leapfrog)")
plt.xlabel("Tiempo")
plt.ylabel("Velocidad")
plt.title("Velocidad vs. Tiempo")
plt.legend()
plt.grid(True)
plt.savefig("vel.pdf")
