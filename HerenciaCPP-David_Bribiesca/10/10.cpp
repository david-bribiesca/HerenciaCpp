#include <iostream>
using namespace std;

class A { 
    public: 
    void imprimir() { 
        cout << "A"; 
    } 
};
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D obj;
    obj.imprimir(); // Error
    return 0;
}