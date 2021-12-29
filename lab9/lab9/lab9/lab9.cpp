#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::string inputFilePath, outputFilePath, text, s;
    std::cin >> inputFilePath;
    std::ifstream fin(inputFilePath);
    while (std::getline(fin, s)) {
        text += s;
    }
    std::cout << text;
    
}


