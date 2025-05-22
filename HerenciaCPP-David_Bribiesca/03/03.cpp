#include <iostream>
using namespace std;

class Vehiculo {
public:

    void encender() {
        cout << "Vehículo encendido" << endl;
    }
};

class Coche : public Vehiculo {
};

int main() {
    Coche miCoche;
    miCoche.encender(); // ¿Por qué falla?
    // fallaba porque en la linea 12 al heredar se estaba privado el acceso a la clase vehiculo
    return 0;
}