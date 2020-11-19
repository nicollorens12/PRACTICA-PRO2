#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

int main(){
    
    Matrix mat(4,Row(4,5));
    for(int i = 0; i < 4; ++i){
        mat[0][i] = 0;
    }

    for(int j = 3; j >= 0; --j){
        for (int k = 0; k < 4; ++k){
            cout << mat[j][k] << " ";
        }
        cout << endl;
    }
}