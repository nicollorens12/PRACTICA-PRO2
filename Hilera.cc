#include "Hilera.hh"
#include <iostream>

using namespace std;


//Creadora

/** @brief Creadora
      \pre <em>Cert</em>
      \post S'ha creat una filera m x h
*/
Hilera::Hilera(int m_i,int h_i){
    mat = Matrix (h_i,Row(m_i,""));
}

//Destructora?
Hilera::~Hilera(){}
// Consultores


void Hilera::modifica_hilera(int m, int h,string matricula, int l){
     
      for (int i = m; i < m+l; ++i){
            
            mat[h][i] = matricula;
      }

}

void Hilera::borra_elem(int m, int h){
      mat[h][m] = "";
}

//Entrada/Salida

/** @brief Imprimeix la posicio i la matricula dels contenidors de la filera. Auxiliar de la funcio print_area_almacenaje()
      \pre <em>Cert</em>
      \post S'ha impres la filera
*/
void Hilera::print_hilera() const {
      for(int i = mat.size() - 1; i >= 0; --i){
      cout << i << " ";
            for (int j = 0; j < mat[0].size(); ++j){
                  if (not mat[i][j].empty()) cout << mat[i][j][0];
                  else cout << " ";
            }
            cout << endl;
      }
      
      cout << "  ";
      int aux_counter = 0;
      int m = mat[0].size();
      for (int k = 0; k < m; ++k){
            if (k%10 == 0) aux_counter = 0;
            cout << aux_counter;
            aux_counter++;
            
      }
      cout << endl;
}

/** @brief Imprimeix els forats disponibles (posicio i longitud) a la filera. Auxiliar de la funcio print_huecos()
      \pre <em>Cert</em>
      \post S'ha impres els forats disponibles a la filera
*/
void Hilera::huecos_hilera(int n,vector<Segmento>& v) const{
      int m = mat[0].size();
      int h = mat.size();
      Ubicacion u;
      for(int i = 0; i < h; ++i){
            for (int j = 0; j < m; ++j){

                  if(mat[i][j].empty() and u.hilera() == -1 and (i == 0 or not mat[i-1][j].empty()) ){
                        u = Ubicacion(n,j,i);
                  }
                  
                  else if(not mat[i][j].empty() and u.hilera() != -1){
                        //cout << mat[i][j] << endl;
                        Ubicacion aux2(n,j,i);
                        int l = aux2.plaza() - u.plaza();
                        Segmento s(u,l);
                        v.push_back(s);
                        u = Ubicacion();
                        

                  } 

                  else if (u.hilera() != -1 and i != 0 and mat[i-1][j].empty() ){ 
                        Ubicacion aux2(n,j,i);
                        int l = aux2.plaza() - u.plaza();
                        Segmento s(u,l);
                        v.push_back(s);
                        u = Ubicacion();
                  }
                
            }
            if(mat[i][m-1].empty() and u.hilera() != -1){
                  int l = m - u.plaza();
                  Segmento s(u,l);
                  v.push_back(s);
                  u = Ubicacion();
                  
            }
            
      }

}



void Hilera::print_pos(int x, int y){
      
      cout << mat[y][x] << endl;
}

string Hilera::elemen_pos(int y, int x){

      return mat[x][y];
}

Row Hilera::operator[](int i) const {
      return mat[i];
}

void Hilera::borra_contenidor_hilera(Segmento s){
      int plaza = s.ubic().plaza();
      int piso = s.ubic().piso();
      /*for(int k = plaza; k < plaza + s.longitud(); ++k){
            if(not elemen_pos(piso+1,k).empty()) borra_contenidor_hilera(Segmento(Ubicacion(),))
      }
      */
      for(int i = plaza; i < plaza + s.longitud(); ++i) mat[piso][i] = "";
}