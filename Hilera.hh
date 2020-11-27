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

/** @brief Retorna la matricula del contenidor que ocupa la posicio (x,y)
      \pre <em>Cert</em>
      \post S'ha retornat la posicio
*/
string elemen_pos(int x, int y);

// Modificadores

/** @brief Inserta el contenidor c en una ubicacio m,h determinada 
      \pre <em>Cert</em>
      \post La hilera ara te la matricula escrita en les posicions m,h fins m+l,h
*/
void modifica_hilera(int m, int h, string matricula, int l);



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
void huecos_hilera(int i,vector<Segmento>& v);

/** @brief Imprimeix la matricula de la posicio (x,y)
      \pre <em>Cert</em>
      \post S'ha impres la matricula
*/
void print_pos(int x, int y);

//Operadors 
Row operator[](int i) const;

private:
    Matrix mat;
    
};

#endif
