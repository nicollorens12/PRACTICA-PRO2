/** @file Hilera.hh
    @brief Especificació de la classe Hilera 
*/

#ifndef _HILERA
#define _HILERA

#include "Ubicacion.hh"
#include <vector>

using namespace std;

typedef vector<string> Row;
typedef vector<Row> Matrix;

/** @class Hilera
    @brief Representa una hilera de longitud M i altura H
*/
class Hilera {
public:

private:
    Matrix mat;
};

#endif
