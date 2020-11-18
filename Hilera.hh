/** @file Hilera.hh
    @brief Especificació de la classe Hilera 
*/

#ifndef _HILERA
#define _HILERA

#include "Ubicacion.hh"
#include "Segmento.hh"
#include "Contenedor.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <string>
#endif

using namespace std;

typedef vector<string> Row; 
typedef vector<Row> Matrix;

/** @class Hilera
    @brief Representa una hilera de longitud M i altura H
*/
class Hilera {
public:

//Creadora

/** @brief Creadora
      \pre <em>Cert</em>
      \post S'ha creat una filera m x h
*/
Hilera(int m,int h);

//Destructora

~Hilera();
/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix el objecte Hilera
*/  

// Consultores

/** @brief Busca el millor lloc per afegir un contenidor en un fila determinada. Auxiliar de la funcio best_fit()
      \pre <em>Cert</em>
      \post S'ha retornat la posicio i la longitud del lloc que s'ha trobat, si no s'ha trobat cap retorna un segment amb l = 0
*/
Ubicacion best_fit_aux(Contenedor c,int hilera);



//Entrada/Salida

/** @brief Imprimeix la posicio i la matricula dels contenidors de la filera. Auxiliar de la funcio print_area_almacenaje()
      \pre <em>Cert</em>
      \post S'ha impres la filera
*/
void print_hilera() const; 

/** @brief Imprimeix els forats disponibles (posicio i longitud) a la filera. Auxiliar de la funcio print_huecos()
      \pre <em>Cert</em>
      \post S'ha impres els forats disponibles a la filera
*/
void print_huecos_hilera(int i,vector<Segmento>& v);

//Operadors 
Row operator[](int i) const;

private:
    Matrix mat;
    
};

#endif
