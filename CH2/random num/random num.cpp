#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

const int N_TRAILS = 10;
int main(){
    cout << "RAND_MAX IS " << RAND_MAX << endl;
    cout << "the first " << N_TRAILS << " calls to rand : " << endl;
    for (int i = 0 ; i < N_TRAILS ; i++){
        cout << setw(5) << rand() << endl;
    }
    return 0;
}