#include <iostream>
#include <string>
#include <functional>

long int factorial(long int x, long int buffer=1 ) {
    if ( x <= 0  )
        return buffer;
    else
        return factorial( x - 1, buffer * x );
}

float binominal(float n, float k, float buffer=1){

    if (k == 0)
        return buffer;
 
    return binominal(n-1, k-1, buffer*n/k);
}


int main() {

    auto res = binominal(8,4);
    std::cout<<res;
}