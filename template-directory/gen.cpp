#include <iostream>
using namespace std;


int rnd(int poc, int kon){
    return poc + rand() % (kon - poc + 1);
}

int main(int argc, char* argv[]){
    srand(atoi(argv[1]));
    int n = 10;
    cout << "1\n" << n << endl;
    for (int i = 0; i < n; i ++){
        cout << rnd(0, 3) << " ";
    }

    return 0;
}