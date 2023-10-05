import matplotlib.pyplot as plt
import numpy as np

# Extraer datos
data = np.loadtxt("EDO2.dat", skiprows=1)
tiempo = data[:, 0]
posicion_euler = data[:, 1]
velocidad_euler = data[:, 2]
posicion_leapfrog = data[:, 3]
velocidad_leapfrog = data[:, 4]
posicion_rk4 = data[:, 5]
velocidad_rk4 = data[:, 6]

# Gráficas posiciones en función del tiempo
fig, axs = plt.subplots(3 ,1, figsize=(6, 8), sharex=True)
fig.suptitle("Posición vs. Tiempo")
axs[0].plot(tiempo, posicion_euler)
axs[0].set_ylabel("Posición")
axs[0].set_title("Método de Euler")
axs[0].grid(True)
axs[1].plot(tiempo, posicion_leapfrog)
axs[1].set_ylabel("Posición")
axs[1].set_title("Algoritmo de Leapfrog")
axs[1].grid(True)
axs[2].plot(tiempo, posicion_rk4)
axs[2].set_ylabel("Posición")
axs[2].set_title("Método de Runge Kutta de orden 4")
axs[2].grid(True)
plt.xlabel("Tiempo")
plt.savefig("pos.pdf")

# Graficas velocidades en función del tiempo
fig2, axs2 = plt.subplots(3 ,1, figsize=(6, 8), sharex=True)
fig2.suptitle("Velocidad vs. Tiempo")
axs2[0].plot(tiempo, velocidad_euler)
axs2[0].set_ylabel("Velocidad")
axs2[0].set_title("Método de Euler")
axs2[0].grid(True)
axs2[1].plot(tiempo, velocidad_leapfrog)
axs2[1].set_ylabel("Velocidad")
axs2[1].set_title("Algoritmo de Leapfrog")
axs2[1].grid(True)
axs2[2].plot(tiempo, velocidad_rk4)
axs2[2].set_ylabel("Velocidad")
axs2[2].set_title("Método de Runge Kutta de orden 4")
axs2[2].grid(True)
plt.xlabel("Tiempo")
plt.savefig("vel.pdf")
