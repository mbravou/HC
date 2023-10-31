# Ejercicio 1 
import numpy as np 
import matplotlib.pylab as plt 

# Forma funcional de la distribución
def mifun(x):
  x_0 = 3.0
  a = 0.01
  return np.exp(-(x**2))/((x-x_0)**2 + a**2)

# Muestreo con el Algoritmo de Metropolis-Hastings
def muestreofun(pasos, sigma):
  muestras = np.empty(0) # Arreglo para almacenar las muestras
  x_old = np.random.uniform(-4,4) # Valor inicial
  muestras = np.append(muestras, x_old)
  for i in range(pasos):
    x_new = np.random.normal(muestras[i], sigma) # Generar x_new a partir de una distribución gaussiana
    A = mifun(x_new)/mifun(muestras[i]) # Calcular la razón de aceptación
    if A >= 1:
      muestras = np.append(muestras, x_new)
    else:
      B = np.random.rand()
      if B < A:
        muestras = np.append(muestras, x_new)
      else:
        muestras = np.append(muestras, muestras[i])
  return muestras

# Parámetros (sigma, pasos)
parametros = [(5, 100000), 
              (0.2, 100000), 
              (0.01, 100000), 
              (0.1, 1000), 
              (0.1, 100000), 
              (0.1, 500000)]

# Gráficas de los histogramas
for i, (sigma, pasos) in enumerate(parametros):
  plt.figure()
  x = np.linspace(-4, 4, 1000)
  normalization = np.trapz(mifun(x), x) # Calcular integral para normalizar
  plt.plot(x, mifun(x)/normalization, label = 'Distribución')
  muestras = muestreofun(pasos, sigma)
  plt.hist(muestras, bins = 150, density=True, label='Muestras')
  plt.legend()
  plt.xlabel('x')
  plt.ylabel('Densidad de Probabilidad')
  plt.title("Histograma: sigma = " + str(sigma) + ", pasos = " + str(pasos))
  plt.savefig("histograma_" + str(sigma) + "_" + str(pasos) + ".pdf")
