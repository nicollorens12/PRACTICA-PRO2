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
#include "Cjt_Contenidors.hh"

using namespace std;

/** @class Area_Magatzem
    @brief Representa el area de magatzem del terminal
*/
class Area_Magatzem {

private:

int n,m,h;
vector <Hilera> v;
Area_Espera a_espera;

void borra_contenidor(Segmento s); //Esborra sense mirar si esta enterrat (aux de retira_contenidor)
void borra_encima_afegeix_a_espera(Segmento s,Cjt_Contenidors& cjt,Huecos& huec);
Segmento distancia_prox_c_izq(Segmento s);
Segmento distancia_prox_c_derecha(Segmento s);

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

/** @brief Retorna un vector amb els forats disponibles al area de magatzem
      \pre <em>Cert</em>
      \post El vector conte els forats del terminal
*/
void huecos(vector<Segmento>& v_huecos) const;

/** @brief Retorna un vector amb els forats disponibles a la hilera
      \pre <em>Cert</em>
      \post El vector conte els forats de la hilera
*/
void huecos_hilera(vector<Segmento>& v_huecos,int hilera) const;

/** @brief Imprimeix l'area d'espera
      \pre <em>Cert</em>
      \post S'ha impres l'area d'espera
*/
void print_area_espera() const;


//Operadors

/** @brief Inserta un contenidor al terminal 
      \pre <em>Cert</em>
      \post El contenidor s'ha afegit al cjt i a la matriu/llista i 
*/
void inserta_contenedor(string m, int l, Ubicacion u,Huecos& huec); 

/** @brief Inserta un contenidor al area de espera
      \pre <em>Cert</em>
      \post El contenidor s'ha afegit al area d'espera
*/
void inserta_contenedor_area_espera(string m, int l);

/** @brief Retira un contenidor del area de espera
      \pre <em>Cert</em>
      \post El contenidor s'ha retirat del area d'espera
*/
void retira_contenedor_area_espera(string m, int l);

/** @brief Elimina un contenidor del terminal
      \pre <em>Cert</em>
      \post Si el contenidor no existeix al terminal s'imprimeix error altrament el contenidor es borrat del terminal
*/
void retira_contenidor(Segmento s,Cjt_Contenidors& cjt, Huecos& huec);

/** @brief Inserta tots els contidors que es pugui del area d'espera
      \pre <em>Cert</em>
      \post S'han insertat els contenidors que hi cabien del area d'espera al area de magatzem
**/
void inserta_contenidors_en_espera(Huecos& huec,Cjt_Contenidors& cjt);

/** @brief Actualitza els forats del conjunt Huec que han estat modificats al retirar un contenidor (Utilitza parametres implicits de la clase Area_Magatzem)
 *          (Es modifica part del parametre implicit de la clase Huecos nomes amb consultes mai directament)
      \pre <em>Cert</em>
      \post S'han actualitzat el mapa dels forats 
**/
void actualiza_huecos_borrar(Segmento s,Huecos& huec);

/** @brief Actualitza els forats del conjunt Huec que han estat modificats al retirar un contenidor (Utilitza parametres implicits de la clase Area_Magatzem)
 *          (Es modifica part del parametre implicit de la clase Huecos nomes amb consultes mai directament)
      \pre <em>Cert</em>
      \post S'han actualitzat el mapa dels forats 
**/
void actualiza_huecos_insertar(Segmento s,Huecos& huec);




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
