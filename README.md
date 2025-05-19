# Herencia en Programación Orientada a Objetos (POO) con C++

## Descripción

Este repositorio ofrece una introducción general al concepto de **herencia** en Programación Orientada a Objetos (POO) y presenta un resumen de los distintos tipos de herencia disponibles en C++ (y en la mayoría de lenguajes OOP). No profundiza en ejemplos específicos, sino que establece el marco conceptual y su relevancia en el diseño de software.

---

## Contenido

* **Introducción a la herencia**: definición, propósito y ventajas.
* **Tipos de herencia**: descripción de modos y estructuras comunes.
* **Importancia de la herencia**: cómo mejora la mantenibilidad, la reutilización de código y la claridad semántica.
* **Referencias**: enlaces a fuentes de consulta recomendadas.

---

## 1. Introducción

La **herencia** es un mecanismo que permite definir nuevas clases (subclases) basadas en clases existentes (superclases), heredando atributos y comportamientos. Establece relaciones **is-a**, promueve la **reutilización de código** y facilita la **extensibilidad** de sistemas complejos.

### Ventajas clave

* **Reutilización**: evita duplicar código común.
* **Jerarquías claras**: refleja relaciones del mundo real.
* **Polimorfismo**: permite tratar objetos derivados como su clase base.

---

## 2. Tipos de herencia

En C++ y muchos lenguajes OOP, existen dos categorías principales:

### 2.1 Modos de herencia (según nivel de acceso)

| Modo          | Sintaxis                        | Efecto sobre miembros heredados                |
| ------------- | ------------------------------- | ---------------------------------------------- |
| **Public**    | `class Sub : public Base {}`    | `public` → `public`, `protected` → `protected` |
| **Protected** | `class Sub : protected Base {}` | `public`/`protected` → `protected`             |
| **Private**   | `class Sub : private Base {}`   | `public`/`protected` → `private`               |

### 2.2 Estructuras de herencia

* **Simple**: una sola clase base.
* **Múltiple**: varias clases base.
* **Multinivel**: cadena de herencia en más de dos niveles.
* **Jerárquica**: varias clases derivadas de una sola base.
* **Híbrida**: combinación de estructuras anteriores.
* **Virtual**: evita duplicación en herencia múltiple (problema del diamante).

---

## 3. Importancia en el diseño de software

1. **Mantenibilidad**: centraliza cambios en la clase base.
2. **Extensibilidad**: facilita agregar nuevas funcionalidades.
3. **Claridad semántica**: expresa relaciones naturales entre entidades.
4. **Reducción de complejidad**: separa comportamientos comunes y específicos.

---

## Referencias

1. [cppreference.com - Inheritance](https://en.cppreference.com/w/cpp/language/inheritance)
2. [GeeksforGeeks - Types of Inheritance in C++](https://www.geeksforgeeks.org/types-of-inheritance-in-c-with-examples/)
3. [TutorialsPoint - C++ Inheritance](https://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm)

---

*Este README establece los fundamentos para explorar ejercicios y ejemplos prácticos sobre herencia en lenguaje C++*

