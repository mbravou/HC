#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>

using std::vector;

// Ecuación diferencial: f =  dy(t)/dt = -y(t)
double f(double t, double y) {
  return -y;
}

// Solución Analítica
struct solucion {
  vector<double> Tiempo_A; //.. Vector que guarda los tiempos para la solución analítica
  vector<double> Sol_A; //..... Vector que guarda los y de la solución analítica
};
solucion sol(double t0, double y0, double tf) {
  double t = t0; //.......... t0: Tiempo inicial 
  double y = y0; //.......... y0: y inicial
  // Intervalo de iteración pequeño para que la solución analítica se vea lo más exacta posible
  double ha = 0.0001; 
  solucion resultado;
  while (t <= tf) { //....... tf: Tiempo final
    resultado.Tiempo_A.push_back(t);
    resultado.Sol_A.push_back(y);
    y = exp(-t);
    t += ha;
  }
  return resultado;
}
  

// Método de Euler
struct met_euler {
  vector<double> Tiempo; //.. Vector que guarda los tiempos
  vector<double> Euler; //... Vector que guarda los y del método de Euler
  vector<double> Error; //... Vector que guarda los errores
};
met_euler euler(double t0, double y0, double h, double tf) {
  double t = t0;
  double y = y0;
  double e = 0.0; // Variable del error
  met_euler resultado;
  while (t <= tf) {
    double ya = exp(-t); // ya: sol. analítica
    resultado.Tiempo.push_back(t);
    resultado.Euler.push_back(y);
    e = std::abs(ya - y)/ya;
    resultado.Error.push_back(e);
    y = y + h * f(t, y);
    t += h;
  }
  return resultado;
}

// Método de Runge-Kutta de cuarto orden
struct met_rk4 {
  vector<double> Tiempo;
  vector<double> RK4;
  vector<double> Error;
};
met_rk4 rk4(double t0, double y0, double h, double tf) {
  double t = t0;
  double y = y0;
  double e = 0.0;
  met_rk4 resultado; 
  while (t <= tf) {
    double ya = exp(-t);
    resultado.Tiempo.push_back(t);
    resultado.RK4.push_back(y);
    e = std::abs(ya - y)/ya;
    resultado.Error.push_back(e);
    double k1 = h * f(t, y);
    double k2 = h * f(t + h/2, y + k1/2);
    double k3 = h * f(t + h/2, y + k2/2);
    double k4 = h * f(t + h, y + k3);
    y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
    t += h;
  }
  return resultado;
}

int main() {
  double t0 = 0.0;      
  double y0 = 1.0;      
  double h = 0.1;      
  double tf = 3.0;
  solucion analitica = sol(t0, y0, tf);
  met_euler sol_euler = euler(t0, y0, h, tf);
  met_rk4 sol_rk4 = rk4(t0, y0, h, tf);
  // Vectores con las soluciones
  vector<double> Tiempo_A = analitica.Tiempo_A;
  vector<double> Tiempo = sol_euler.Tiempo;
  vector<double> Sol_A = analitica.Sol_A;
  vector<double> Euler = sol_euler.Euler;
  vector<double> RK4 = sol_rk4.RK4;
  vector<double> Error_Euler = sol_euler.Error;
  vector<double> Error_RK4 = sol_rk4.Error;
  // Archivo que almacene la solución analítica
  std::ofstream file1("analitica.dat");
  file1 << "Tiempo_A Analitica\n";
  for (size_t i = 0; i < Tiempo_A.size(); i++) {
    file1 << Tiempo_A[i] << " " << Sol_A[i] << "\n";
  }
  // Archivo que almacene las soluciones de los métodos
  std::ofstream file2("metodos.dat");
  file2 << "Tiempo Euler RK4 Error_Euler Error_RK4\n";
  for (size_t i = 0; i < Tiempo.size(); i++) {
    file2 << Tiempo [i] << " " << Euler[i] << " " << RK4[i] << " " << Error_Euler[i] << " " << Error_RK4[i] << "\n";
  }
  return 0;
}
 
