#include <iostream>
using namespace std;

enum Month { JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

bool isleapyear(int year){//分阶段执行，需要全局声明或者是放在运用之前
    return((year % 4 == 0)&&(year % 100 != 0))|| (year % 400 == 0);
}

int dayinmonth(Month month,int year){
    switch (month){
        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
        return 30;
        case FEBRUARY:
        return (isleapyear(year))?29:28;
        default :
        return 31;
    }
}


int main(){
    int monthInput; 
    Month month;
    int year;
    while(1){        
        cout << "input your month(1-12):";
        cin >> monthInput;
        if (monthInput < 1 || monthInput > 12) {
            cout << "useless month input again:" << endl;
            continue;  // 如果无效，则跳过本次循环
        }
        month = static_cast<Month>(monthInput);

        cout <<"input your year:";
        cin >> year;
        cout << dayinmonth(month,year) << endl;

        char choice;
        cout << "weather continue (y/n): ";
        cin >> choice;
        if (choice != 'y' && choice != 'Y') {
            break;  // 如果用户输入不是 'y'，则退出
        }
    }
    return 0; 
}