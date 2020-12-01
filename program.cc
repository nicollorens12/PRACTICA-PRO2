/** @file program.cc
    @brief Programa principal
*/
#include "Area_Magatzem.hh"
#include "Cjt_Contenidors.hh"
#include "Huecos.hh"
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
        Huecos huec(n,m);

        cout << "#" << comando << " " << n << " " << m << " " << h << endl;
        cin >> comando;

        while (comando != "fin" and comando != "crea_terminal") {
        cout << "#" << comando;

        if (comando == "inserta_contenedor" or comando == "i"){ 

            string matricula;
            int l;
            cin >> matricula >> l;
            cout << " " << matricula << " " << l << endl;
            if(not contenidor.exists(matricula)){
                Ubicacion u = huec.best_fit(l);
                if(u.hilera() == -1){
                    Ubicacion u_aux(-1,0,0);
                    u_aux.print();
                    cout << endl;
                    Segmento s(u_aux,l);
                    area.inserta_contenedor_area_espera(matricula,l);
                    contenidor.inserta_contenedor(matricula,s);
                }
                else{
                    u.print();
                    cout << endl;
                    area.inserta_contenedor(matricula,l,u);
                    Segmento s(u,l);
                    contenidor.inserta_contenedor(matricula,s);
                    vector<Segmento> v_huecos;
                    area.huecos(v_huecos);
                    /*cout << "ESTOS SON LOS HUECOS QUE DEVUELVE" << endl << endl;
                    for(int i = 0; i < v_huecos.size(); ++i){
                        v_huecos[i].print();
                        cout << endl;
                    }
                    */
                    huec.renueva_huecos(v_huecos);
                    //huec.actualiza_huecos_insertar(v_huecos,u.hilera());
                    area.inserta_contenidors_en_espera(huec,contenidor);
                }
                
            }

            else cout << "error: el contenedor ya existe" << endl;
            
        }

        else if(comando == "retira_contenedor" or comando == "r"){ 
            string matricula;
            cin >> matricula;
            cout << " " << matricula << endl;
            Segmento s = contenidor.consulta_contenidor(matricula);

            if(s.ubic().hilera() == -1 and s.ubic().plaza() == 0 and s.ubic().piso() == 0){ //ESTA EN EL AREA DE ESPERA??
              
                area.retira_contenedor_area_espera(matricula,contenidor.consulta_contenidor(matricula).longitud());
                contenidor.retira_contenidor_cjt(matricula);
            }

            else if(s.ubic().plaza() != -1){

                area.retira_contenidor(s,contenidor); //SOLO CAMBIAMOS HUECOS DE LA HILERA CON LA QUE TRABAJAMOS PERO SI ANADIMOS ALGO EN OTRA HILERA DEL A ESPERA QUE??
                vector<Segmento> v_huecos;  //RECALCULAMOS TODO PERO SIGUE SIN IR, DETECTA UN HUECO QUE NO TOCA, mira huecos_hilera (aux de funcion huecos del area(abajo))
                area.huecos(v_huecos);
                huec.renueva_huecos(v_huecos);          
                //huec.actualiza_huecos_borrar(v_huecos,s.ubic().hilera());
                area.inserta_contenidors_en_espera(huec,contenidor);
                contenidor.retira_contenidor_cjt(matricula);
                
            }
    
            else cout << "error: el contenedor no existe" << endl;
           
        }

        else if (comando == "donde"){
            string matricula;
            cin >> matricula;
            cout << " " << matricula << endl;
            contenidor.ubi(matricula).print();
            cout << endl;
        }

        else if (comando == "longitud"){
            string matricula; 
            cin >> matricula;
            cout << " " << matricula << endl;
            if(contenidor.longitud(matricula) != -1) cout << contenidor.longitud(matricula) << endl;
            else cout << "error: el contenedor no existe" << endl;
        }

        else if (comando == "contenedor_ocupa"){
            int i,j,k;
            cin >> i >> j >> k;
            cout << " " << i << " " << j << " " << k  << endl;
            area.print_contenedor_ocupa(i,j,k);
        }

        else if (comando == "num_pisos"){
            cout << endl;
            area.print_num_pisos();
        }
        else if (comando == "num_hileras"){
            cout << endl;
            area.print_num_hileras();
        }
        else if (comando == "num_plazas"){
            cout << endl;
            area.print_num_plazas();
        }

        else if (comando == "area_espera"){
            cout << endl;
            area.print_area_espera();
        }

        else if (comando == "contenedores"){
            cout << endl;
            contenidor.print_contenedores();
            cout << endl;
        }

        else if (comando == "area_almacenaje"){
            cout << endl;
            area.print_area_almacenaje();
        }
        
        else if (comando == "huecos"){
            cout << endl;
            huec.print_huecos();
        }

        cin >> comando;
        }
    }
}
/**@fn main
 * @code

@endcode
*/
