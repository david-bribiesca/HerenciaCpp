#include <iostream>
using namespace std;

class Usuario{
    public:
    Usuario(string n):name(n){}
    string name;
    void login(){
        cout << name << " ha iniciado sesión" << endl; 
    }
};

class Moderador: public Usuario{
    public:
    Moderador(string n):Usuario(n){}
    void moderar(){
        cout << name << " ha moderado" << endl;
    }

};

class Admin: public Moderador{
    public:
    Admin(string n):Moderador(n){}
    void banear(string user){
        cout << name << " ha baneado a " << user << endl;
    }
};

int main(){
    Admin A1("David");
    A1.login();
    A1.moderar();
    A1.banear("Santiago");
    return 0;
}