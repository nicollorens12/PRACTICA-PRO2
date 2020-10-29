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
 
private:
map<string,Segmento> cjt;
};
#endif