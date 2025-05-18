# Ejercicio 3: Herencia privada - Detección y corrección de errores

**Enunciado:**
El siguiente código intenta heredar miembros públicos, pero algo falla. Identifica el error y corrígelo.

```cpp
#include <iostream>
using namespace std;

class Vehiculo {
public:
    void encender() {
        cout << "Vehículo encendido" << endl;
    }
};

class Coche : private Vehiculo {
};

int main() {
    Coche miCoche;
    miCoche.encender(); // ¿Por qué falla?
    return 0;
}
```