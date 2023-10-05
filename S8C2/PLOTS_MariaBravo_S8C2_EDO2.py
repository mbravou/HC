import matplotlib.pyplot as plt
import numpy as np

# Extraer datos
data = np.loadtxt("EDO2.dat", skiprows=1)
tiempo = data[:, 0]
posicionx_euler = data[:, 1]
posiciony_euler = data[:, 2]
posicionx_leapfrog = data[:, 3]
posiciony_leapfrog = data[:, 4]

# Gráficas Órbitas Caso 1
fig, axs = plt.subplots(2 ,1, figsize=(6, 8), sharex=True)
fig.suptitle("Órbita Caso 1 (Sol estático)")
axs[0].plot(posicionx_euler, posiciony_euler)
axs[0].set_title("Método de Euler")
axs[0].grid(True)
axs[1].plot(posiciony_leapfrog, posiciony_leapfrog)
axs[1].set_title("Algoritmo de Leapfrog")
axs[1].grid(True)
#plt.xlabel("")
plt.savefig("Caso1.pdf")

# Graficas Órbitas Caso 2
#fig2, axs2 = plt.subplots(2 ,1, figsize=(6, 8), sharex=True)
#fig2.suptitle("Velocidad vs. Tiempo")
#axs2[0].plot(tiempo, velocidad_euler)
#axs2[0].set_ylabel("Velocidad")
#axs2[0].set_title("Método de Euler")
#axs2[0].grid(True)
#axs2[1].plot(tiempo, velocidad_leapfrog)
#axs2[1].set_ylabel("Velocidad")
#axs2[1].set_title("Algoritmo de Leapfrog")
#axs2[1].grid(True)
#plt.xlabel("Tiempo")
#plt.savefig("vel.pdf")
