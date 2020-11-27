/** @file Area_Magatzem.hh
    @brief Especificació de la classe Area_Magatzem 
*/

#ifndef _AREA_MAGATZEM
#define _AREA_MAGATZEM

#include "Segmento.hh"
#include "Contenedor.hh"
#include "Hilera.hh"
#include "Area_Espera.hh"
#include "Huecos.hh"

using namespace std;

/** @class Area_Magatzem
    @brief Representa el area de magatzem del terminal
*/
class Area_Magatzem {

private:

int n,m,h;
vector <Hilera> v;
// Area_Espera a_espera;

public:

//Constructores

/** @brief Creadora
      \pre <em>Cert</em>
      \post  El resultat és un area magatzem amb N,M,H > 0 i una area d'esepera
*/ 
Area_Magatzem(int n, int m, int h);


//Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Area_Magatzem
*/  
~Area_Magatzem();


//Consultores

/** @brief Consultora del tamany N (N = cantidad de plazas)
      \pre <em>Cert</em>
      \post Retorna el enter N
*/
int plazas() const;

/** @brief Consultora del tamany M (M = cantidad de filas)
      \pre <em>Cert</em>
      \post Retorna el enter M
*/
int filas() const;

/** @brief Consultora de l'altura maxima del area magatzem
      \pre <em>Cert</em>
      \post Retorna el enter H
*/
int altura() const;

/** @brief Retorna la matricula del contenidor de la ubicacio(i,j,k)
      \pre <em>Cert</em>
      \post S'ha retornat la matricula
*/

string contenedor_ocupa(int i, int j, int k);

//Operadors

/** @brief Inserta un contenidor al terminal 
      \pre <em>Cert</em>
      \post El contenidor s'ha afegit al cjt i a la matriu/llista i 
*/
void inserta_contenedor(string m, int l, Ubicacion u); // ADMENT COM A COMANDA i

/** @brief Elimina un contenidor del terminal
      \pre <em>Cert</em>
      \post Si el contenidor no existeix al terminal s'imprimeix error altrament el contenidor es borrat del terminal
*/
void retira_contenidor(Segmento s); // ADMENT COM A COMANDA r



// Entrada/Sortida


void print_num_hileras();

/** @brief Imprimeix el nombre de places
      \pre <em>Cert</em>
      \post S'ha escrit el nombre de places del area de magatzem
*/
void print_num_plazas();

/** @brief Imprimeix el nombre de pisos
      \pre <em>Cert</em>
      \post S'ha escrit el nombre pisos del area de magatzem
*/
void print_num_pisos();


/** @brief Imprimeix la matricula del contenidor que ocupa la posicio (i,j,k) si es buida, no s'imprimeix res, 
 *          si no es valida s'imprimeix error
      \pre <em>Cert</em>
      \post Retorna la posicio
*/
void print_contenedor_ocupa(int i,int j,int k);

/** @brief Imprimeix l'area principal utilitzant la lletra inicial de m de forma bidimensional per fileres en ordre ascendent indicant pis i plaça
      \pre <em>Cert</em>
      \post S'ha escrit els contenidors a l'area principal per fileres de forma bidimensional
*/
void print_area_almacenaje(); // Si el numero de hileras es superior a nueve se vuelve a empezar por 0


};
#endif
