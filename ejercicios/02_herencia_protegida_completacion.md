# Ejercicio 2: Herencia protegida - Completación de código

**Enunciado:**
Completa el siguiente código para que una clase `Empleado` herede de `Persona` usando herencia protegida. El método `mostrarDatos()` debe acceder a los atributos protegidos de la clase base.

```cpp
#include <iostream>
using namespace std;

class Persona {
protected:
    string nombre;
    int edad;
};

class Empleado : protected Persona {
public:
    void mostrarDatos() {
        // Completa para mostrar nombre y edad
    }
};

int main() {
    Empleado emp;
    emp.mostrarDatos();
    return 0;
}
```