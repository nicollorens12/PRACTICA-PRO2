#include "Hilera.hh"
#include <iostream>

using namespace std;


//Creadora

/** @brief Creadora
      \pre <em>Cert</em>
      \post S'ha creat una filera m x h
*/
Hilera::Hilera(int m,int h){
    Matrix mat(m,Row(h,""));
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
      int n = mat.size();
      int m = mat[0].size();
      Ubicacion u; 
      bool found = false;
      int i,j;
      i = 0;

      while(i < n and not found){
            int j = 0;
            while(j < m and not found){
                  if (mat[i][j].empty()){

                        int hueco_size = 1;
                        int l = c.longitud();
                        while (not found and j < n ){
                        j++;
                        if (mat[i][j].empty()){
                              if (i == 0) ++hueco_size;
                              else if (not mat[i-1][j].empty()) ++hueco_size;
                        }
                        else if (not mat[i][j].empty()) found = false;
                        if(hueco_size == l){
                              found = true;
                              Ubicacion aux(i,hilera,j); // coordenada i se 
                              u = aux;
                        }
                        ++j;
                        }

                  }
                  ++j;
            }
          ++i;
      }
      return u;
}

//Entrada/Salida

/** @brief Imprimeix la posicio i la matricula dels contenidors de la filera. Auxiliar de la funcio print_area_almacenaje()
      \pre <em>Cert</em>
      \post S'ha impres la filera
*/
void Hilera::print_hilera() const {
      
      int h = mat[0].size() - 1;
      
      while (h >= 0){
            cout << h << " ";
            int n = mat.size() - 1;
            while (n >= 0){
                  if (mat[h][n].empty()) cout << " ";
                  else cout << mat[h][n];
            }

      }
      cout << "  ";
      int aux_counter = 0;
      int n = mat.size();
      for (int i = 0; i < n; ++i){
            if (i < 10){
                  cout << aux_counter;
                  ++aux_counter;
            }
            else{
                  aux_counter = 0;
                  cout << aux_counter;
            }
      }
}

/** @brief Imprimeix els forats disponibles (posicio i longitud) a la filera. Auxiliar de la funcio print_huecos()
      \pre <em>Cert</em>
      \post S'ha impres els forats disponibles a la filera
*/
void Hilera::print_huecos_hilera(int n,vector<Segmento> v){
      int m = mat.size();
      int h = mat[0].size();
      vector<Segmento> v;
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