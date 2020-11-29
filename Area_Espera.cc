#include "Area_Espera.hh"
#include <list>
#include <iostream>


using namespace std;

Area_Espera::Area_Espera(){
    l_espera = list<Contenedor> l;
}

Area_Espera::~Area_Espera(){}

void Area_Espera::inserta_a_espera(Contenedor c){
    l_espera.push_back(c);
}

Contenedor Area_Espera::consulta_siguiente(){

    if(l_espera.size() >= 1){
        return l_espera.back();
    }
    return Contenedor();
}

void Area_Espera::print_a_espera(){
    for(list<Contenedor>::const_iterator it = l_espera.begin(); it != l_espera.end(); ++it){
        cout << it->matricula() << " (" << it->longitud() << ")" << endl;
    }
}

