#include "Huecos.hh"

#include <iostream>

using namespace std;

typedef pair<int,pair<int,int>> Clau;
// pair<long,pair<hilera,plasa>> Value: k
Huecos::Huecos(int n, int m){
    
    for (int i = 0; i < n; ++i){
        
        Clau p;
        p.first = m;
        p.second.first = i;
        p.second.second = 0;
        pair <Clau,int> hco;
        hco.first = p;
        hco.second = 0;
        huec.insert(hco);
    }
    
}

Huecos::~Huecos(){}

Ubicacion Huecos::extrae_ubi(map<Clau,int>::const_iterator it){
    return Ubicacion (it->first.second.first,it->first.second.second, it->second);
}

Ubicacion Huecos::best_fit(int l){
    map<Clau,int>::const_iterator it;

    while(it != huec.end()){
        if(it->first.first > l) return extrae_ubi(it);

        else if(it->first.first == l) return extrae_ubi(it);

        else ++it;
    }

    return Ubicacion();
}
// pair<long,pair<hilera,plasa>> Value: k
void Huecos::actualiza_huecos_insertar(Segmento s, int h){

    map<Clau,int>::const_iterator it = huec.begin();
    bool found = false;

    while(not found and it != huec.end()){
        if(it->first.second.first == s.ubic().hilera() and it->first.second.second == s.ubic().plaza()) found = true;
    }

    if(found){
        Clau p = it->first;
        p.first -= s.longitud();

        if(p.first -= s.longitud() != 0){
            p.second.second += s.longitud();

            pair<Clau,int> aux;
            aux.first = p;
            aux.second = it->second;

            huec.erase(it);
            huec.insert(aux);
        }
    }

    if(s.ubic().piso()+1 < h){
        // pair<long,pair<hilera,plasa>> Value: k
        
        it = huec.begin();
        while(it->first.second.first != s.ubic().hilera() and it->first.second.second != (s.ubic().plaza() + s.longitud()) ) ++it;

        map<Clau,int>::const_iterator it_esq = huec.begin();

        if(s.ubic().plaza() != 0){
            
            bool existe = false;
            while (it_esq != huec.end() and not existe) {
                if (it->first.second.first == s.ubic().hilera() and it->second == s.ubic().piso() and (it->first.second.second + it->first.first) == s.ubic().plaza()){
                    existe =  true;
                }
                else ++it_esq;
            }
            
        }

        if(it != huec.end()){
            if(it_esq != huec.end()){ //SUMAR IZQ Y DER
                Clau c;
                c.first = it->first.first + it_esq->first.first + s.longitud();
                c.second.first = it_esq->first.second.first;
                c.second.second = it_esq->first.second.second;
                int k = it_esq->second;
                pair<Clau,int> aux;
                aux.first = c;
                aux.second = k;
                huec.erase(it);
                huec.erase(it_esq);
                huec.insert(aux);
            }
            else{ // SOLO SUMAR DERECHA
                Clau c;
                c.first = it->first.first  + s.longitud();
                c.second.first = s.ubic().hilera();
                c.second.second = s.ubic().plaza();
                int k = s.ubic().piso();
                pair<Clau,int> aux;
                aux.first = c;
                aux.second = k;
                huec.erase(it);
                huec.insert(aux);
            }
        }
        else if(it_esq != huec.end()){ //SOLO SUMAR IZQ
            Clau c;
            c.first = it_esq->first.first  + s.longitud();
            c.second.first = it_esq->first.second.first;
            c.second.second = it_esq->first.second.second;
            int k = it_esq->second;
            pair<Clau,int> aux;
            aux.first = c;
            aux.second = k;
            huec.erase(it_esq);
            huec.insert(aux);
        }
            
    }

}


void Huecos::actualiza_huecos_borrar(Segmento s,int h){
    

    map<Clau,int>::const_iterator it = huec.begin();
    while(it->first.second.first != s.ubic().hilera() and (it->first.second.second != s.ubic().plaza() + s.longitud()) ) ++it;

    map<Clau,int>::const_iterator it_esq = huec.begin();
    while(it->first.second.first != s.ubic().hilera() and it->second != s.ubic().piso() and (it->first.first + it->first.second.second == s.ubic().plaza())) ++it_esq;

    
    bool derecha_v = true;
    bool izq_v = true;
    if(it == huec.end()) derecha_v = false;
    if(it_esq == huec.end()) izq_v = false;

    if(derecha_v and izq_v){ //SUMAMOS TODOS LOS FUCKING HUECOS
        // pair<long,pair<hilera,plasa>> Value: k
        Clau c;
        c.first = it_esq->first.first + s.longitud() + it->first.first;
        c.second.first = it->first.second.first;
        c.second.second = it_esq->first.second.second;
        int k = it_esq->second;
        pair<Clau,int> aux;
        aux.first = c;
        aux.second = k;
        huec.erase(it);
        huec.erase(it_esq);
        huec.insert(aux);

    }
    else if(derecha_v){ //SUMAMOS EL HUECO DE LA DERECHA
        Clau c;
        c.first = s.longitud() + it->first.first;
        c.second.first = it->first.second.first;
        c.second.second = s.ubic().plaza();
        int k = it->second;
        pair<Clau,int> aux;
        aux.first = c;
        aux.second = k;
        huec.erase(it);
        huec.insert(aux);
    }
    else if(izq_v){//SUMAMOS EL HUECO DE IZQUIERDA
        // pair<long,pair<hilera,plasa>> Value: k
        Clau c;
        c.first = it_esq->first.first + s.longitud();
        c.second.first = it_esq->first.second.first;
        c.second.second = it_esq->first.second.second;
        int k = it_esq->second;
        pair<Clau,int> aux;
        aux.first = c;
        aux.second = k;
        huec.erase(it_esq);
        huec.insert(aux);
    }


    if(s.ubic().piso()+1 < h){

        if(not derecha_v and not izq_v){ // MIRAMOS HUECOS DE ARRIBA ENTEROS
            
        }
        else if(not derecha_v){ //MIRAMOS HUECOS ARRIBA DERECHA
            it = huec.begin();
            while(it->first.second.first != s.ubic().hilera() and it->first.second.second != s.ubic().plaza() and it->second != s.ubic().piso()) ++it;
        }
        else if(not izq_v){ // MIRAMOS HUECOS ARRIBA IZQ

        }
    }

}

void Huecos::print_huecos(){
    
    for(map<Clau,int>::const_iterator it = huec.begin(); it != huec.end(); ++it){
        Ubicacion u = extrae_ubi(it);
        Segmento s(u,it->first.first);
        s.print(); 
        cout << endl; 
    }
    cout << endl;
}