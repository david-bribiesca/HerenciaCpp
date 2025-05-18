# Ejercicio 8: Herencia protegida - Corrección de errores y adaptación

**Enunciado:**
Corrige el siguiente código para que el método `mostrar()` de la clase derivada acceda a `nombre` (protected en la base).

```cpp
#include <iostream>
using namespace std;

class Persona {
protected:
    string nombre;
};

class Cliente : protected Persona {
public:
    void mostrar() {
        cout << nombre << endl; // Error si se cambia a private
    }
};

int main() {
    Cliente c;
    c.mostrar();
    return 0;
}
```