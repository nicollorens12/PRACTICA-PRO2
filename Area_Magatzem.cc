#include "Area_Magatzem.hh"
#include <iostream>

using namespace std;

Area_Magatzem::Area_Magatzem(int n_i, int m_i, int h_i){
      n = n_i;
      m = m_i;
      h = h_i;
      v = vector<Hilera> (n_i, Hilera(m_i,h_i)); // m h?
}


//DESTRUCTORA?
Area_Magatzem::~Area_Magatzem(){}
//Consultores

/** @brief Consultora del tamany total (N,M,H) del area magatzem
      \pre <em>Cert</em>
      \post El resultat és la terna <N,M,H>
*/
Ubicacion Area_Magatzem::t_size(){
      Ubicacion u(n,m,h);
      return u;
}

/** @brief Consultora del tamany N (N = cantidad de plazas)
      \pre <em>Cert</em>
      \post Retorna el enter N
*/
int Area_Magatzem::plazas() const{
      return n;
}

/** @brief Consultora del tamany M (M = cantidad de filas)
      \pre <em>Cert</em>
      \post Retorna el enter M
*/
int Area_Magatzem::filas() const{
      return m;
}

/** @brief Consultora de l'altura maxima del area magatzem
      \pre <em>Cert</em>
      \post Retorna el enter H
*/
int Area_Magatzem::altura() const{
      return h;
}


/** @brief Busca el millor lloc per afegir un contenidor al area magatzem
      \pre <em>Cert</em>
      \post S'ha retornat la posicio i la longitud del lloc que s'ha trobat, si no s'ha trobat cap retorna un segment amb l = 0;
*/
// ENTREGA INTERMEDIA SIEMPRE HABRA UN SITIO DONDE PONER EL CONTENEDOR
Ubicacion Area_Magatzem::best_fit(Contenedor c){
      int i = 0; // punter a les hileres m
      Ubicacion u;
      bool found = false;
      while (i < m and not found){
            u = v[i].best_fit_aux(c,i);
            if(u.hilera() != -1) found = true;
            else ++i;
      }
      return u;
}


//Operadors

/** @brief Inserta un contenidor al terminal 
      \pre <em>Cert</em>
      \post El contenidor s'ha afegit al cjt i a la matriu/llista i 
*/
void Area_Magatzem::inserta_contenedor(string m, int l,Ubicacion& u){
      Contenedor c(m,l);
      u = best_fit(c);
      
      for(int i = 0; i < l; ++i){
            v[u.hilera()][u.piso()][u.plaza() + i] = m;
      }

} // ADMENT COM A COMANDA i


/** @brief Elimina un contenidor del terminal
      \pre <em>Cert</em>
      \post Si el contenidor no existeix al terminal s'imprimeix error altrament el contenidor es borrat del terminal
*/
void Area_Magatzem::retira_contenidor(Segmento s){
      int n = s.ubic().hilera();
      int m = s.ubic().plaza();
      int h = s.ubic().piso();
      int l = s.longitud();
      for (int i = m; i < m+l; ++i){
            v[n][i][h] = "";
      }
} // ADMENT COM A COMANDA r



// Entrada/Sortida


/** @brief Imprimeix el nombre de hileres
      \pre <em>Cert</em>
      \post S'ha escrit el nombre d'hileres
*/
void Area_Magatzem::print_num_hileras(){
      cout << n << endl;
}

/** @brief Imprimeix el nombre de places
      \pre <em>Cert</em>
      \post S'ha escrit el nombre de places en una hilera
*/
void Area_Magatzem::print_num_plazas(){
      cout << m << endl;
}

/** @brief Imprimeix el nombre de pisos
      \pre <em>Cert</em>
      \post S'ha escrit el nombre pisos en la plaça d'una hilera
*/
void Area_Magatzem::print_num_pisos(){
      cout << h << endl;
}


/** @brief Imprimeix la matricula del contenidor que ocupa la posicio (i,j,k) si es buida, no s'imprimeix res, 
 *          si no es valida s'imprimeix error
      \pre <em>Cert</em>
      \post Retorna la posicio
*/
void Area_Magatzem::print_contenedor_ocupa(int i,int j,int k){
      if( (i > n or j > m or k > h) or (i < 0 or j < 0 or k < 0)){
            cout << "ERROR: la ubicacio <" << i << "," << j << "," << k << "> esta fora dels limits del area de magatzem" << endl;
      }
      else if (v[i][j][k].empty()) cout << endl;
      else cout << v[i][j][k] << endl;
}

/** @brief Imprimeix l'area principal utilitzant la lletra inicial de m de forma bidimensional per fileres en ordre ascendent indicant pis i plaça
      \pre <em>Cert</em>
      \post S'ha escrit els contenidors a l'area principal per fileres de forma bidimensional
*/
void Area_Magatzem::print_area_almacenaje(){
      int hileras = v.size();
      for (int i = 0; i < hileras; ++i){
            cout << "hilera " << i << endl;
            v[i].print_hilera();
            cout << endl;
      }
} // Si el numero de hileras es superior a nueve se vuelve a empezar por 0

/** @brief Imprimeix una llista dels espais segons tamany de menor a major, si el tamany es igual, segons hilera i si es igual segons la plaça
      \pre <em>Cert</em>
      \post S'ha escrit els contenidors a l'area principal per fileres de forma bidimensional
*/
void Area_Magatzem::print_huecos(){
      vector<Segmento> v_huecos;
      for(int i = 0; i < n; ++i){
            v[i].print_huecos_hilera(i,v_huecos);
      }
      // v_huecos.sort(v.begin(),v.end(),)
}
