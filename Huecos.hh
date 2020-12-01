#ifndef _HUECOS
#define _HUECOS

#include "Ubicacion.hh"
#include "Segmento.hh"
#include "Contenedor.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <vector>
#endif

typedef pair<int,pair<int,int>> Clau;

class Huecos{

public:

//Constructora
/** @brief Creadora
      \pre <em>Cert</em>
      \post El resultat és mapa de huecos buit;
*/
Huecos(int n, int m);

//Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Huecos
*/  
~Huecos();

//Consultora
/** @brief Consulta la millor ubicacio per insertar un contenidor de tamany l
      \pre <em>Cert</em>
      \post S'ha retornat la ubicacioo
*/
Ubicacion best_fit(int l);

/** @brief Transforma un segmento en un pair del mapa implicit de la clase huecos
      \pre <em>Cert</em>
      \post S'ha un pair amb clau i int extret del segment s
*/
pair<Clau,int> segmento_a_clau(Segmento s);

//Modificadora

/** @brief Actualitza el mapa del forats despres de afegir un contenidor
      \pre <em>Cert</em>
      \post S'ha actualitzat el mapa 
*/
void actualiza_huecos_insertar(vector<Segmento> huecos_hilera,int hilera);

/** @brief Actualitza el mapa del forats despres de eliminar un contenidor
      \pre <em>Cert</em>
      \post S'ha actualitzat el mapa 
*/
void actualiza_huecos_borrar(vector<Segmento> huecos_hilera,int hilera);

/** @brief Actualitza el mapa del forats al complert
      \pre <em>Cert</em>
      \post S'ha actualitzat el mapa 
*/
void renueva_huecos(vector<Segmento> huecos);

//Operador

//Consultora
/** @brief Consulta el tamany del mapa
      \pre <em>Cert</em>
      \post S'ha retornat el tamany 
*/
int tamany();

//Entrada/Sortida

/** @brief Impresora del forats
      \pre <em>Cert</em>
      \post S'han impres els forats
*/
void print_huecos();

private:

// map<pair<l,pair<i,j>>,h>
map<Clau,int> huec;
Ubicacion extrae_ubi(map<Clau,int>::const_iterator it);
map<Clau,int>::const_iterator bin_search(int l, int hil, int pla);

};

#endif