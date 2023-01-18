#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv) {
    std::string filepath = "./prng-service.txt";
    std::string input;
    int max = 5;

    srand((unsigned) time(NULL));

    while(true) {
        std::ifstream inputStream(filepath, std::ios::in);
        input.clear();
        inputStream >> input;
        inputStream.close();
        
        if(input == "run") {
            int randNumb = rand() / (RAND_MAX / max);
            std::ofstream outputStream(filepath, std::ios::out | std::ios::trunc);
            outputStream << randNumb;
            outputStream.close();
            usleep(20000);
        }
    }
}