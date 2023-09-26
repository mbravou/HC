#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>

// 1. Inicializar dos variables globales
int x = 17;
float y = 2.8;

// 2. Imprimir los valores de las variables globales
void Variables() {
    std::cout << "2. \n La primera variable tiene un valor de " << x << " y la segunda variable tiene un valor de " << y << std::endl;
}

// 3. Calcular el valor de la segunda variable dividida por la primera
void Division() {
    float z = y / static_cast<float>(x);
    std::cout << "\n. 3. \n El resultado de dividir la segunda variable entre la primera es " << z << std::endl;
}

// 4. Crear un arreglo con 300 números enteros aleatorios entre 0 y 900
std::vector<int> crearArreglo() {
    std::vector<int> arreglo;
    std::srand(std::time(nullptr));
    for (int i = 0; i < 300; ++i) {
        int aleatorio = std::rand() % 901; // Números entre 0 y 900
        arreglo.push_back(aleatorio);
    }
    return arreglo;
}

// 5. Imprimir elementos del arreglo
void imprimirArreglo(const std::vector<int>& arreglo) {
    std::cout << "\n. 5. \n Arreglo" <<std::endl;
    for (int numero : arreglo) {
        std::cout << numero << " ";
    }
    std::cout << std::endl;
}

// 6. Imprimir el quinto elemento del arreglo
void QuintoElemento(const std::vector<int>& arreglo) {
    std::cout << "\n. 6. \n El quinto elemento del arreglo es: " << arreglo[4] << std::endl;
}
// 7. Obtener la longitud del arreglo e imprimir
void LongitudArreglo(const std::vector<int>& arreglo) {
    std::cout << "\n. 7. \n La longitud del arreglo es " << arreglo.size() << std::endl;
}

// 8. Función que recibe dos variables y retorna su potencia
float Potencia(float mivarflotante, int mivarentera) {
    return std::pow(mivarflotante, mivarentera);
}

// 9. Imprimir potencia de variables
//Hice que todos los items del ejercicio sean funciones, al final las llamaré a todas en la fubnción main

// 10. Función que retorna el mínimo del arreglo
int Minimo(const std::vector<int>& arreglo) {
    int minimo = arreglo[0];
    for (int numero : arreglo) {
        if (numero < minimo) {
            minimo = numero;
        }
    }
    return minimo;
}

// 11. Función que imprime números impares y detiene la impresión cuando encuentra un número mayor a 800
void ImparesHasta800(const std::vector<int>& arreglo) {
    std::cout << "\n. 11. \n" <<std::endl;
    for (int numero : arreglo) {
        if (numero % 2 == 1) {
            std::cout << "Número impar: " << numero << std::endl;
        }
        if (numero > 800) {
            break;
        }
    }
}

int main() {
    // 2. Imprimir valores de variables globales
    Variables();

    // 3. Calcular y imprimir resultado
    Division();

    // 4. Crear un arreglo de números aleatorios
    std::vector<int> arreglo = crearArreglo();

    // 5. Imprimir todos los elementos del arreglo
    imprimirArreglo(arreglo);

    // 6. Imprimir el quinto elemento del arreglo
    QuintoElemento(arreglo);

    // 7. Imprimir la longitud del arreglo
    LongitudArreglo(arreglo);

    // 8. Llamar a la función y mostrar su resultado
    float resultadoPotencia = Potencia(17.5, 5);
    std::cout << "\n. 8. \n El resultado de la potencia es: " << resultadoPotencia << std::endl;

    // 10. Encontrar y mostrar el mínimo del arreglo
    int minimo = Minimo(arreglo);
    std::cout << "\n. 10. \n El mínimo del arreglo es: " << minimo << std::endl;

    // 11. Imprimir números impares hasta encontrar un número mayor a 800
    ImparesHasta800(arreglo);

    return 0;
}
