#include <iostream>
using namespace std;

// Completa aquí las clases:
class Animal {
public:
    void comer() {
        cout << "El animal está comiendo." << endl;
    }
};

class Perro : public Animal {
public:
    void ladrar() {
        cout << "Woof Woof" << endl;
    }
};

int main() {
    Perro miPerro;
    miPerro.comer();
    miPerro.ladrar();
    return 0;
}