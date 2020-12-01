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


void Area_Magatzem::inserta_contenedor(string m, int l, Ubicacion u,Huecos& huec){
      if (u.hilera() != -1) v[u.hilera()].modifica_hilera(u.plaza(),u.piso(),m,l);
      actualiza_huecos_insertar(Segmento(u,l),huec);
      
}

void Area_Magatzem::inserta_contenedor_area_espera(string m, int l){
      Contenedor c(m,l);
      a_espera.inserta_a_espera(c);
}

void Area_Magatzem::retira_contenedor_area_espera(string m, int l){
      Contenedor c(m,l);
      a_espera.retira_elem_a_espera(c);
}

void Area_Magatzem::borra_encima_afegeix_a_espera(Segmento s,Cjt_Contenidors& cjt,Huecos& huec){
      int plaza = s.ubic().plaza();
      int piso = s.ubic().piso();
      int hilera = s.ubic().hilera();

      for(int i = plaza; i < plaza + s.longitud(); ++i){
            if(piso+1 < h and not v[hilera].elemen_pos(i,piso+1).empty()){ //MIRA SI EL CONTENEDOR QUE ESTOY MIRANDO DE ARRIBA ENCIMA TIENE OTRO MAS
                  if(piso + 2 < h){ 
                        Segmento aux = cjt.consulta_contenidor(v[hilera].elemen_pos(i,piso+1));
                        borra_encima_afegeix_a_espera(aux,cjt,huec);
                  }
                  else{
                        Segmento aux = cjt.consulta_contenidor(v[hilera].elemen_pos(i,piso+1));
                        a_espera.inserta_a_espera(Contenedor(v[hilera].elemen_pos(i,piso+1),aux.longitud()));
                        Segmento aux_espera(Ubicacion(-1,0,0),aux.longitud());
                        cjt.modifica_contenidor_cjt(v[hilera].elemen_pos(i,piso+1),aux_espera);
                        borra_contenidor(aux);
                        actualiza_huecos_borrar(aux,huec);
                        
                  }
            }
      }

      Contenedor c(v[s.ubic().hilera()].elemen_pos(plaza,piso),s.longitud());
      a_espera.inserta_a_espera(c);
      Segmento aux_espera(Ubicacion(-1,0,0),s.longitud());
      cjt.modifica_contenidor_cjt(v[hilera].elemen_pos(plaza,piso),aux_espera);
      borra_contenidor(s);
      actualiza_huecos_borrar(s,huec);
}

void Area_Magatzem::retira_contenidor(Segmento s,Cjt_Contenidors& cjt,Huecos& huec){
      int hilera = s.ubic().hilera();
      int lim = s.ubic().plaza()+ s.longitud();
      int piso = s.ubic().piso();
      
      if(piso + 1 < h){
            for(int i = s.ubic().plaza(); i < lim; ++i){
                  if(not v[hilera].elemen_pos(i,piso+1).empty()){
                        Segmento s = cjt.consulta_contenidor(v[hilera].elemen_pos(i,piso+1));
                        borra_encima_afegeix_a_espera(s,cjt,huec);
                  }
            }
      }

      borra_contenidor(s);
      actualiza_huecos_borrar(s,huec);
  
}

void Area_Magatzem::inserta_contenidors_en_espera(Huecos& huec, Cjt_Contenidors& cjt){
      list<Contenedor>::iterator it = a_espera.inici();
 
      while(it != a_espera.final() and huec.tamany() != 0){

            Contenedor c = a_espera.consulta_element(it);
            string matricula = c.matricula();
            int l = c.longitud();
            Ubicacion u = huec.best_fit(l);
            
            if(u.hilera() != -1){
                  inserta_contenedor(matricula,l,u,huec);
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

void Area_Magatzem::actualiza_huecos_borrar(Segmento s,Huecos& huec){
      bool derecha_v = false;
      bool izq_v = false;
      Ubicacion u = s.ubic();
      int aux_dist = s.longitud();
      if(distancia_prox_c_izq(s).longitud() != 0){
            izq_v = true;
            Segmento izq = distancia_prox_c_izq(s);
            huec.borra_hueco(huec.segmento_a_clau(izq).first);
            u = izq.ubic();
            aux_dist += izq.longitud();
      }
      if(distancia_prox_c_derecha(s).longitud() != 0){
            derecha_v = true;
            Segmento der = distancia_prox_c_derecha(s);
            aux_dist += der.longitud();
            huec.borra_hueco(huec.segmento_a_clau(der).first);
      }
      Segmento huec_abajo(u,aux_dist); //HUECO DE ABAJO
      
      //BORRAR LOS HUECOS DE ARRIBA

      Segmento huec_arriba1;
      Segmento huec_arriba2;
      Ubicacion aux(s.ubic().hilera(),s.ubic().plaza(),s.ubic().piso()+1);
      if(s.ubic().piso() + 1 < h and (not izq_v or not derecha_v)){
            
            Segmento izq_arriba = distancia_prox_c_izq(Segmento(aux,s.longitud()));
            Segmento der_arriba = distancia_prox_c_derecha(Segmento(aux,s.longitud()));

            if((not izq_v and izq_arriba.longitud() == 0) or izq_v){ // HUECO ENCIMA A LA DERECHA (UNICO HUECO QUE SE PUEDE CONSEGUIR)
                  if(der_arriba.longitud() > 0){
                        Ubicacion aux_derecha(aux.hilera(),aux.plaza()+s.longitud(),aux.piso());
                        huec_arriba1 = der_arriba;
                        huec.borra_hueco(huec.segmento_a_clau(Segmento(aux,s.longitud()+der_arriba.longitud())).first);
                  }
            }
            else if((not derecha_v and der_arriba.longitud() == 0) or derecha_v){ // HUECO ENCIMA A LA IZQUIERDA (UNICO HUECO QUE SE PUEDE CONSEGUIR)
                  if(izq_arriba.longitud() > 0){
                        huec_arriba1 = izq_arriba;
                        huec.borra_hueco(huec.segmento_a_clau(Segmento(izq_arriba.ubic(),izq_arriba.longitud()+s.longitud())).first);
                  }
            }
            else if(not derecha_v and not izq_v and izq_arriba.longitud() > 0 and der_arriba.longitud() >0){
                  huec_arriba1 = izq_arriba;
                  huec_arriba2 = der_arriba;
                  int longitud = izq_arriba.longitud() + s.longitud() + der_arriba.longitud();
                  huec.borra_hueco(huec.segmento_a_clau(Segmento(izq_arriba.ubic(),longitud)).first);
            }
            
      }
      huec.borra_hueco(huec.segmento_a_clau(Segmento(aux,s.longitud())).first);
      huec.inserta_hueco(huec.segmento_a_clau(huec_abajo));
      if(huec_arriba1.longitud() > 0) huec.inserta_hueco(huec.segmento_a_clau(huec_arriba1));
      else if(huec_arriba2.longitud() > 0) huec.inserta_hueco(huec.segmento_a_clau(huec_arriba2));

}

Segmento Area_Magatzem::distancia_prox_c_izq(Segmento s){
      int aux_counter = 0;
      int j = s.ubic().plaza() - 1;
      int hilera = s.ubic().hilera();
      int piso = s.ubic().piso();
      while(j >= 0 and v[hilera].elemen_pos(j,piso).empty() and (piso == 0 or not v[hilera].elemen_pos(j,piso-1).empty())){
            --j;
            ++aux_counter;
      }
      if(aux_counter != 0){
            return Segmento(Ubicacion(hilera,j+1,piso),aux_counter);
      }
      return Segmento();
}

Segmento Area_Magatzem::distancia_prox_c_derecha(Segmento s){
      int aux_counter = 0;
      int j = s.ubic().plaza() + s.longitud();
      int hilera = s.ubic().hilera();
      int piso = s.ubic().piso();
      Ubicacion u(s.ubic().hilera(),s.ubic().plaza()+s.longitud(),s.ubic().piso());
      while(j < m and v[hilera].elemen_pos(j,piso).empty() and (piso == 0 or not v[hilera].elemen_pos(j,piso-1).empty())){
            ++j;
            ++aux_counter;
      }
      if(aux_counter != 0){
            return Segmento(u,aux_counter); //DEVULVE BIEN LA UBI
      }
      return Segmento();
}

void Area_Magatzem::actualiza_huecos_insertar(Segmento s,Huecos& huec){
      Segmento der_abajo = distancia_prox_c_derecha(s);
      bool derecha_v = false;
      if(der_abajo.longitud() > 0) derecha_v = true;
      huec.borra_hueco(huec.segmento_a_clau(Segmento(s.ubic(),der_abajo.longitud()+s.longitud())).first);
      if(derecha_v) huec.inserta_hueco(huec.segmento_a_clau(der_abajo));

      //MIRAR HUECOS ARRIBA
      

      Ubicacion aux(s.ubic().hilera(),s.ubic().plaza(),s.ubic().piso()+1);
      Segmento arriba;
      if(s.ubic().piso()+1 < h){
            //Hay que borrar los huecos de arriba
            Segmento izq_arriba = distancia_prox_c_izq(Segmento(aux,s.longitud()));
            Segmento der_arriba = distancia_prox_c_derecha(Segmento(aux,s.longitud()));
            if(izq_arriba.longitud() > 0 and der_arriba.longitud() > 0){ //inserto entre dos contenedores sale solo un hueco grande
                  huec.borra_hueco(huec.segmento_a_clau(izq_arriba).first);
                  huec.borra_hueco(huec.segmento_a_clau(der_arriba).first);
                  arriba = Segmento(izq_arriba.ubic(),izq_arriba.longitud()+s.longitud()+der_arriba.longitud());
            }
            else if(izq_arriba.longitud() > 0){ // der_arriba.longitud() > 0 = falso ya que no se ha cumplido la anterior
                  huec.borra_hueco(huec.segmento_a_clau(izq_arriba).first);
                  arriba = Segmento(izq_arriba.ubic(),izq_arriba.longitud()+s.longitud());
            }
            else if(der_arriba.longitud() > 0){
                  huec.borra_hueco(huec.segmento_a_clau(der_arriba).first);
                  arriba = Segmento(aux,s.longitud()+der_arriba.longitud());
            }
            else{
                  huec.borra_hueco(huec.segmento_a_clau(Segmento(aux,s.longitud())).first);
                  arriba = Segmento(aux,s.longitud());
            }

      }
      if(arriba.longitud() != 0) huec.inserta_hueco(huec.segmento_a_clau(arriba));
      
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