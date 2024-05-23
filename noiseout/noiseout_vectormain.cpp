#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <random>
#include <vector>

int main() 
{
    int len = 10;
    std::vector<double> data;
    data.resize(len);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-2, 2);

    for (int cc = 0 ; cc < data.size(); cc++)
    {   
        double r2 = dis(gen);
        data.at(cc) = r2;
    }

    std::string filename = "noisedata3.bin";
    std::ofstream fileout(filename, std::ios::binary);
    if (fileout.is_open()) 
    {
        /*
        for (auto val : data)
        {
            fileout.write(reinterpret_cast<char*>(&val), sizeof(val));
            std::cout << val << std::endl;
        }
        */
        fileout.write(reinterpret_cast<char*>(&data[0]), sizeof(double)*data.size());
        fileout.close();
    }
    
    return 0;
}