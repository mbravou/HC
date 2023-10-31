import numpy as np
import matplotlib.pyplot as plt

# 1) Almacenamiento de datos
datos = np.loadtxt('resorte.dat')
t = datos[:, 0]
pos_x = datos[:, 1]

# 2) Estimación bayesiana de parámetros:
# 2a.) Función del modelo (omega=np.sqrt(k/m))
def modelo_fun(parametros, t):
    a, gamma, omega = parametros
    return a * np.exp(-gamma * t) * np.cos(omega * t)

# Función del modelo con k y m
def modelo_fun2(parametros, t):
    a, gamma, k, m = parametros
    return a * np.exp(-gamma * t) * np.cos(np.sqrt(k/m) * t)

# 2b.) Función de verosimilitud
def verosimilitud_fun(parametros, t, pos_x):
    modelo = modelo_fun(parametros, t) # Comentar para ""estimar"" parámetros k y m
    #modelo = modelo_fun2(parametros, t) # Descomentar para ""estimar"" parámetros k y m
    verosimilitud = np.exp(-0.5 *np.sum(((pos_x - modelo) ** 2)/(sigma**2)))
    return verosimilitud

# 2c.) Caminata
iteraciones = 100000  # número de pasos
sigma = 1

# Condiciones iniciales
aini = 7.12
gammaini = 0.69
omegaini = 18.32
mini = 1 # m ¿arbitraria?. Sí --> NO hay manera de definirla con base a los datos
kini = mini*(omegaini**2) # k definido para cuadrar con ommega dado
parametros_ini = [aini, gammaini, omegaini] # Comentar para ""estimar"" parámetros k y m
#parametros_ini = [aini, gammaini, kini, mini] # Descomentar para ""estimar"" parámetros k y m

# Algoritmo de Metropolis-Hastings
def caminata_fun(iteraciones, sigma, parametros_ini):
  parametros = np.empty((iteraciones, len(parametros_ini))) # Matriz para almacenar parametros ((número de pasos)x(cantidad de parámetros)) 
  params_old = parametros_ini # Inicializa arreglo viejo
  parametros[0] = params_old # Coloca las primeros componentes de la matriz 
  for i in range(1, iteraciones): # Bucle desde 1 para no repetir los primeros parametros_ini
    params_old = parametros[i - 1] # Lo mismo, para no repetir parametros_ini
    params_new = [np.random.normal(params_old[j], sigma) for j in range(len(parametros_ini))] # j recorre las columnas de esa fila (corresponde a cada parámetro)
    A = verosimilitud_fun(params_new, t, pos_x) / verosimilitud_fun(params_old, t, pos_x)
    if A >= 1:
      parametros[i] = params_new
    else:
      B = np.random.rand()
      if B < A:
        parametros[i] = params_new
      else:
        parametros[i] = params_old
  return parametros

# 2d.) Selección de los mejores parámetros
parametros = caminata_fun(iteraciones, sigma, parametros_ini)
verosimilitudes = [verosimilitud_fun(params, t, pos_x) for params in parametros]
mejor_indice = np.argmax(verosimilitudes)
mejores_parametros = parametros[mejor_indice]
print(f"LOS MEJORES PARÁMETROS SON a={mejores_parametros[0]}, gamma={mejores_parametros[1]} y omega={mejores_parametros[2]}") # Comentar para ""estimar"" parámetros k y m
#print(f"LOS MEJORES PARÁMETROS SON a={mejores_parametros[0]}, gamma={mejores_parametros[1]}, k={mejores_parametros[2]} y m={mejores_parametros[2]}") # Descomentar para ""estimar"" parámetros k y m


# 2f.) Gráfica de datos originales y modelo con los mejores parámetros
modelo = modelo_fun(mejores_parametros, t) # Comentar para ""estimar"" parámetros k y m
#modelo = modelo_fun2(mejores_parametros, t) # Descomentar para ""estimar"" parámetros k y m
plt.plot(t, pos_x, label='Datos Originales')
plt.plot(t, modelo, label='Modelo Ajustado', linestyle='--')
plt.legend()
plt.savefig('Resorte.pdf')

# 3) omega=np.sqrt(k/m), ¿Estimar k, m? 
print("NO es posible determinar k y m de manera individual. Aquí no se puede extraer esa información de los datos, el conocimiento del fenómeno del resorte que tenemos es limitado, el comportamiento de pos_x no da ningún indicio de cuál podría ser la masa sin saber la constante de elasticidad y viceversa. Esto se debe al modelo físico que explica el movimiento, tenemos (x = a*exp(-gamma*t)*cos(omega*t)) no depende de k y m individualmente sino que estas dos construyen otra constante (omega=sqrt(k/m)), y este ommega sí que aparece explícita e INDIVIDUALMENTE en la ecuación del modelo. Para estimar uno de los dos parámetros tendríamos que necesariamente conocer uno, por ejemplo: si a = b + c y tenemos que a = 2, podría ser que b = 1 y c = 1, o  b = 2 y c = 0, o  b = 1.5 y c = 0.5, con esa indeterminación es imposible estimar correctamente los parámetros b y c individualmente. Para ver esto, podríamos sencillamente cambiar el código y ver que pasa. Lo que sucederá es que k y m van a dar unos valores numéricos físicamente absurdos y además claramente acomodados de tal manera que la estimación buena sea la de su combinación ommega, esto se ve porque k y m dan iguales (ver los comentarios del codigo que indican qué líneas habilitar y deshabilitar).")
