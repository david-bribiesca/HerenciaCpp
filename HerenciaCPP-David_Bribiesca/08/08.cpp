#include <iostream>
using namespace std;

class Persona {
protected:
    string nombre;
public:
    Persona(string n):nombre(n){}

    string getNombre(){
        return nombre;
    }
};

class Cliente : protected Persona {
public:
    Cliente(string n):Persona(n){}
    void mostrar() {
        cout << "nombre: " <<  getNombre() << endl; // Error si se cambia a private
    }
};

int main() {
    Cliente c("David");
    c.mostrar();
    return 0;
}