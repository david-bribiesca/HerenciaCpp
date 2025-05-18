# Ejercicio 7: Herencia pública - Código incompleto con override

**Enunciado:**
Completa una jerarquía `Instrumento` → `Guitarra`, usando `override` en un método `tocar()`. Muestra polimorfismo con punteros.

```cpp
#include <iostream>
using namespace std;

class Instrumento {
public:
    virtual void tocar() {
        // ...
    }
};

class Guitarra : public Instrumento {
public:
    void tocar() override {
        // ...
    }
};

void probar(Instrumento* inst) {
    inst->tocar();
}

int main() {
    Guitarra g;
    probar(&g);
    return 0;
}
```