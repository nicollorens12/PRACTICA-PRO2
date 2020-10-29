/** @file Area_Magatzem.hh
    @brief Especificació de la classe Area_Magatzem 
*/

#ifndef _
#define _

#include "Segmento.hh"
#include "Contenedor.hh"

#ifndef NO_DIAGRAM
#include <map>
#include <string>
#endif

using namespace std;

class Cjt_contenidors {

public:
//Constructores;

/** @brief Creadora
      \pre <em>Cert</em>
      \post El resultat és mapa de contenidors buit;
*/ 
Cjt_contenidors();

//Destructora
/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Cjt_contenidors
*/  
~Cjt_contenidors();

//Consultora
/** @brief Consultora de la ubicacio del contenidor amb matricula m, si es buit retorna (-1,-1,-1) y 
 *          si es al area de espera retorna (-1,0,0)
      \pre <em>Cert</em>
      \post Retorna la ubicacio del contenidor
*/
Ubicacion ubi(string m);

//Operadors

/** @brief Inserta un contenidor en el terminal
      \pre <em>Cert</em>
      \post El contenidor s'ha afegit al Cjt i si ja hi existia el Cjt no s'ha modificat
*/
void inserta_contenedor_cjt(string m, Segmento s);

/** @brief Elimina un contenidor del terminal
      \pre <em>Cert</em>
      \post El contenidor s'ha retirat del Cjt si hi era i si no no s'ha modificat
*/
void retira_contenidor_cjt(string m); 


private:

map<string,Segmento> cjt;

};
#endif