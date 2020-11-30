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
    it = huec.begin();
   
    while(it != huec.end()){
        
        if(it->first.first == l) return extrae_ubi(it);

        else if(it->first.first > l) return extrae_ubi(it);

        else ++it;
    }

    return Ubicacion();
}

pair<Clau,int> Huecos::segmento_a_clau(Segmento s){
    Clau c;
    c.first = s.longitud();
    c.second.first = s.ubic().hilera();
    c.second.second = s.ubic().plaza();
    int k = s.ubic().piso();
    pair<Clau,int> aux;
    aux.first = c;
    aux.second = k;
    return aux;
}

// pair<long,pair<hilera,plasa>> Value: k 
void Huecos::actualiza_huecos_insertar(vector<Segmento> huecos_hilera,int hilera) {

    map<Clau,int>::const_iterator it = huec.begin();
    int size = huecos_hilera.size();
    //cout << it->first.second.first << endl;
    while(it != huec.end() and it->first.second.first != hilera) ++it;
    while(it != huec.end() and it->first.second.first == hilera){
        //cout << "FLAG" << endl;
        //cout << it->first.second.first << ' ' << it->first.second.second << ' ' << it->second << endl;
        it = huec.erase(it);
    
    }
   
    
    for(int i = 0; i < size; ++i){
        pair<Clau,int> elem = segmento_a_clau(huecos_hilera[i]);
        huec.insert(elem);
    }
    
    /*
    map<Clau,int>::const_iterator it = huec.begin();
    bool found = false;

    while(not found and it != huec.end()){
        if(it->first.second.first == s.ubic().hilera() and it->first.second.second == s.ubic().plaza()) found = true;
        else ++it;
    }
    
    //TROBA BE EL IT
    bool exacte = false;
    map<Clau,int>::const_iterator it_prova;
    if(found){
        Clau p = it->first;
        p.first -= s.longitud();

        if(p.first != 0){
            
            p.second.second += s.longitud();
            pair<Clau,int> aux;
            aux.first = p;
            aux.second = it->second;

            huec.erase(it);
            huec.insert(aux);
            it_prova = huec.find(p);
            cout << "nabo " << it_prova->first.second.first << ' ' << it_prova->first.second.second << ' ' << it_prova->second << ' ' << it_prova->first.first << endl;
            //INSERTA PERF EL HUECO QUE TOCA
        }
        else{
            exacte = true;
            huec.erase(it);
            Clau c;
            c.first = s.longitud();
            c.second.first = s.ubic().hilera();
            c.second.second = s.ubic().plaza();
            pair<Clau,int> aux;
            aux.first = c;
            aux.second = s.ubic().piso()+1;
            huec.insert(aux);
        }
    }

    // cout << it_prova->first.first << ' ' << it_prova->first.second.first << ' ' << it_prova->first.second.second << endl;
    if(not exacte){
        
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
        cout << "FLAG1" << endl;
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
                cout << "FLAGFERRAN1" << endl;
                huec.erase(it_esq);
                
                huec.insert(aux);
               
            }

            else{ // SOLO SUMAR DERECHA
                cout << "FLAG3" << endl;
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
            cout << "FLAG4" << endl;
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
    */
}


void Huecos::actualiza_huecos_borrar(vector<Segmento> huecos_hilera){
    // pair<long,pair<hilera,plasa>> Value: k
    map<Clau,int>::const_iterator it = huec.begin();
    int hilera = huecos_hilera[0].ubic().hilera();

    while(it != huec.end() and it->first.second.first != hilera) ++it;
    while(it != huec.end() and it->first.second.first == hilera) it = huec.erase(it);
   
    int size = huecos_hilera.size();
    for(int i = 0; i < size; ++i){
        pair<Clau,int> elem = segmento_a_clau(huecos_hilera[i]);
        huec.insert(elem);
    }

}

int Huecos::tamany(){
    return huec.size();
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

/*map<Clau,int>::const_iterator Huecos::bin_search(int l, int hil, int pla){
    
}
*/