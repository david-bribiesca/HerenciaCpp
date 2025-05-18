# Ejercicio 10: Herencia múltiple - Análisis de ambigüedad

**Enunciado:**
Corrige este código que presenta ambigüedad por herencia múltiple:

```cpp
#include <iostream>
using namespace std;

class A { public: void imprimir() { cout << "A
"; } };
class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
    D obj;
    obj.imprimir(); // Error
    return 0;
}
```