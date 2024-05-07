#include <iostream>
#include <cmath>
#include <numbers>
#include <fstream>

auto func(double x) -> double
{
    return 4.0 * std::atan(x) - std::numbers::pi;
}

auto deltaFunc(double x) -> double
{
    return 4.0 / (1 + x * x);
}

int main(int argc, char *argv[]){
     std::ofstream svg_file;
    svg_file.open("_plot.svg");
    svg_file << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"2000\" height=\"500\">\n";
    svg_file << "<rect width=\"100%\" height=\"100%\" fill=\"white\"/>\n";

    std::ofstream csv_file;
    csv_file.open("_plot.csv");

    double x_r = -1.65;

    while (std::fabs(func(x_r)) > 0.001)
    {
        x_r -= func(x_r) / deltaFunc(x_r);
        std::cout << "x=" << x_r << "\tf(x)=" << func(x_r) << "\tdf(x)=" << deltaFunc(x_r)  << "\terror(x)=" << std::fabs(func(x_r)) << std::endl;
        svg_file << "<circle cx=\"" << x_r * 100.0 + 50.0 << "\" cy=\"" << func(x_r) * 100.0 + 50.0 << "\" r=\"1\" fill=\"black\" />\n";
        csv_file << x_r << "," << func(x_r) << std::endl;

        if(std::fabs(func(x_r)) > 20.0) break;
    }
    svg_file << "</svg>\n";
    svg_file.close();
    csv_file.close();

    
    return 0;
}