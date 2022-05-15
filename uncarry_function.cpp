#include <iostream>
#include <string>
#include <functional>


auto uncarry(auto f){
    return [f] (auto a, auto b){ return f(a)(b);};
}

int main() {

    // given carried function
    auto f = [](int a) { return [a](int b){ return a + b; }; };
    auto uf = uncarry(f);
    int result = uf(1,2);
    
    std::cout << result << std::endl;



}