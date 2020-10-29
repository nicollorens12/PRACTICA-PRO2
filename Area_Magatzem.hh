/** @file Area_Magatzem.hh
    @brief Especificació de la classe Area_Magatzem 
*/

#ifndef _AREA_MAGATZEM
#define _AREA_MAGATZEM

#include "Segmento.hh"
#include "Contenedor.hh"
#include "Hilera.hh"
#include "Area_espera.hh"
#include "Cjt_contenidors.hh"

using namespace std;

class Magatzem {
    public:

//Constructores

/** @brief Creadora sense arguments
      \pre <em>Cert</em>
      \post El resultat és un terminal amb N,M,H = 0
*/ 
Terminal(); //CAL? No se si es dona el cas d'una creacio de terminal sense arguments

/** @brief Creadora amb arguments
      \pre <em>Cert</em>
      \post El resultat és un terminal amb N,M,H > 0
*/ 
Terminal(int n, int m, int h);


//Destructora

/** @brief Destructora
      \pre <em>Cert</em>
      \post Destrueix un objecte Terminal
*/  
~Terminal();


//Consultores

/** @brief Consultora del tamany total (N,M,H) del terminal
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

/** @brief Consultora de l'altura maxima del terminal
      \pre <em>Cert</em>
      \post Retorna el enter H
*/
int altura() const;

/** @brief Consultora de si una ubicacio te tamany l lliure
      \pre <em>Ubicacion certa</em>
      \post retorna si hi cap un contenidor de tamany l a la posicio indicada
*/
bool es_valid(Ubicacion pos,int l);

/** @brief Consultora de la ubicacio del contenidor amb matricula m, si es buit retorna (-1,-1,-1) y 
 *          si es al area de espera retorna (-1,0,0)
      \pre <em>Cert</em>
      \post Retorna la ubicacio del contenidor
*/
Ubicacion ubi(string m);




//Operadors

/** @brief Inserta un contenidor en el terminal principal
      \pre <em>Contenidor valid</em>
      \post Si el contenidor ja existeix s'imprimeix un ERROR altrament si el contenidor te lloc al terminal principal 
            s'imprimira la seva posicio,si s'ha hagut d'afegir a la terminal d'espera s'imprimira (-1,0,0)
*/
void inserta_contenedor(string m, int l); // ADMENT COM A COMANDA i

/** @brief Elimina un contenidor del terminal principal
      \pre <em>Contenidor valid</em>
      \post Si el contenidor no existeix al terminal s'imprimeix error altrament el contenidor es borrat del terminal
*/
void retira_contenidor(string m); // ADMENT COM A COMANDA r



// Entrada/Sortida

/** @brief Imprimeix la ubicacio del contenidor amb matricula m, si no existeix imprimira (-1,-1,-1), si esta al area 
           d'espera s'imprimira (-1,0,0) altrament imprimira la seva ubicacio en el terminal principal
      \pre <em>Cert</em>
      \post S'ha escrit la ubicacio
*/
void donde(string m); 

/** @brief Imprimeix la longitud l d'un contenidor amb matricula m
      \pre <em>Cert/em>
      \post S'ha escrit la longitud o un error en cas de que no existeix contenidor amb matricula m a cap terminal
*/
void longitud (string m);

/** @brief Imprimeix el nombre de hileres
      \pre <em>Terminal creada</em>
      \post S'ha escrit el nombre d'hileres
*/
void num_hileras();

/** @brief Imprimeix el nombre de places
      \pre <em>Terminal creada</em>
      \post S'ha escrit el nombre de places en una hilera
*/
void num_plazas(int n);

/** @brief Imprimeix el nombre de pisos
      \pre <em>Terminal no creada</em>
      \post S'ha escrit el nombre pisos en la plaça d'una hilera
*/
void num_pisos(int n, int m);

/** @brief Imprimeix la llista de contenidors en l'area d'espera en ordre de sortida dels contenidors de forma m(l)
      \pre <em>Cert</em>
      \post S'ha escrit els contenidors a l'area d'espera
*/
void area_espera();

/** @brief Imprimeix la llista dels contenidors en ordre alfabetic ascendent de forma m(<i,j,k>,l)
      \pre <em>Terminal creada</em>
      \post S'ha escrit els contenidors a l'area principal 
*/
void contenedores();

/** @brief Imprimeix la matricula del contenidor que ocupa la posicio (i,j,k) si es buida, no s'imprimeix res, 
 *          si no es valida s'imprimeix error
      \pre <em>Cert</em>
      \post Retorna la posicio
*/
void contenedor_ocupa(Ubicacion u);

/** @brief Imprimeix l'area principal utilitzant la lletra inicial de m de forma bidimensional per fileres en ordre ascendent indicant pis i plaça
      \pre <em>Terminal creada</em>
      \post S'ha escrit els contenidors a l'area principal per fileres de forma bidimensional
*/
void area_almacenaje(); // Si el numero de hileras es superior a nueve se vuelve a empezar por 0

/** @brief Imprimeix una llista dels espais segons tamany de menor a major, si el tamany es igual, segons hilera i si es igual segons la plaça
      \pre <em>Terminal creada</em>
      \post S'ha escrit els contenidors a l'area principal per fileres de forma bidimensional
*/
void huecos();

private:

Cjt_contenidors contenidors;
int n,m,h;
vector <Hilera> v;
A_espera a_espera;

};
#endif
