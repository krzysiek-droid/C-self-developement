#include <iostream>
#include <string>
#include <functional>

struct IF{
    
    //Constructor
    IF(bool _boolean, int _val){
        _boolean ? changeState(_val) : (*this);
    }

    //Operator() overload
    IF operator() (bool _boolean, int _val){
        return _boolean ? changeState(_val) : (*this);
    }

    //Operator() overload
    int operator() (int _val){
        return !m_state ? this->m_val : _val;
    }

    //Function to set IF member value (m_val) if given boolean is true
    IF changeState (int val){
        this->m_val = val;
        this->m_state = false;
        return (*this);
    }

    private:
        int m_val;
        bool m_state=true;

};


int main() {

    std::string v = "two";
    //const int a = IF(v=="one", 1).ELSEIF(v=="zero", 0).ELSE(-1);
    //or in a more compact way realying more on operator() overloading
    const int b = IF(v=="one", 1)(v=="zero", 0)(-1);

    std::cout <<"b value: " << b;
    
}