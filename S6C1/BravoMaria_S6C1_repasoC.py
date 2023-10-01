import numpy as np
import matplotlib.pylab as plt

# Gráfica Arreglo
arreglo = np.genfromtxt("arreglo.dat")
plt.figure()
plt.scatter(arreglo[:,0],arreglo[:,1])
plt.title('Scatter del Arreglo de aleatorios')
plt.xlabel('Índice')
plt.xlabel('Valor')
plt.grid(True)
plt.savefig("aleatorios.png")

# Gráfica Impares del Arreglo hasta 800
impares = np.genfromtxt("impares.dat")
if impares.ndim == 2 and len (impares) > 1: # Deben haber por lo menos 2 impares para hacer el scatter
    plt.figure()
    plt.scatter(impares[:,0],impares[:,1])
    plt.title('Scatter de los Impares del Arreglo de aleatorios hasta 800')
    plt.xlabel('Índice')
    plt.xlabel('Valor')
    plt.grid(True)
    plt.savefig("aleatorios_con_impares.png")
else:
    print("No hay suficientes impares para realizar un scatter")
