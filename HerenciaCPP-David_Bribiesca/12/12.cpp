#include<iostream>
using namespace std;

class Dispositivo { public: string marca; };
class TV : virtual public Dispositivo {};
class DVD : virtual public Dispositivo {};
class ControlRemoto : public TV, public DVD {};

int main(){
    ControlRemoto c1;
    c1.marca = "Panasonic";
    cout << c1.marca;
}