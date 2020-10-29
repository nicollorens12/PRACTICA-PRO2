/** @file Terminal.hh
    @brief Especificació de la classe Terminal 
*/

#ifndef _TERMINAL_ESPERA
#define _TERMINAL_ESPERA

#include <Contenedor.hh>
#ifndef NO_DIAGRAM
#include <map>
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
void 


private:

map<string,int l> t_e;

};
#endif
