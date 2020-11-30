#include "Area_Espera.hh"
#include <list>
#include <iostream>


using namespace std;

Area_Espera::Area_Espera(){}

Area_Espera::~Area_Espera(){}

void Area_Espera::inserta_a_espera(Contenedor c){
    l_espera.push_front(c);
}

list<Contenedor>::iterator Area_Espera::retira_a_espera(list<Contenedor>::iterator it){
    return l_espera.erase(it);
}

void Area_Espera::retira_elem_a_espera(Contenedor c){
    list<Contenedor>::iterator it = l_espera.begin();
    bool found = false;
    while(not found and it != l_espera.end()){
        if(c.matricula() == it->matricula()){
            l_espera.erase(it);
            found = true;
        }
        else ++it;
    }
}

Contenedor Area_Espera::consulta_element(list<Contenedor>::iterator it){
    return (*it);
}

list<Contenedor>::iterator Area_Espera::inici(){
    list<Contenedor>::iterator it = l_espera.begin();
    return it;
}

list<Contenedor>::iterator Area_Espera::final(){
    list<Contenedor>::iterator it = l_espera.end();
    return it;
}

void Area_Espera::print_a_espera() const{
    if(l_espera.size() != 0){
        for(list<Contenedor>::const_iterator it = l_espera.begin(); it != l_espera.end(); ++it){
            cout << it->matricula() << "(" << it->longitud() << ")" << endl;
        }
        cout << endl;
    }
    else cout << endl;
}

