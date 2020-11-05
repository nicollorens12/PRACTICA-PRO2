#include "Cjt_Contenidors.hh"
#include <utility>

using namespace std;

Cjt_Contenidors::Cjt_Contenidors(){
    map<string,Segmento> cjt;
    map<string,Segmento>::iterator it;
    
}

Ubicacion Cjt_Contenidors::ubi(string m){
    
    it = cjt.find(m);
    Ubicacio ubi = (*it).ubic();
    return ubi;
}

void Cjt_Contenidors::inserta_contenedor_cjt(string m, Segmento s){
    pair<string,Segmento> p;
    p.first() = m;
    p.second() = s;
    cjt.insert(p);
}

void Cjt_Contenidors::retira_contenidor_cjt(string m){
    cjt.erase(m);
}
void Cjt_Contenidors::print_contenedores(){
    //Forma mes eficient de printejar un mapa
}
