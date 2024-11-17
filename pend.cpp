#include <iostream>
#include <vector>
#include <limits> 


using namespace std;

struct Punto {
    float x, y;
};

// Función para calcular la pendiente entre dos puntos
float calcularPendiente(Punto p1, Punto p2) {
    if (p2.x - p1.x == 0) {
        return numeric_limits<float>::infinity(); // Pendiente indefinida (línea vertical)
    } else {
        return (p2.y - p1.y) / (p2.x - p1.x);
    }
}

// Función para determinar el cuadrante de un punto
string determinarCuadrante(Punto p) {
    if (p.x > 0 && p.y > 0) {
        return "primer";
    } else if (p.x < 0 && p.y > 0) {
        return "segundo";
    } else if (p.x < 0 && p.y < 0) {
        return "tercer";
    } else if (p.x > 0 && p.y < 0) {
        return "cuarto";
    } else if (p.x == 0 && p.y == 0) {
        return "origen";
    } else if (p.x == 0) {
        return "eje Y";
    } else {
        return "eje X";
    }
}

int main() {
    vector<Punto> puntos;
    int n;

    cout << "Ingrese el número de puntos: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        Punto p;
        cout << "Ingrese la coordenada x del punto " << i + 1 << ": ";
        cin >> p.x;
        cout << "Ingrese la coordenada y del punto " << i + 1 << ": ";
        cin >> p.y;
        puntos.push_back(p);
        
        cout << "El punto (" << p.x << ", " << p.y << ") pertenece al " << determinarCuadrante(p) << " cuadrante." << endl;

    }

    // Calcular la pendiente entre el primer punto y todos los demás
    float pendiente = calcularPendiente(puntos[0], puntos[1]);
    bool todosEnLaMismaLinea = true;

    for (int i = 2; i < n; ++i) {
        float pendienteActual = calcularPendiente(puntos[0], puntos[i]);
        if (pendiente != pendienteActual) {
            todosEnLaMismaLinea = false;
            break;
        }
    }

    if (todosEnLaMismaLinea) {
        // Calcular la ecuación de la recta (y = mx + b)
        float b = puntos[0].y - pendiente * puntos[0].x;
        cout << "Todos los puntos pertenecen a la misma línea." << endl;
        cout << "La ecuación de la recta es: y = " << pendiente << "x + " << b << endl;
        
        
    } else {
        cout << "Los puntos no pertenecen a la misma línea." << endl;
    }

    return 0;
}