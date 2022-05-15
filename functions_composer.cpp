#include <iostream>
#include <string>
#include <functional>


auto compose_3f( auto d, auto e, auto f) {
    return [d,e,f] (auto arg) { 
        return d(e(f(arg))); 
    };
}

int a(int x ) { return x+2; }
int b(int x) {  return x+3; };

int c(int x){ return x+4; };


int main() {
    auto f1 = compose_3f(c, b, a );
    std::cout<<"First composition: "<< f1(2) << std::endl;
    auto f2 = compose_3f (a,b,f1);
    std::cout<<"Second composition: "<< f2(2) << std::endl;

}