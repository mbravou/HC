#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using std::vector;

// Constantes
const double G = 6.67430e-11;  // Constante de gravitación universal
const double M_S = 1.989e30;   // Masa del Sol
const double M_T = 5.972e24;   // Masa de la Tierra

// Caso 1: Sol estático
// Ecuación diferencial: a = F/m --> d^2 r(t)/dt^2 = -(G*M_S)/(r²(t))
double f(double r) {
  return -(G*M_S)/(r*r);
}

// Método de Euler
struct met_euler {
  vector<double> Tiempo;
  vector<double> PosicionX;
  vector<double> PosicionY;
  vector<double> VelocidadX;
  vector<double> VelocidadY;
};
met_euler euler(double t0, double x0, double y0, double vx0, double vy0, double h, double tf) {
  double t = t0;
  double x = x0;
  double y = y0;
  double vx = vx0;
  double vy = vy0;
  met_euler resultado;
  while (t <= tf) {
    resultado.Tiempo.push_back(t);
    resultado.PosicionX.push_back(x);
    resultado.PosicionY.push_back(y);
    resultado.VelocidadX.push_back(vx);
    resultado.VelocidadY.push_back(vy);
    double r = sqrt(x*x + y*y); // Distancia
    double a = f(r); // Aceleración
    x = x + vx * h; // Actualización de la posición en x
    y = y + vy * h; // Actualización de la posición en y
    vx = vx + (x/r)*a * h; // Actualización de la velocidad en x
    vy = vy + (y/r)*a * h; // Actualización de la velocidad en y
    t += h;
  }
  return resultado;
}

// Algoritmo Leapfrog
struct met_leapfrog {
  vector<double> Tiempo;
  vector<double> PosicionX;
  vector<double> PosicionY;
  vector<double> VelocidadX;
  vector<double> VelocidadY;
};
met_leapfrog leapfrog(double t0, double x0, double y0, double vx0, double vy0, double h, double tf) {
  double t = t0;
  double x = x0;
  double y = y0;
  double vx = vx0;
  double vy = vy0;
  met_leapfrog resultado;
  while (t <= tf) {
    resultado.PosicionX.push_back(x);
    resultado.PosicionY.push_back(y);
    resultado.VelocidadX.push_back(vx);
    resultado.VelocidadY.push_back(vy);
    double r = sqrt(x*x + y*y);
    double a = f(r);
    x = x + vx * h + 0.5 * (x/r) * a * h * h;
    y = y + vy * h + 0.5 * (y/r) * a * h * h;
    vx = vx + (x/r) *a * h;
    vy = vy + (y/r) *a * h;
    t += h;
  }
  return resultado;
}

int main() {
  double r0 = 1.496e11;  // Distancia inicial de la Tierra al Sol
  double v0 = 29783.0;  // Velocidad inicial de la Tierra
  double t0 = 0.0;
  double tf = 31536000.0;  // 1 año
  double h = 3600.0; // 1 hora
  met_euler sol_euler = euler(t0, r0, 0.0, 0.0, v0, h, tf);
  met_leapfrog sol_leapfrog = leapfrog(t0, r0, 0.0, 0.0, v0, h, tf);
  // Vectores con las soluciones
  vector<double> Tiempo = sol_euler.Tiempo;
  vector<double> PosicionX_Euler = sol_euler.PosicionX;
  vector<double> PosicionY_Euler = sol_euler.PosicionY;
  //vector<double> Velocidad_Euler = sol_euler.Velocidad;
  vector<double> PosicionX_Leapfrog = sol_leapfrog.PosicionX;
  vector<double> PosicionY_Leapfrog = sol_leapfrog.PosicionY;
  //vector<double> Velocidad_Leapfrog = sol_leapfrog.Velocidad;
  // Archivo que almacene las soluciones de los métodos
  std::ofstream file("EDO2.dat");
  file << "Tiempo PosicionX_Euler PosicionY_Euler PosicionX_Leapfrog PosicionX_Leapfrog\n";
  for (size_t i = 0; i < Tiempo.size(); i++) {
    file << Tiempo[i] << " " << PosicionX_Euler[i] << " " << PosicionY_Euler[i] << " " << PosicionX_Leapfrog[i] << " " << PosicionY_Leapfrog[i] << "\n";
  }
  return 0;
}
