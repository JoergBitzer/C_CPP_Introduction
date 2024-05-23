#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <random>

int main() 
{
    int len = 10;
    std::string filename = "noisedata.bin";
    std::ofstream fileout(filename, std::ios::binary);
    if (fileout.is_open()) 
    {
        for (int i = 0; i < len; i++) 
        {
            /*
            //Generate a random number between 0 and 1
            // very old school
            double r = (double)rand() / RAND_MAX;
            // scale between -2 and 2
            double max_val = 2;
            double min_val = -2;
            double scaled = r * (max_val - min_val) + min_val;
            std::cout << scaled << std::endl;
            */
            // new school
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_real_distribution<> dis(-2, 2);
            double r2 = dis(gen);
            fileout.write(reinterpret_cast<char*>(&r2), sizeof(r2));
            std::cout << r2 << std::endl;
        }
        fileout.close();
    }
/*    
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
*/    
    return 0;
}