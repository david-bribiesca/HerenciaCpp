#include <iostream>
using namespace std;

class ReproductorMultimedia {
    public:
    string name;
    ReproductorMultimedia(string n):name(n){}
    
};

class ReproductorAudio: public ReproductorMultimedia{
    public:
    ReproductorAudio(string n):ReproductorMultimedia(n){}
    void reproducir(string mp3){
        cout << "Esta sonando " + mp3 + " en el reproductor " + name << endl;

    }
};

class ReproductorVideo: public ReproductorMultimedia{
    public:
    ReproductorVideo(string n):ReproductorMultimedia(n){}
    void reproducir(string mp4){
        cout << "Estas viendo " + mp4 + " en el reproductor " +  name << endl;

    }
};


int main(){
    ReproductorVideo Youtube("Youtube");
    Youtube.reproducir("Tutorial de cocina");
    ReproductorAudio Spotify("Spotify");
    Spotify.reproducir("Sapito");
}
