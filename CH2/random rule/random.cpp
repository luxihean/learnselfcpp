# include <iostream>
# include <cstdlib>
# include <cmath>
# include <ctime>
# include "random.h"//自建库文件不可包含空格
// # include "randominit.h"
using namespace std;

void initrandomseed(){
    static bool initialized = false ; //定义一个静态的局部变量
    if(!initialized){
        srand(int( time (NULL))) ; //如果没有初始化将读取当前的nuix时间作为种子数
        initialized = true ;
    }
}

void initrandomseed() ;

int randominteger (int low , int high){ //随机数的取值范围 [low , high)，因为比如我要投骰子，我需要输出6个随机数，我的随机数是[0 , 6),这其中就包含了六个区间，如果闭的话就是七个数了
    initrandomseed() ;
    double d = rand() / (double (RAND_MAX) + 1) ; //从cstlib库中读取10位随机数值rand(),并将值对应到[0 , 1)的区间，这里避免了rand()随机到最大值
    double s = d *(double (high) - low + 1) ; //按比例分配
    return int (floor (low + s)) ; //返回的是一个整数
}

double randomreal ( double low , double high){
    initrandomseed() ;
    double d = rand() / (double (RAND_MAX) + 1) ;
    double s = d *(double (high) - low + 1) ;
    return low + s ; //返回的是一个浮点数
}

bool randomchance (double p ){ //确保概率，避免出现比如rand()生成的都是一个区间的数
    initrandomseed() ;
    return randomreal(0 ,1) < p ;
}