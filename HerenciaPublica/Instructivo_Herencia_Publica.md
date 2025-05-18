## Instructivo: Herencia Pública en C++

### 1. Presentación y explicación profunda

La **herencia pública** es un pilar fundamental de la Programación Orientada a Objetos (POO) en C++. Consiste en definir una nueva clase (subclase) que extiende otra clase existente (superclase o clase base), de modo que:

- Los **miembros públicos** de la clase base permanecen **públicos** en la subclase.
- Los **miembros protegidos** de la clase base permanecen **protegidos** en la subclase.
- Se establece una relación **is-a** (es-un), indicando que todo objeto de la subclase "es un" objeto de la superclase.

Este mecanismo promueve la:

1. **Reutilización de código**, evitando duplicaciones.
2. **Extensibilidad**, permitiendo añadir o modificar comportamientos.
3. **Organización jerárquica**, reflejando relaciones del mundo real.

La herencia pública habilita, además, el **polimorfismo**, cuando los métodos de la clase base se declaran como `virtual`, y pueden ser sobrescritos (`override`) en la subclase.

---

### 2. Caso hipotético: Problema de programación sin uso de herencia

Suponga que se debe desarrollar un sistema de registro de vehículos en un parqueadero. Existen **coches**, **motocicletas** y **camiones**. Cada vehículo comparte ciertos atributos (marca, modelo, placa) y métodos (registrarIngreso, registrarSalida), pero también tiene comportamientos específicos.

El reto consiste en gestionar estos distintos tipos de vehículos, implementando funcionalidades que permitan registrar su ingreso y salida, y mostrar su información completa.

---

### 3. Solución sin aplicar herencia pública

```cpp
#include <iostream>
using namespace std;

// Solución basada en clases independientes
class Coche {
public:
    string marca, modelo, placa;
    void registrarIngreso() { cout << "Ingreso de coche: " << placa << endl; }
    void registrarSalida()  { cout << "Salida de coche: "  << placa << endl; }
};

class Motocicleta {
public:
    string marca, modelo, placa;
    void registrarIngreso() { cout << "Ingreso de moto: " << placa << endl; }
    void registrarSalida()  { cout << "Salida de moto: "  << placa << endl; }
};

class Camion {
public:
    string marca, modelo, placa;
    void registrarIngreso() { cout << "Ingreso de camión: " << placa << endl; }
    void registrarSalida()  { cout << "Salida de camión: "  << placa << endl; }
};

int main() {
    Coche    c{"Toyota","Corolla","ABC123"};
    Motocicleta m{"Honda","CBR","XYZ789"};
    Camion   t{"Volvo","FH","TRK456"};

    c.registrarIngreso();
    m.registrarIngreso();
    t.registrarIngreso();

    return 0;
}
```

---

### 4. Desventajas de la solución sin herencia

1. **Duplicación de código**: cada clase repite atributos y métodos idénticos.
2. **Mantenimiento dificultoso**: cambios comunes (por ejemplo, renombrar `placa`) requieren editar múltiples clases.
3. **Extensibilidad limitada**: agregar un nuevo tipo de vehículo obliga a replicar la misma lógica.
4. **No aprovecha polimorfismo**, por lo que no es posible manejar todos los vehículos de forma uniforme.

---

### 5. Solución aplicando herencia pública

#### 5.1. Código C++ con herencia pública y documentación

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Clase base: Vehiculo
class Vehiculo {
public:
    // Atributos comunes
    string marca;
    string modelo;
    string placa;

    // Constructor parametrizado
    Vehiculo(const string& m, const string& mod, const string& p)
        : marca(m), modelo(mod), placa(p) {}

    // Método para registrar el ingreso (puede ser sobrescrito)
    virtual void registrarIngreso() const {
        cout << "Ingreso de vehículo [" << placa << "]" << endl;
    }

    // Método para registrar la salida (puede ser sobrescrito)
    virtual void registrarSalida() const {
        cout << "Salida de vehículo [" << placa << "]" << endl;
    }

    // Destructor virtual para garantizar liberación adecuada
    virtual ~Vehiculo() {}
};

// Subclase: Coche (herencia pública)
class Coche : public Vehiculo {
public:
    Coche(const string& m, const string& mod, const string& p)
        : Vehiculo(m, mod, p) {}

    // Sobrescritura de registrarIngreso
    void registrarIngreso() const override {
        cout << "Ingreso de coche [" << placa << "] - Marca: "
             << marca << ", Modelo: " << modelo << endl;
    }
};

// Subclase: Motocicleta (herencia pública)
class Motocicleta : public Vehiculo {
public:
    Motocicleta(const string& m, const string& mod, const string& p)
        : Vehiculo(m, mod, p) {}

    // Usa el comportamiento base (no override)
};

int main() {
    // Ejemplo de uso: vector de punteros a Vehiculo
    vector<Vehiculo*> parqueadero;

    parqueadero.push_back(new Coche("Toyota","Corolla","ABC123"));
    parqueadero.push_back(new Motocicleta("Honda","CBR","XYZ789"));

    cout << "-- Registro de ingreso --" << endl;
    for (const auto* v : parqueadero) {
        v->registrarIngreso();  // Polimorfismo en acción
    }

    cout << "-- Registro de salida --" << endl;
    for (const auto* v : parqueadero) {
        v->registrarSalida();
    }

    // Liberar memoria
    for (auto* v : parqueadero) delete v;
    return 0;
}
```

> **Nota**: el ejemplo incluye un **contraejemplo** implícito: `Motocicleta` no redefine `registrarIngreso()`, por lo que utiliza la implementación de la clase base.

---

### 6. Ventajas de la solución con herencia pública

1. **Reutilización de código**: atributos y métodos comunes definidos una sola vez.
2. **Mantenimiento sencillo**: cambios en la clase base afectan a todas las derivadas.
3. **Polimorfismo**: permite manejar diferentes tipos de vehículos de manera uniforme.
4. **Extensibilidad**: agregar un nuevo tipo de vehículo solo implica crear una nueva subclase.
5. **Claridad semántica**: expresa relaciones "es-un" de forma natural.

---

*Este instructivo está diseñado para proporcionar al programador junior un recorrido práctico y profundo por la herencia pública en C++, desde la identificación del problema hasta la aplicación de buenas prácticas de diseño orientado a objetos.*
