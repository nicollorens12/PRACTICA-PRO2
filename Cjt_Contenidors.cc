#include "Cjt_Contenidors.hh"
#include <iostream>

using namespace std;

Cjt_Contenidors::Cjt_Contenidors(){}

Cjt_Contenidors::~Cjt_Contenidors(){}

Ubicacion Cjt_Contenidors::ubi(string m){
    map<string,Segmento>::const_iterator it;
    it = cjt.find(m);
    
    if (it == cjt.end()){
        Ubicacion u;
        return u;
    } 
    return it->second.ubic();
}

int Cjt_Contenidors::longitud(string m){
    map<string,Segmento>::const_iterator it;
    it = cjt.find(m);
    if (it == cjt.end()) return -1;
    return it->second.longitud();
}

Segmento Cjt_Contenidors::consulta_contenidor(string m){
    map<string,Segmento>::const_iterator it = cjt.find(m);
    if(it == cjt.end()) return Segmento();
    return it->second;
}

bool Cjt_Contenidors::exists(string m){
    map<string,Segmento>::const_iterator it = cjt.find(m);
    if(it == cjt.end()) return false;
    return true;
}

void Cjt_Contenidors::inserta_contenedor(string m, Segmento s){

    pair<string,Segmento> p;
    p.first = m;
    p.second = s;
    cjt.insert(p);
}

void Cjt_Contenidors::retira_contenidor_cjt(string m){
    cjt.erase(m);
}

void Cjt_Contenidors::print_contenedores() const{
    
    for (map<string,Segmento>::const_iterator it = cjt.begin(); it != cjt.end(); ++it){
        cout << it->first << "(";
        it->second.ubic().print();
        cout << "," << it->second.longitud() <<')' << endl;
    }
    cout << endl;
}
