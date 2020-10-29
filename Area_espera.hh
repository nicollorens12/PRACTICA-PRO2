/** @file Area_Espera.hh
    @brief Especificació de la classe Area_Espera 
*/

#ifndef _AREA_ESPERA
#define _AREA_ESPERA

#include "Contenedor.hh"
#ifndef NO_DIAGRAM
#include <vector>
#endif

using namespace std;

class T_espera {
    public:

//Constructores

/** @brief Creadora
      \pre <em>Cert</em>
      \post El resultat és un terminal d'espera
*/ 
T_espera(); //CAL? No se si es dona el cas d'una creacio de terminal sense arguments


//Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Terminal d'espera
*/  
~T_espera();


//Consultores

//Modificadores

private:

    vector<Contenedor> area_e;

};
#endif
