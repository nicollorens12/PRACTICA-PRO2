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

class A_espera {
    public:

//Constructores

/** @brief Creadora
      \pre <em>Cert</em>
      \post El resultat és un terminal d'espera
*/ 
A_espera(); //CAL? No se si es dona el cas d'una creacio de terminal sense arguments


//Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Terminal d'espera
*/  
~A_espera();


//Consultores

//Modificadores

private:

    list l_espera;

};
#endif
