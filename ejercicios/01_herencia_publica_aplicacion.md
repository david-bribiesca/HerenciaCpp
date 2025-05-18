# Ejercicio 1: Herencia pública - Aplicación directa

**Enunciado:**
Imagina un zoológico con distintos tipos de animales. Crea una clase `Animal` con un método `comer()` y una clase `Perro` que hereda públicamente de `Animal` e implementa un método `ladrar()`. En la función `main`, crea un `Perro` y demuestra que puede llamar a ambos métodos.

**Objetivos:**
- Comprender herencia pública.
- Uso básico de métodos heredados.

```cpp
#include <iostream>
using namespace std;

// Completa aquí las clases:
class Animal {
public:
    void comer() {
        // ...
    }
};

class Perro : public Animal {
public:
    void ladrar() {
        // ...
    }
};

int main() {
    Perro miPerro;
    miPerro.comer();
    miPerro.ladrar();
    return 0;
}
```