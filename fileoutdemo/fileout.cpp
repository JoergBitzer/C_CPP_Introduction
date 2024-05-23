#include <fstream>
#include <iostream>

int main() 
{
    // write a text file
    std::string filename = "fileout.txt";
    std::ofstream fileout(filename);
    if (fileout.is_open()) 
    {
        fileout << "Hello, file!" << std::endl;
        fileout.close();
    } 
    else 
    {
        std::cerr << "Error opening file" << std::endl;
    }
    // write a binary file

    std::ofstream fileoutbin("fileout.bin", std::ios::binary);
    if (fileoutbin.is_open()) 
    {
        int x = 42;
        fileoutbin.write(reinterpret_cast<char*>(&x), sizeof(x));
        fileoutbin.write((char*)(&x), sizeof(x));

        fileoutbin.close();
    } 
    else 
    {
        std::cerr << "Error opening file" << std::endl;
    }
    return 0;
}