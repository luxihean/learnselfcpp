#include <iostream>
using namespace std;

const int sentinel = 0;

int main(){
    cout<<"This program adds a list of numbers"<<endl;
    cout<<"use "<<sentinel<<" to signal the end"<<endl;
    int total = 0;
    while(1){
        int value;
        cout<<"input num :";
        cin>>value;
        if (value == sentinel) break;
        total +=value;
    }
    cout<<"the total is "<<total<<endl;
    return 0;
}