# -*- coding: utf-8 -*-
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation

# Cargar los datos de los archivos
data = np.loadtxt("resultados.dat")
data2 = np.loadtxt("resultados2.dat")

# Número de puntos espaciales
num_points = data.shape[1]

# Tiempos en los que se va a graficar la cuerda
times_to_plot = [0, 1, 2, 4, 18, 21]

# Gráficas
fig, axes = plt.subplots(2, 3, figsize=(12, 8))
fig.suptitle("Cuerda en diferentes tiempos")

c = 300.0
L = 2.0
num_points = 100
dx = L / num_points
dt = (0.5 * dx / c) * 100 # resultados.dat almacena cada 100 tiempos
    
for i, ax in enumerate(axes.flat):
    time_index = times_to_plot[i]
    time = dt * time_index
    time_label = '{:.4f}'.format(time)
    ax.plot(np.linspace(0, 2, num_points), data[time_index])
    ax.set_title(f"Tiempo {time_index}: {time_label} s")
    ax.set_xlabel("Posición (x)")
    ax.set_ylabel("Amplitud")
    ax.set_ylim(-0.125, 0.125)

plt.tight_layout()
plt.savefig('grafica_cuerda.pdf')

# Visualización de la cuerda en animación
x_values = np.linspace(0, L, num_points)
fig, ax = plt.subplots()
line, = ax.plot(x_values, data2[0])
ax.set_ylim(-0.125, 0.125)
ax.set_ylabel('Posición (x)')
ax.set_ylabel('Amplitud')
ax.set_title('Evolución de la onda en el tiempo')

def animate(t):
    line.set_ydata(data2[t])
    return line,

ani = animation.FuncAnimation(fig, animate, frames=len(data2), interval=100, blit=True)
ani.save('animacion_cuerda.gif', dpi=300)


