# Herencia Privada en C++

## 1. Presentación y explicación profunda

La **herencia privada** en C++ es un mecanismo de encapsulamiento que modifica el acceso de los miembros de la clase base al derivar una subclase. En este modelo:

- Los **miembros públicos** de la clase base se convierten en **privados** en la subclase.
- Los **miembros protegidos** de la clase base también pasan a ser **privados** en la subclase.
- Los **miembros privados** de la clase base permanecen inaccesibles.

La herencia privada se emplea cuando se desea **reutilizar código de una clase base** como **implementación interna** de otra clase, sin exponer la interfaz de la base a los usuarios de la derivada. De este modo, la relación se percibe como una **dependencia de implementación**, no como una relación **is-a** (es-un).

---

## 2. Caso hipotético: Problema sin uso de herencia privada

Imagine un sistema de generación de reportes donde existe una clase `GeneradorJSON` que provee métodos para construir y formatear estructuras JSON internas. Se requiere crear una clase `Reporte` que use estas funciones para generar su salida, pero **sin exponer** directamente la API de `GeneradorJSON` a quien use `Reporte`.

---

## 3. Solución sin aplicar herencia privada

```cpp
#include <iostream>
#include <map>
using namespace std;

// Clases independientes
class GeneradorJSON {
public:
    void abrirObjeto() { cout << "{"; }
    void cerrarObjeto() { cout << "}"; }
    void escribirCampo(const string& clave, const string& valor) {
        cout << """ << clave << "": "" << valor << """;
    }
};

class Reporte {
public:
    void generar() {
        GeneradorJSON gen;
        gen.abrirObjeto();
        gen.escribirCampo("estado", "OK");
        gen.cerrarObjeto();
    }
};

int main() {
    Reporte r;
    r.generar();  // Salida: {"estado": "OK"}
    return 0;
}
```

---

## 4. Desventajas de la solución sin herencia privada

1. **Acoplamiento explícito**: `Reporte` crea y maneja internamente `GeneradorJSON`, duplicando llamadas.
2. **No reutilización de instancias**: cada llamada a `generar()` crea un nuevo objeto.
3. **Dificultad de extensión**: no hay posibilidad de modificar comportamiento de JSON sin cambiar `Reporte`.
4. **Interfaces expuestas**: el usuario de `Reporte` no puede personalizar la generación de JSON.

---

## 5. Solución aplicando herencia privada

```cpp
#include <iostream>
#include <map>
using namespace std;

// Clase base: GeneradorJSON
class GeneradorJSON {
protected:
    void abrirObjeto() { cout << '{'; }
    void cerrarObjeto() { cout << '}'; }
    void escribirCampo(const string& clave, const string& valor) {
        cout << '"' << clave << "": "" << valor << '"';
    }
};

// Clase derivada: Reporte hereda privatamente GeneradorJSON
class Reporte : private GeneradorJSON {
public:
    void generar(const map<string,string>& datos) {
        abrirObjeto();
        bool primera = true;
        for (const auto& par : datos) {
            if (!primera) cout << ',';
            escribirCampo(par.first, par.second);
            primera = false;
        }
        cerrarObjeto();
        cout << endl;
    }
};

int main() {
    Reporte rep;
    cout << "Salida con herencia privada:" << endl;
    rep.generar({{"estado","OK"},{"codigo","200"}});

    // Contraejemplo: acceso prohibido
    // rep.abrirObjeto();      // Error: miembro privado
    // rep.escribirCampo(...);  // Error: miembro privado
    return 0;
}
```

---

## 6. Ventajas de la solución con herencia privada

1. **Reutilización de código**: `Reporte` aprovecha métodos de `GeneradorJSON`.
2. **Encapsulamiento fuerte**: la API de JSON no se expone fuera de `Reporte`.
3. **Bajo acoplamiento**: clientes de `Reporte` interactúan con una interfaz limpia.
4. **Flexibilidad interna**: se puede modificar la implementación JSON sin afectar usuarios.
5. **Mantenimiento**: cambios en `GeneradorJSON` se reflejan internamente en `Reporte`.

---

*Este instructivo está diseñado para ofrecer una exposición detallada de la herencia privada, mostrando cómo encapsular implementaciones sin exponer la interfaz de la clase base.*
