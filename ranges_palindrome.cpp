#include <ranges>
#include <iostream>
#include <algorithm>
 
int main()
{
    auto const ints = {3, 4, 5, 5, 4, 3};

    if (std::ranges::equal(std::ranges::ref_view(ints), std::ranges::reverse_view(ints)))
        std::cout<<"is palindrome";
    else
        std::cout<<"is not palindrome";
}