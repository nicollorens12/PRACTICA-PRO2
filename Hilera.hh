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

/** @brief Borra el contenidor de la hilera
      \pre <em>Cert</em>
      \post La ubicacio del contenidor es buida 
*/
void borra_contenidor_hilera(Segmento s);

/** @brief Borra la la matricula d'una posicio determinada
      \pre <em>Cert</em>
      \post La ubicacio del (m,h) es buida 
*/
void borra_elem(int m, int h);



//Entrada/Salida

/** @brief Imprimeix la posicio i la matricula dels contenidors de la filera. Auxiliar de la funcio print_area_almacenaje()
      \pre <em>Cert</em>
      \post S'ha impres la filera
*/
void print_hilera() const; 

/** @brief Guarda els forats disponibles (posicio i longitud) a la filera. Auxiliar de la funcio print_huecos()
      \pre <em>Cert</em>
      \post S'ha guardat els forats disponibles a la filera en un vector
*/
void huecos_hilera(int n,vector<Segmento>& v) const;

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
