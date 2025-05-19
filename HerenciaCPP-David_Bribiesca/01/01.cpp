#include <iostream>
using namespace std;

// Completa aquí las clases:
class Animal {
public:
    Animal(string s) : nombre(s) {}
    string nombre;
    void comer() {
        cout << nombre << " está comiendo: ñam ñam" << endl;
    }
};

class Perro : public Animal {
public:
    Perro(string s) : Animal(s) {}
    void ladrar() {
        cout << nombre << " dice: Woof Woof" << endl;
    }
};

int main() {
    Perro miPerro("Max");
    miPerro.comer();
    miPerro.ladrar();
    return 0;
}