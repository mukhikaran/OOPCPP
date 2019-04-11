#include <iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int input(char row){
    int result;
    int rowInt = (int)(row - '0');
    if(rowInt<1||rowInt>8) throw  2; //Column exception
    else result= rowInt;
    return result;
}
int main(){
    srand(int(time(0)));
    int randomval = rand() % 2;
    cout << randomval << endl;
    return 0;
}

