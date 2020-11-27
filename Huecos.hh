#ifndef _HUECOS
#define _HUECOS

#include "Ubicacion.hh"
#include "Segmento.hh"
#include "Contenedor.hh"
#include "Area_Magatzem.hh"

#ifndef NO_DIAGRAM
#include <map>
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

//Modificadora
void actualiza_huecos_insertar(Segmento s, int h);
void actualiza_huecos_borrar(Segmento s, int h);
//Operador

//Consultora
/** @brief Actualitza el mapa del forats
      \pre <em>Cert</em>
      \post S'ha actualitzat el mapa 
*/
void actualiza_huecos(Segmento s,string comando);

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

};

#endif