#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using std::vector;

// Ecuación diferencial: d^2 x(t)/dt^2 = - (k/m) x(t)
double f(double t, double x, double v, double k, double m) {
  return -(k/m)*x;
}

// Método de Euler
struct met_euler {
    vector<double> Tiempo;
    vector<double> Posicion; // Valores x(t) calculados con Euler
    vector<double> Velocidad; // Valores dx/dt calculados con Euler
};
met_euler euler(double t0, double x0, double v0, double k, double m, double h, double tf) {
    double t = t0;
    double x = x0;
    double v = v0;
    met_euler resultado;
    while (t <= tf) {
        resultado.Tiempo.push_back(t);
        resultado.Posicion.push_back(x);
        resultado.Velocidad.push_back(v);
        double a = f(t, x, v, k, m); // Aceleración
        x = x + v * h; // Actualización de la posición
        v = v + a * h; // Actualización de la velocidad
        t += h;
    }
    return resultado;
}

// Algoritmo Leapfrog
struct met_leapfrog {
    vector<double> Tiempo;
    vector<double> Posicion;
    vector<double> Velocidad;
};
met_leapfrog leapfrog(double t0, double x0, double v0, double k, double m, double h, double tf) {
    double t = t0;
    double x = x0;
    double v = v0;
    met_leapfrog resultado;
    while (t <= tf) {
        resultado.Posicion.push_back(x);
        resultado.Velocidad.push_back(v);
	double a = f(t, x, v, k, m);    
        x = x + v * h + 0.5 * a * h * h;
        v = v + a * h;
        t += h;
    }
    return resultado;
}

int main() {
    double t0 = 0.0;
    double x0 = 0.1;
    double v0 = 0.0;
    double h = 0.0001;
    double tf = 5.0;
    double k = 50.0;
    double m = 0.2;
    met_euler sol_euler = euler(t0, x0, v0, k, m, h, tf);
    met_leapfrog sol_leapfrog = leapfrog(t0, x0, v0, k, m, h, tf);
    // Vectores con las soluciones
    vector<double> Tiempo = sol_euler.Tiempo;
    vector<double> Posicion_Euler = sol_euler.Posicion;
    vector<double> Velocidad_Euler = sol_euler.Velocidad;
    vector<double> Posicion_Leapfrog = sol_leapfrog.Posicion;
    vector<double> Velocidad_Leapfrog = sol_leapfrog.Velocidad;
    // Archivo que almacene las soluciones de los métodos
    std::ofstream file("EDO2.dat");
    file << "Tiempo Posicion_Euler Velocidad_Euler Posicion_Leapfrog Velocidad_Leapfrog\n";
    for (size_t i = 0; i < Tiempo.size(); i++) {
        file << Tiempo[i] << " " << Posicion_Euler[i] << " " << Velocidad_Euler[i] << " " << Posicion_Leapfrog[i] << " " << Velocidad_Leapfrog[i] << "\n";
    }

    return 0;
}
