#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double monte_carl_pi( int numtotal ){
    int inside_num ;

    for (int i = 0 ; i < numtotal ; i ++ ){
        double x = static_cast < double > (rand()) / RAND_MAX ;
        double y = static_cast < double > (rand()) / RAND_MAX ;

        if ( x * x + y * y < 1 ){
            inside_num  ++ ;
        } 
    }
    return 4 * static_cast < double > (inside_num) / numtotal ;
}

int main(){
    srand(static_cast<unsigned int>(time(0)));
    int times ;
    while (true) {
    cout << "input your times :" << endl ;
    cin >> times ;
    while ( times > 0 ){
        cout << monte_carl_pi ( 1000000 ) << endl ;
        times -- ;
    }
    }
    return 0 ;
}