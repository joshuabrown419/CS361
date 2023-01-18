#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <filesystem>

int main(int argc, char** argv) {
    std::string filepath = "./image-service.txt";
    std::string imagepath = std::filesystem::absolute("images/");
    std::string imageext = ".png";
    std::string input;

    while(true) {
        std::ifstream inputStream(filepath, std::ios::in);
        input.clear();
        inputStream >> input;
        inputStream.close();
        
        if(input != "") {
            usleep(2000000);
            std::ofstream outputStream(filepath, std::ios::out | std::ios::trunc);
            outputStream << imagepath << input << imageext;
            outputStream.close();

            std::cout << imagepath << input << imageext << std::endl;
            usleep(2000000);

            std::ofstream clearStream(filepath, std::ios::out | std::ios::trunc);
            clearStream << "";
            clearStream.close();
        }
        
        usleep(1000);
    }
}