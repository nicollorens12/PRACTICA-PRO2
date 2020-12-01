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
           v[i].huecos_hilera(i,v_huecos);
      }
}

void Area_Magatzem::huecos_hilera(vector<Segmento>& v_huecos,int hilera) const{
      v[hilera].huecos_hilera(hilera,v_huecos);
}

//Operadors


void Area_Magatzem::inserta_contenedor(string m, int l, Ubicacion u){
      Contenedor c(m,l);
      if (u.hilera() != -1) v[u.hilera()].modifica_hilera(u.plaza(),u.piso(),m,l);
      
}

void Area_Magatzem::inserta_contenedor_area_espera(string m, int l){
      Contenedor c(m,l);
      a_espera.inserta_a_espera(c);
}

void Area_Magatzem::retira_contenedor_area_espera(string m, int l){
      Contenedor c(m,l);
      a_espera.retira_elem_a_espera(c);
}

void Area_Magatzem::borra_encima_afegeix_a_espera(Segmento s,Cjt_Contenidors& cjt){
      int plaza = s.ubic().plaza();
      int piso = s.ubic().piso();
      int hilera = s.ubic().hilera();

      for(int i = plaza; i < plaza + s.longitud(); ++i){
            if(piso+1 < h and not v[hilera].elemen_pos(i,piso+1).empty()){ //MIRA SI EL CONTENEDOR QUE ESTOY MIRANDO DE ARRIBA ENCIMA TIENE OTRO MAS
                  if(piso + 2 < h){ 
                        Segmento aux = cjt.consulta_contenidor(v[hilera].elemen_pos(i,piso+1));
                        borra_encima_afegeix_a_espera(aux,cjt);
                  }
                  else{
                        Segmento aux = cjt.consulta_contenidor(v[hilera].elemen_pos(i,piso+1));
                        a_espera.inserta_a_espera(Contenedor(v[hilera].elemen_pos(i,piso+1),aux.longitud()));
                        Segmento aux_espera(Ubicacion(-1,0,0),aux.longitud());
                        cjt.modifica_contenidor_cjt(v[hilera].elemen_pos(i,piso+1),aux_espera);
                        borra_contenidor(aux);
                        
                  }
            }
      }

      Contenedor c(v[s.ubic().hilera()].elemen_pos(plaza,piso),s.longitud());
      a_espera.inserta_a_espera(c);
      Segmento aux_espera(Ubicacion(-1,0,0),s.longitud());
      cjt.modifica_contenidor_cjt(v[hilera].elemen_pos(plaza,piso),aux_espera);
      borra_contenidor(s);
}

void Area_Magatzem::retira_contenidor(Segmento s,Cjt_Contenidors& cjt){
      int hilera = s.ubic().hilera();
      int lim = s.ubic().plaza()+ s.longitud();
      int piso = s.ubic().piso();
      
      if(piso + 1 < h){
            for(int i = s.ubic().plaza(); i < lim; ++i){
                  if(not v[hilera].elemen_pos(i,piso+1).empty()){
                        Segmento s = cjt.consulta_contenidor(v[hilera].elemen_pos(i,piso+1));
                        borra_encima_afegeix_a_espera(s,cjt);
                  }
            }
      }

      borra_contenidor(s);
  
}

void Area_Magatzem::inserta_contenidors_en_espera(Huecos& huec, Cjt_Contenidors& cjt){
      list<Contenedor>::iterator it = a_espera.inici();
 
      while(it != a_espera.final() and huec.tamany() != 0){

            Contenedor c = a_espera.consulta_element(it);
            string matricula = c.matricula();
            int l = c.longitud();
            Ubicacion u = huec.best_fit(l);
            
            if(u.hilera() != -1){
                  inserta_contenedor(matricula,l,u);
                  a_espera.retira_a_espera(it); //Inutil apuntar al siguiente elemento si vuelvo al principio
                  Segmento s(u,l);
                  cjt.modifica_contenidor_cjt(matricula,s);
                  vector<Segmento> v_huecos;
                  huecos(v_huecos);
                  //huec.actualiza_huecos_borrar(v_huecos,u.hilera());
                  huec.renueva_huecos(v_huecos);
                  it = a_espera.inici();
            }
            else ++it;        
      }
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
      //cout << endl;
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