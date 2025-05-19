# Instructivo: Herencia Protegida en C++

## 1. Presentación y explicación profunda

En C++, la **herencia protegida** (`protected`) es un mecanismo que modifica los niveles de acceso de los miembros de la clase base al derivar una subclase. A diferencia de la herencia pública, donde los miembros públicos y protegidos de la clase base conservan sus niveles de acceso, en la herencia protegida:

- Los **miembros públicos** de la clase base pasan a ser **protegidos** en la subclase.
- Los **miembros protegidos** de la clase base se mantienen **protegidos** en la subclase.
- Los **miembros privados** de la clase base **no** se heredan y, por tanto, no están disponibles en la subclase.

Este esquema de acceso busca **garantizar encapsulamiento**, de modo que la interfaz de la clase base no quede expuesta públicamente a los usuarios de la subclase, pero siga siendo accesible para la propia jerarquía de herencia. La herencia protegida es útil cuando **queremos reutilizar atributos y métodos de la base internamente** pero **ocultar** esa reutilización a clientes de la subclase.

---

## 2. Caso hipotético: Problema de programación sin uso de herencia protegida

Imagínese un sistema de gestión de perfiles de usuario para una aplicación corporativa. Existen dos roles:

- `Usuario`: debe almacenar nombre de usuario, correo y contraseña.
- `Administrador`: añade funcionalidad para modificar roles y permisos internos.

Se requiere desarrollar ambas clases de forma que, internamente, `Administrador` pueda acceder a los datos de `Usuario` para validar credenciales y asignar permisos, pero sin exponer públicamente esos detalles a quien use la clase `Administrador`.

---

## 3. Solución sin aplicar herencia protegida

```cpp
#include <iostream>
using namespace std;

// Clases independientes sin herencia
class Usuario {
public:
    string nombre;
    string correo;
    string contrasena;

    void autenticar() const {
        cout << "Autenticando usuario: " << nombre << endl;
    }
};

class Administrador {
public:
    // Duplicación de atributos
    string nombre;
    string correo;
    string contrasena;

    void autenticarAdmin() const {
        cout << "Autenticando administrador: " << nombre << endl;
    }

    void asignarPermisos() const {
        cout << "Permisos asignados." << endl;
    }
};

int main() {
    Usuario u{"alice","alice@corp.com","pass123"};
    Administrador a{"admin","admin@corp.com","adminpass"};

    u.autenticar();           // funciona correctamente
    a.autenticarAdmin();      // método propio de Administrador
    a.asignarPermisos();      // funcionalidad adicional
    return 0;
}
```

---

## 4. Desventajas de la solución sin aplicar el tema

1. **Duplicación de código**: los atributos `nombre`, `correo` y `contrasena` están repetidos en ambas clases.
2. **Falta de relación semántica**: no se refleja que `Administrador` es un tipo de `Usuario`.
3. **Mantenimiento complicado**: cualquier cambio en la representación de `Usuario` debe replicarse en `Administrador`.
4. **Encapsulamiento deficiente**: `Administrador` expone públicamente los datos de `Usuario` en su interfaz.

---

## 5. Solución aplicando herencia protegida

```cpp
#include <iostream>
using namespace std;

// Clase base: Usuario
class Usuario {
protected:
    string nombre;
    string correo;
    string contrasena;

public:
    // Constructor parametrizado
    Usuario(const string& u, const string& c, const string& p)
        : nombre(u), correo(c), contrasena(p) {}

    // Método público para autenticar
    void autenticar() const {
        cout << "[Usuario] Autenticando: " << nombre << endl;
    }
};

// Subclase: Administrador con herencia protegida
class Administrador : protected Usuario {
public:
    // Constructor que delega a la base
    Administrador(const string& u, const string& c, const string& p)
        : Usuario(u, c, p) {}

    // Método público propio de Administrador
    void autenticarAdmin() const {
        // Uso interno de autenticar() heredado (ahora protegido)
        autenticar();
        cout << "[Admin] Autenticación elevada exitosa." << endl;
    }

    void asignarPermisos() const {
        // Acceso directo a atributos protegidos
        cout << "Asignando permisos a: " << nombre << endl;
    }
};

int main() {
    // Instanciación y uso
    Administrador admin("admin","admin@corp.com","adminpass");

    cout << "-- Validación de credenciales --" << endl;
    admin.autenticarAdmin();

    cout << "-- Gestión de permisos --" << endl;
    admin.asignarPermisos();

    // Contraejemplo: las siguientes líneas FALLAN
    // admin.nombre;          // Error: 'nombre' es protected en Administrador
    // admin.autenticar();    // Error: autenticar() es protected

    return 0;
}
```

---

## 6. Ventajas de la solución con herencia protegida

1. **Reutilización interna**: `Administrador` accede a atributos y métodos de `Usuario` sin duplicarlos.
2. **Encapsulamiento reforzado**: la interfaz de `Usuario` no se expone al cliente de `Administrador`.
3. **Claridad semántica**: `Administrador` es claramente un subtipo de `Usuario`.
4. **Mantenimiento**: cambios en `Usuario` repercuten automáticamente en `Administrador`.
5. **Seguridad de acceso**: datos sensibles permanecen protegidos fuera de la jerarquía.

---

*Este instructivo ofrece una visión detallada de la herencia protegida, ilustrando cómo mejorar el diseño de clases en C++ y garantizar un encapsulamiento adecuado manteniendo la flexibilidad interna.*
