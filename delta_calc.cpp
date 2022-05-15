#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <cmath>

using namespace std;

auto delta = [](auto a, auto b, auto c){
    return b*b - 4*a*c;
};

//solution 1
template<typename T>
vector <T> solver(T a, T b, T c){
    cout << "Delta equel to: " << delta(a,b,c) << "\n";
    return delta(a,b,c) > 0 ? vector <T> {(-b - sqrt(delta(a,b,c))) / (2*a), (-b + (sqrt(delta(a,b,c)))) / (2*a)} : // if equation has 2 solutions
    delta(a,b,c) == 0 ? vector <T> {-b/2*a} : vector <T>(); // if equation has 1 or 0 solution
}

//solution 2
std::vector<double> solver1(auto a, auto b, auto c){
    cout << "Delta equel to: " << delta(a,b,c) << "\n";
    return delta(a,b,c) > 0 ? vector  {(-b - sqrt(delta(a,b,c))) / (2*a), (-b + (sqrt(delta(a,b,c)))) / (2*a)} : // if equation has 2 solutions
    delta(a,b,c) == 0 ? vector {-b/2*a} : vector<double>{}; // if equation has 1 or 0 solution
};

int main() {

    const double a = 1, b = 8, c = 4; //takes type double as solution requires square root
    const auto solution = solver1(a,b,c);
    // the solution is simply std::vector
    if ( solution.size() == 0 ) std::cout << "No solution \n";
    if ( solution.size() == 1 ) std::cout << "Single solution " <<
    solution[0] << "\n";
    if ( solution.size() == 2 ) std::cout << "Two solutions " << solution[0]
    << " " << solution[1] << "\n";
    
}