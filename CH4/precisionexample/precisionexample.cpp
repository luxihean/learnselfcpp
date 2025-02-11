#include <iostream> 
#include <iomanip> 
#include <cmath> 
using namespace std;

const double PI = 3.14159265358979323846 ; 
const double SPEED_OF_LIGHT = 2.99792458E+8;
const double FINE_STRUCTURE =7.2573525E-3;

void printPrecisionTable();

int main(){
    cout << uppercase << right;
    cout << "Default format:"<< endl << endl;
    printPrecisionTable();
    cout << endl << "Fixed format: "<< fixed << endl << endl;
    printPrecisionTable();
    cout << endl << "Scientific format:"<< scientific << endl << endl;
    printPrecisionTable();
    return 0;    
}
void printPrecisionTable(){
    cout << " prec |    pi       | speed of light   | fine-structure" << endl;
    cout << "------+-------------+-----------------+----------------" << endl;
    for (int prec = 0; prec <= 6; prec += 2) {
        cout << setw(4) << prec << " |";
        cout << " " << setw(12) << setprecision(prec) << PI << " |";
        cout << " " << setw(16) << setprecision(prec) << SPEED_OF_LIGHT << " |";
        cout << " " << setw(14) << setprecision(prec) << FINE_STRUCTURE << endl;
    }
}
