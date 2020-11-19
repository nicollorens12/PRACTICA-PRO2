#include "Hilera.hh"
#include <iostream>

using namespace std;


//Creadora

/** @brief Creadora
      \pre <em>Cert</em>
      \post S'ha creat una filera m x h
*/
Hilera::Hilera(int m_i,int h_i){
    Matrix m(m_i,Row(h_i,""));
    mat = m;
}

//Destructora?
Hilera::~Hilera(){}
// Consultores

/** @brief Busca el millor lloc per afegir un contenidor en un fila determinada. Auxiliar de la funcio best_fit()
      \pre <em>Cert</em>
      \post S'ha retornat la posicio i la longitud del lloc que s'ha trobat, si no s'ha trobat cap retorna un segment amb l = 0
*/ 
//Segmento con longitud 0 = no se puede colocar el contenedor en esta hilera

Ubicacion Hilera::best_fit_aux(Contenedor c, int hilera){
      int h = mat.size();
      int m = mat[0].size();

      Ubicacion u; 
      bool found = false;

      int i = 0;
      
      while(i < h and not found){
            int j = 0;
            while(j < m and not found){
                  bool stop = false;
                  int hueco_size = 0;
                  int l = c.longitud();
                  while (j < m and mat[i][j].empty() and not stop) {

                        if (i == 0) ++hueco_size;
                        else if(not mat[i-1][j].empty())++hueco_size;
                        else stop = true;
                        
                        if(hueco_size == l and not stop){
                              found = true;
                              stop = true;
                              cout << j << endl;
                              Ubicacion aux(hilera,((j-l) + 1),i);
                              u = aux;
                        }
                        else if (not stop) ++j;
                        
                  }
                  ++j;
            }
          ++i;
      }
      return u;
}

void Hilera::modifica_hilera(int m, int h,Contenedor c){
      int l = c.longitud();
      string matricula = c.matricula();
      for (int i = m; i < m+l; ++i){
            
            mat[i][h] = matricula;
      }
}

//Entrada/Salida

/** @brief Imprimeix la posicio i la matricula dels contenidors de la filera. Auxiliar de la funcio print_area_almacenaje()
      \pre <em>Cert</em>
      \post S'ha impres la filera
*/
void Hilera::print_hilera() const {
      
     for(int i = mat[0].size() - 1; i >= 0; --i){
           cout << i << " ";
            for (int j = 0; j < mat.size(); ++j){
                  if (mat[j][i] != "") cout << mat[j][i] << " ";
                  else cout << "e" << " ";
            }
            cout << endl;
      }
      
      cout << "  ";
      int aux_counter = 0;
      int n = mat.size();
      for (int k = 0; k < n; ++k){
            if (k < 10){
                  cout << aux_counter << " ";
                  ++aux_counter;
            }
            else{
                  aux_counter = 0;
                  cout << aux_counter << " ";
            }
      }
}


void Hilera::print_aux() const{
      for(int i = mat[0].size() - 1; i >= 0; --i){
            for (int j = 0; j < mat.size(); ++j){
                  if (mat[j][i] != "") cout << mat[j][i] << " ";
                  else cout << "e" << " ";
            }
            cout << endl;
      }
}
/** @brief Imprimeix els forats disponibles (posicio i longitud) a la filera. Auxiliar de la funcio print_huecos()
      \pre <em>Cert</em>
      \post S'ha impres els forats disponibles a la filera
*/
void Hilera::print_huecos_hilera(int n,vector<Segmento>& v){
      int m = mat.size();
      int h = mat[0].size();
      Ubicacion u;
      for(int i = 0; i < h; ++i){
            for (int j = 0; j < m; ++j){
                  if(mat[i][j].empty() and u.hilera() != -1){
                        Ubicacion aux1(n,i,j);
                        u = aux1;
                  }
                  else if(not mat[i][j].empty() and u.hilera() != -1){ 
                        Ubicacion aux2(n,i,j);
                        int l = aux2.plaza() - u.plaza();
                        Ubicacion aux3;
                        u = aux3;
                        Segmento s(u,l);
                        v.push_back(s);
                  }
            }
      }

}

Row Hilera::operator[](int i) const {
      return mat[i];
}