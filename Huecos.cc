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

void Huecos::renueva_huecos(vector<Segmento> huecos){
    huec.clear();
    int size = huecos.size();
    for(int i = 0; i < size; ++i){
        huec.insert(segmento_a_clau(huecos[i]));
    }
}

void Huecos::borra_hueco(Clau c){
    map<Clau,int>::iterator it = huec.find(c);
    if(it != huec.end()) huec.erase(it);
    
}

void Huecos::inserta_hueco(pair<Clau,int> p){
    huec.insert(p);
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