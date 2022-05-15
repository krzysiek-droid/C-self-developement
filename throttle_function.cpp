#include <iostream>
#include <string>
#include <functional>
#include <cstdarg>
#include <tuple>

using namespace std;

void print_count(const string msg , int count) { std::cout << msg <<
count << std::endl; }
void print_count_pair(const string msg , int count1, int count2) {
std::cout << msg << count1 << " " << count2 << std::endl; }

template<typename RET, typename ... ARG>
std::tuple<ARG...> args_tuple( RET(*)(ARG...) ) {
    return std::tuple<ARG...>();
}

template<class F>
struct throttle{
    //member variables
    F m_func;
    decltype(args_tuple(m_func)) prev_args;
    int repeats=0;

    //constructor
    throttle(F func): m_func(func){
    }

    //call operator overload
    //(auto ... args) and (args...) was a salvation here ^^
    void operator() (auto ... args) {
        auto called_args = make_tuple(args...);
        if(called_args == prev_args){
            if (repeats == 0){
                ++repeats;
                cout<<"..."<<endl;
            } 
        }else{
            prev_args = called_args;
            std::apply(m_func, called_args);
        }
    };
};


int main() {

    auto t_print_count = throttle(print_count);
    auto t_print_count_pair = throttle(print_count_pair);
    t_print_count("my c1: ", 1); // my c1: 1
    t_print_count("my c2: ", 1); // my c2: 1
    t_print_count("my c1: ", 1); // my c1: 1
    t_print_count("my c1: ", 1); // ...
    t_print_count("my c1: ", 1); //
    t_print_count_pair("my c1 and c2: ", 1, 7); // my c1 and c2: 1 7
    t_print_count_pair("my c1 and c3: ", 1, 7); // my c1 and c3: 1 7
    t_print_count_pair("my c1 and c3: ", 1, 7); // ...
    t_print_count_pair("my c1 and c3: ", 1, 7); //
    t_print_count_pair("my c1 and c3: ", 1, 7); //
}