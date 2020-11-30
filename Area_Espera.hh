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

/** @brief Retira un element al area de espera (en base a un iterador)
      \pre <em>Cert</em>
      \post S'ha retirat un contenidor de la llista i retornat un iterador al seguent element
*/
list<Contenedor>::iterator retira_a_espera(list<Contenedor>::iterator);

/** @brief Retira un contenidor del area de espera
      \pre <em>Cert</em>
      \post S'ha retirat un contenidor de la llista
*/
void retira_elem_a_espera(Contenedor c);

//Consultora

/** @brief Consulta el element que apunta l'iterador
      \pre <em>Cert</em>
      \post S'ha retornat el contenidor indicat per l'iterador
*/
Contenedor consulta_element(list<Contenedor>::iterator it);

/** @brief Retorna un iterador al principi de la llista
      \pre <em>Cert</em>
      \post S'ha el iterador
*/
list<Contenedor>::iterator inici();

/** @brief Retorna un iterador al final de la llista
      \pre <em>Cert</em>
      \post S'ha el iterador
*/
list<Contenedor>::iterator final();

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
