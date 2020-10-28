#include <Terminal.hh>

using namespace std;

int main(){
    string comando;
    
    cin >> comando;
    while (comando != "fin") {
    // comando == "crea_terminal N M H"
        procesa comando;
        lee comando;
        while (comando != "fin" and comando != "crea_terminal") {
        procesa comando;
        lee comando;
        }
    }
}