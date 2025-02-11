#include <iostream>
#include "random.h"
using namespace std;

int rolltwodice(){  //取两个随机数求和
    int d1 = randominteger(1 , 6) ;
    int d2 = randominteger(1 , 6) ;
    int total = d1 + d2;
    cout << "you rolled " << d1 << " and " << d2 << endl;
    cout << "total is :" << total << endl;
    return total;
}

bool end (int point){ //结束
    while (true){
        int total = rolltwodice();
        if (total == point ) return true ; //第二次投掷一直投到7lose
        if (total == 7 ) return false ;
    }
}

int randominteger(int low , int high){
    int r = rand()%( high - low + 1 ) + low ;
    return r ;
}

bool end (int point) ;
int rolltwodice() ;
int randominteger(int low , int high) ;

int main(){
    for (int i = 0; i < 10; i++){
    cout << "this is a program plays a game of crap ." << endl ;
    int point = rolltwodice();
    switch (point) {
        case 7 : case 11 :
        cout << "you win " << endl ;
        break;
        case 2 : case 3 : case 12 :
        cout << "you lose " << endl ;
        break;
        default :
        cout << "your point is " << point << endl;
        if (end (point)) {
            cout << "you win" << endl;
        }else {
            cout << "you rollesd seven . you lose ." << endl ;
        }
    }
    }
    return 0 ;
}

