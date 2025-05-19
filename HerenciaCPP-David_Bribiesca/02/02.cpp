#include <iostream>
using namespace std;

class Persona {
protected:
    string nombre;
    int edad;
public:
    Persona(string s, int e) : nombre(s), edad(e) {}
    void _mostrarDatos() {
        cout << "Nombre: " << nombre << endl;
        cout << "Edad: " << edad << endl;
    }
    void setNombre(string n) {
        nombre = n;
    }
    void setEdad(int e) {
        edad = e;
    }
};

class Empleado : protected Persona {
public:
    Empleado(string s, int e) : Persona(s, e) {}
    void mostrarDatos() {
        _mostrarDatos();
        cout << "Estatus: Empleado" << endl;
    }
};

int main() {
    Empleado emp("Juan", 30);
    emp.mostrarDatos();
    return 0;
}