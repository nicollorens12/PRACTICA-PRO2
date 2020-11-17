/** @file program.cc
    @brief Programa principal
*/
#include "Area_Magatzem.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#endif

using namespace std;

int main(){
    string comando;
    cin >> comando;
    while (comando != "fin") {
    // comando == "crea_terminal N M H"
        int n,m,h;
        cin >> n >> m >> h;
        Area_Magatzem area(n,m,h); //t
        Cjt_Contenidors contenidor; //conj
        cin >> comando;
        while (comando != "fin" and comando != "crea_terminal") {

        if (comando == "inserta_contenedor" or comando == "i"){
            string matricula;
            int l;
            cin >> matricula >> l;
            Ubicacion u;
            area.inserta_contenedor(matricula,l,u);
            Segmento s(u,l);
            contenidor.inserta_contenedor(matricula,s);
        }

        else if(comando == "retira_contenedor" or comando == "r"){
            string matricula;
            cin >> matricula;
            Segmento s = contenidor.consulta_contenidor(matricula);
            contenidor.retira_contenidor_cjt(matricula);
            area.retira_contenidor(s);
        }

        else if (comando == "donde"){
            string matricula;
            cin >> matricula;
            contenidor.ubi(matricula);
        }

        else if (comando == "longitud"){
            string matricula; 
            cin >> matricula;
            contenidor.longitud(matricula);
        }

        else if (comando == "contenedor_ocupa"){
            int i,j,k;
            cin >> i >> j >> k;
            area.print_contenedor_ocupa(i,j,k);
        }

        else if (comando == "num_pisos"){
            int i,j;
            cin >> i >> j;
            area.print_num_pisos();
        }

        else if (comando == "num_hileras") area.print_num_hileras();
        else if (comando == "num_plazas") area.print_num_plazas();
        // else if (comando == "area_espera") Area_Espera::print_a_espera();
        else if (comando == "contenedores") contenidor.print_contenedores();
        else if (comando == "area_almacenaje") area.print_area_almacenaje();
        else if (comando == "huecos") area.print_huecos();

        cin >> comando;
        }
    }
}
/**@fn main
 * @code
int main(){
    string comando;
    cin >> comando;
    while (comando != "fin") {
    // comando == "crea_terminal N M H"
        int n,m,h;
        cin >> n >> m >> h;
        Area_Magatzem(n,m,h);
        cin >> comando;
        while (comando != "fin" and comando != "crea_terminal") {

        if (comando == "inserta_contenedor" or comando == "i"){
            string matricula;
            int l;
            cin >> matricula >> l;

        }

        else if(comando == "retira_contenedor" or comando == "r"){
            string matricula;
            cin >> matricula;
        }

        else if (comando == "donde"){
            string matricula;
            cin >> matricula;
            print_ubi(matricula);
        }

        else if (comando == "longitud"){
            string matricula; 
            cin >> matricula;
            print_longitud(matricula);
        }

        else if (comando == "contenedor_ocupa"){
            int i,j,k;
            cin >> i >> j >> k;
            print_contenedor_ocupa(i,j,k);
        }

        else if (comando == "num_pisos"){
            int i,j;
            cin >> i >> j;
            print_num_pisos(i,j);
        }

        else if (comando == "num_hileras") print_num_hileras();
        else if (comando == "num_plazas") print_num_plazas();
        else if (comando == "area_espera")print_a_espera();
        else if (comando == "contenedores") print_contenedores();
        else if (comando == "area_almacenaje") print_area_almacenaje();
        else if (comando == "huecos") print_huecos();

        cin >> comando;
        }
    }
}
@endcode
*/
