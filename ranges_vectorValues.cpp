#include <iostream>
#include <optional>
#include <ranges>
#include <algorithm>
#include <charconv>
#include <numeric>

int main()
{

    std::vector<std::string> a({"0.7", "1.1", "2.45", "garbage", "12.1"});
    std::vector<double> result;

    for (auto el : a 
        | std::ranges::views::transform([](auto str, double value=0)->std::optional<double>{
            std::from_chars(str.data(), str.data()+str.size(), value, std::chars_format::general);
            return value;})
        | std::ranges::views::filter([](auto opt){return 0!=opt;})){
            std::cout<<"El value: "<<el.value()<<std::endl;
            result.push_back(el.value());
    }

    std::cout<<"Mean of vector values: "<<1.0*std::accumulate(result.begin(), result.end(), 0.0) / result.size();
    

}

