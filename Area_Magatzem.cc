#include "Area_Magatzem.hh"
#include <iostream>


using namespace std;

Area_Magatzem::Area_Magatzem(int n_i, int m_i, int h_i){
      n = n_i;
      m = m_i;
      h = h_i;
      v = vector<Hilera> (n_i, Hilera(m_i,h_i)); // m h?
}


//DESTRUCTORA

Area_Magatzem::~Area_Magatzem(){}

//Consultores

int Area_Magatzem::plazas() const{
      return n;
}

int Area_Magatzem::filas() const{
      return m;
}

int Area_Magatzem::altura() const{
      return h;
}

void Area_Magatzem::huecos(vector<Segmento>& v_huecos) const{
      for(int i = 0; i < n; ++i){
           v[i].huecos_hilera(n-1,v_huecos);
      }
}

//Operadors


void Area_Magatzem::inserta_contenedor(string m, int l, Ubicacion u){
      Contenedor c(m,l);
      if (u.hilera() != -1) v[u.hilera()].modifica_hilera(u.plaza(),u.piso(),m,l);
      
}

void Area_Magatzem::retira_contenidor(Segmento s,Cjt_Contenidors& cjt){
      int hilera = s.ubic().hilera();
      int lim = s.ubic().plaza()+ s.longitud();
      
      for(int j = h; j >= 0; --j){
            for(int i = s.ubic().plaza(); i < lim; ++i){

                  if(i == s.ubic().piso() and s.ubic().plaza() == j){
                        v[hilera].borra_contenidor_hilera(s);
                  }
                  else if(not v[hilera].elemen_pos(j,i).empty()){
                        
                        Segmento segm = cjt.consulta_contenidor(v[hilera].elemen_pos(j,i));
                        Contenedor c(v[hilera].elemen_pos(j,i),segm.longitud());
                        a_espera.inserta_a_espera(c);
                       
                        v[hilera].borra_contenidor_hilera(segm);
                       
                  }
            }
      }
      
      v[s.ubic().hilera()].modifica_hilera(s.ubic().plaza(),s.ubic().piso(),"",s.longitud());
}



// Entrada/Sortida

void Area_Magatzem::print_num_hileras(){
      cout << n << endl;
}

void Area_Magatzem::print_num_plazas(){
      cout << m << endl;
}

void Area_Magatzem::print_num_pisos(){
      cout << h << endl;
}

void Area_Magatzem::print_contenedor_ocupa(int i,int j,int k){

      if( (i >= n or j >= m or k >= h) or (i < 0 or j < 0 or k < 0)){ //sin sentido
            cout << "error: ubicacion fuera de rango" << endl;
      }
      else if (v[i].elemen_pos(j,k).empty()) cout << endl;
      
      else {
            v[i].print_pos(j,k);
      }
      
}

void Area_Magatzem::print_area_espera() const{
      a_espera.print_a_espera();
}

void Area_Magatzem::print_area_almacenaje(){
      int hileras = v.size();
      for (int i = 0; i < hileras; ++i){
            cout << "hilera " << i << endl;
            v[i].print_hilera();
            cout << endl;
      }
}

string Area_Magatzem::contenedor_ocupa(int i, int j, int k){
      return v[i].elemen_pos(j,k);
}

void Area_Magatzem::borra_contenidor(Segmento s){
      v[s.ubic().hilera()].borra_contenidor_hilera(s);
}