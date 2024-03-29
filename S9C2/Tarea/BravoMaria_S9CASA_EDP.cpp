#include <iostream>
#include <vector>
#include <fstream>

int main() {
    double c = 300.0;
    double L = 2.0;
    double x_0 = L / 2.0; // Coordenada x inicial
    double y_0 = 0.1; // Coordenada y inicial
    int num_points = 100;
    double dx = L / num_points;
    double dt = 0.5 * dx / c; // En este caso 1/30000
    //double dt = 3 * dx / c; // En este caso 1/5000
    double t_final = 0.1;
    int num_time_steps = static_cast<int>(t_final / dt); // En este caso 3000 tiempos

    // Inicialización de condiciones iniciales en el arreglo u_past
    std::vector<double> u_past(num_points);
    for (int i = 0; i < num_points; ++i) {
        double x = i * dx;
        if (0.0 <= x && x <= L / 2.0) {
            u_past[i] = (y_0 / x_0) * x; // Recta ascendente
        } else if (L / 2.0 < x && x <= L) {
            u_past[i] = (y_0 / (x_0 - L)) * (x - L); // Recta descendente
        }
    }

    // Inicialización del arreglo u_present con condición inicial v_0 = 0
    std::vector<double> u_present(num_points);
    for (int i = 1; i < num_points - 1; ++i) { // Desde 1 porque para i=0 --> [-1]
        u_present[i] = u_past[i] + 0.5 * (c * c * dt * dt / (dx * dx)) * (u_past[i + 1] - 2.0 * u_past[i] + u_past[i - 1]);
    }

    // Resolución de la ecuación de onda en el tiempo con cálculo de u_future
    std::vector<double> u_future(num_points);
    std::vector<std::vector<double>> results; // Lista para almacenar resultados en el tiempo
    std::vector<std::vector<double>> results2; // Lista que guarda 10 veces más datos
    for (int t = 0; t < num_time_steps; ++t) {
        if (t % 100 == 0) { // Guardar cada 100 pasos de tiempo, habrían 30 tiempos
            results.push_back(u_present); // El dato más actualizado u_future se almacena en u_present
        }
        if (t % 10 == 0) { // Guardar cada 10 pasos de tiempo, habrían 300 tiempos
            results2.push_back(u_present); // El dato más actualizado u_future se almacena en u_present
        }
        for (int i = 1; i < num_points - 1; ++i) {
            u_future[i] = 2.0 * u_present[i] - u_past[i] + (c * c * dt * dt / (dx * dx)) * (u_present[i + 1] - 2.0 * u_present[i] + u_present[i - 1]);
        }
        // Actualizar arreglos (almacena u_present en u_past, u_future en u_present)
        u_past = u_present;
        u_present = u_future;
        // Reestablecer u_future garantiza que los valores anteriores no se acumulen o interfieran con los nuevos cálculos:
        u_future.assign(num_points, 0.0);
    }

    // Guardar los resultados en un archivo .dat
    std::ofstream outputFile("resultados.dat");
    for (const auto &row : results) {
        for (double value : row) {
            outputFile << value << " ";
        }
        outputFile << std::endl;
    }
    outputFile.close();
    std::ofstream outputFile2("resultados2.dat");
    for (const auto &row : results2) {
        for (double value : row) {
            outputFile2 << value << " ";
        }
        outputFile2 << std::endl;
    }
    outputFile2.close();

    return 0;
}

