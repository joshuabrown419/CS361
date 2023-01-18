#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv) {
    std::string filepath = "./prng-service.txt";
    std::string input;
    int max = 1040;

    srand((unsigned) time(NULL));

    while(true) {
        std::ifstream inputStream(filepath, std::ios::in);
        input.clear();
        inputStream >> input;
        inputStream.close();
        
        if(input == "run") {
            int randNumb = rand() / (RAND_MAX / max) + 1;
            std::ofstream outputStream(filepath, std::ios::out | std::ios::trunc);
            std::cout << randNumb << std::endl;
            outputStream << randNumb;
            outputStream.close();
            usleep(20000);
        }

        usleep(1000);
    }
}