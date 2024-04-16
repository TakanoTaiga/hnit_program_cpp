#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

auto pulse_ff(double x, size_t n) -> double
{
    auto result = 0.0;

    for(auto i = 0; i <= n; ++i){
        if(i % 2 == 0) continue;

        result += (1.0 / (double)i) * std::sin((double)i * x);
    }
    result *= 4 / (std::atan(1.0) * 4);
    result += 1;
    return result;
}

auto plot(const size_t n)
{
    std::ofstream svg_file;
    svg_file.open(std::to_string(n) + "_plot.svg");
    svg_file << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"2000\" height=\"500\">\n";
    svg_file << "<rect width=\"100%\" height=\"100%\" fill=\"white\"/>\n";

    for(double x = 0; x < 20; x += 0.001){
        const auto result =  pulse_ff(x, n);
        svg_file << "<circle cx=\"" << x * 100.0 + 50.0 << "\" cy=\"" << result * 100.0 + 50.0 << "\" r=\"1\" fill=\"black\" />\n";
    }

    svg_file << "</svg>\n";
    svg_file.close();
}

int main(void){
    plot(3);
    plot(8);
    plot(50);
}