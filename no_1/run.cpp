#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <numbers>

constexpr double pi = 3.141592;

int main(void){
    const double a = 17.0 / 30.0;
    //const double a = 1.0;

    std::ofstream out_file;
    std::string file_name = "";
    out_file.open(file_name);

    std::ofstream file("Ex-1a.xls");
    file.is_open();

    file << "<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"500\" height=\"500\">\n";
    file << "<rect width=\"100%\" height=\"100%\" fill=\"white\"/>\n";

    for(double t = 0; t < 5; t += 0.1){
        const auto result = std::exp(a * t * -1.0) * std::sin(pi * t);
        out_file << t << "\t" << result << std::endl;
        file << "<circle cx=\"" << t * 100.0 + 50.0 << "\" cy=\"" << result * 100.0 + 50.0 << "\" r=\"1\" fill=\"black\" />\n";

    }
    out_file.close();
    file << "</svg>\n";
    file.close();
    return 0;
}