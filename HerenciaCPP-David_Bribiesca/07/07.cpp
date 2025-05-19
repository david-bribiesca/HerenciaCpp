#include <iostream>
using namespace std;

class Instrumento {
public:
    Instrumento(string s) : marca(s) {}
    string marca;
    virtual void tocar() {
        cout << "Tocando un instrumento: " << marca << endl;
    }
};

class Guitarra : public Instrumento {
public:
    Guitarra(string s) : Instrumento(s) {}
    void tocar() override {
        cout << "Tocando la guitarra: " << marca << endl;
    }
};

void probar(Instrumento* inst) {
    inst->tocar();
}

int main() {
    Guitarra g("Fender");
    probar(&g);
    return 0;
}