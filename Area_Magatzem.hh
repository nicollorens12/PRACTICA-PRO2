/** @file Area_Magatzem.hh
    @brief Especificació de la classe Area_Magatzem 
*/

#ifndef _AREA_MAGATZEM
#define _AREA_MAGATZEM

#include "Segmento.hh"
#include "Contenedor.hh"
#include "Hilera.hh"
#include "Area_Espera.hh"
#include "Cjt_Contenidors.hh"

using namespace std;

/** @class Area_Magatzem
    @brief Representa el area de magatzem del terminal
*/
class Area_Magatzem {
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

/** @brief Consultora del tamany total (N,M,H) del area magatzem
      \pre <em>Cert</em>
      \post El resultat és la terna <N,M,H>
*/
Ubicacion t_size();

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

/** @brief Consultora de si una ubicacio te tamany l lliure
      \pre <em>Ubicacion certa</em>
      \post Retorna si hi cap un contenidor de tamany l a la posicio indicada
*/
bool es_valid(Ubicacion pos,int l);


/** @brief Busca el millor lloc per afegir un contenidor al area magatzem
      \pre <em>Cert</em>
      \post S'ha retornat la posicio i la longitud del lloc que s'ha trobat, si no s'ha trobat cap retorna un segment amb l = 0;
*/
Segmento best_fit(vector<Hilera> v);



//Operadors

/** @brief Inserta un contenidor al terminal 
      \pre <em>Cert</em>
      \post El contenidor s'ha afegit al cjt i a la matriu/llista i 
*/
void inserta_contenedor(string m, int l); // ADMENT COM A COMANDA i

/* 

/** @brief Elimina un contenidor del terminal
      \pre <em>Cert</em>
      \post Si el contenidor no existeix al terminal s'imprimeix error altrament el contenidor es borrat del terminal
*/
void retira_contenidor(string m); // ADMENT COM A COMANDA r



// Entrada/Sortida

/** @brief Imprimeix la ubicacio del contenidor amb matricula m, si no existeix imprimira (-1,-1,-1), si esta al area 
           d'espera s'imprimira (-1,0,0) altrament imprimira la seva ubicacio en el area magatzem
      \pre <em>Cert</em>
      \post S'ha escrit la ubicacio
*/
static void print_ubi(string m); 

/** @brief Imprimeix la longitud l d'un contenidor amb matricula m
      \pre <em>Cert/em>
      \post S'ha escrit la longitud o un error en cas de que no existeixi un contenidor amb matricula m 
*/
static void print_longitud (string m);

/** @brief Imprimeix el nombre de hileres
      \pre <em>Cert</em>
      \post S'ha escrit el nombre d'hileres
*/
static void print_num_hileras();

/** @brief Imprimeix el nombre de places
      \pre <em>Cert</em>
      \post S'ha escrit el nombre de places en una hilera
*/
static void print_num_plazas();

/** @brief Imprimeix el nombre de pisos
      \pre <em>Cert</em>
      \post S'ha escrit el nombre pisos en la plaça d'una hilera
*/
static void print_num_pisos(int n, int m);


/** @brief Imprimeix la matricula del contenidor que ocupa la posicio (i,j,k) si es buida, no s'imprimeix res, 
 *          si no es valida s'imprimeix error
      \pre <em>Cert</em>
      \post Retorna la posicio
*/
static void print_contenedor_ocupa(int i,int j,int k);

/** @brief Imprimeix l'area principal utilitzant la lletra inicial de m de forma bidimensional per fileres en ordre ascendent indicant pis i plaça
      \pre <em>Cert</em>
      \post S'ha escrit els contenidors a l'area principal per fileres de forma bidimensional
*/
static void print_area_almacenaje(); // Si el numero de hileras es superior a nueve se vuelve a empezar por 0

/** @brief Imprimeix una llista dels espais segons tamany de menor a major, si el tamany es igual, segons hilera i si es igual segons la plaça
      \pre <em>Cert</em>
      \post S'ha escrit els contenidors a l'area principal per fileres de forma bidimensional
*/
static void print_huecos();

private:

Cjt_Contenidors contenidors;
int n,m,h;
vector <Hilera> v;
Area_Espera a_espera;

};
#endif
