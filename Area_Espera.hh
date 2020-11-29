/** @file Area_Espera.hh
    @brief Especificació de la classe Area_Espera 
*/

#ifndef _AREA_ESPERA
#define _AREA_ESPERA

#include "Contenedor.hh"
#ifndef NO_DIAGRAM
#include <list>
#endif

using namespace std;

/** @class Area_Espera
    @brief Representa el area d'espera del terminal
*/
class Area_Espera {
    public:

//Constructores

/** @brief Creadora
      \pre <em>Cert</em>
      \post El resultat és un area d'espera
*/ 
Area_Espera();

//Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte area d'espera
*/  
~Area_Espera();

//Modificacdora
/** @brief Inserta un element al area de espera
      \pre <em>Cert</em>
      \post S'ha insert un contenidor al principi de la llista
*/
void inserta_a_espera(Contenedor c);

//Consultora
/** @brief Consulta l'ultim elemento que ha entrat a la llista
      \pre <em>Cert</em>
      \post S'ha retornat l'ultim contenidor que ha entrat a la llista 
*/
Contenedor consulta_siguiente();

//Entrada/Salida

/** @brief Imprimeix l'area d'espera (matricula i longitud) en ordre de sortida
      \pre <em>Cert</em>
      \post S'ha impres l'area d'espera
*/  
void print_a_espera() const;

private:

    list<Contenedor> l_espera;

};
#endif
