# Ejercicio 11: Herencia virtual - De código a diagrama + mejora

**Enunciado:**
A partir del siguiente código, dibuja el diagrama y reescribe usando herencia virtual para evitar duplicación de atributos.

```cpp
#include <iostream>
using namespace std;

class Dispositivo { public: string marca; };
class Tablet : public Dispositivo {};
class Telefono : public Dispositivo {};
class Smartphone : public Tablet, public Telefono {};

int main() {
    Smartphone s;
    s.marca = "MiMarca";
    cout << s.marca << endl;
    return 0;
}
```