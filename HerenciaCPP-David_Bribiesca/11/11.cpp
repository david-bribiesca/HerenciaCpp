#include <iostream>
using namespace std;

class Dispositivo { public: string marca; };
class Tablet : virtual public Dispositivo {};
class Telefono : virtual public Dispositivo {};
class Smartphone : public Tablet, public Telefono {};

int main() {
    Smartphone s;
    s.marca = "Nike";
    cout << s.marca << endl;
    return 0;
}