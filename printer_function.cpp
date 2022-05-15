#include <iostream>
#include <string>
#include <functional>

using namespace std;

auto mul2 = [](int x ){ return x*2; };
auto sq = [](int x ){ return x*x; };

template <typename Func>
struct printer
{
    printer(Func fun): m_fun(fun){}

    int operator()(int arg)
    {
        cout << arg << " -> " << m_fun(arg) << "\n";
        return m_fun(arg);
    }
    
    Func m_fun;
};

int main() {

    // example
    
    auto printing_mul2 = printer(mul2);
    auto printing_sq = printer(sq);

    printing_mul2(10); // would produce output like: 10 -> 20
    printing_sq(8); // would produce output like: 8 -> 64

}