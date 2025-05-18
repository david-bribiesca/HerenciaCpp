# Ejercicio 9: Herencia privada - Implementación parcial + análisis

**Enunciado:**
Completa una clase `Sensor` que será usada por `SistemaAlarma`, pero sin exponer sus métodos públicamente. Usa herencia `private` y llama internamente a `detectarMovimiento()`.

```cpp
#include <iostream>
using namespace std;

class Sensor {
protected:
    void detectarMovimiento() {
        cout << "Movimiento detectado" << endl;
    }
};

class SistemaAlarma : private Sensor {
public:
    void verificar() {
        // Llama a detectarMovimiento();
    }
};

int main() {
    SistemaAlarma sa;
    sa.verificar();
    return 0;
}
```