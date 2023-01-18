#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <unistd.h>

int main(int argc, char** argv) {
    std::string filepath = "./image-service.txt";
    std::string imagepath = "./images/";
    std::string imageext = ".jpg";
    std::string input;

    while(true) {
        std::ifstream inputStream(filepath, std::ios::in);
        input.clear();
        inputStream >> input;
        inputStream.close();
        
        if(input != "") {
            std::cout << "here";
            std::string randImgPath = imagepath + input + imageext;
            std::ofstream outputStream(filepath, std::ios::out | std::ios::trunc);
            outputStream << randImgPath;
            std::cout << randImgPath;
            outputStream.close();
            usleep(20000);

            std::ofstream clearStream(filepath, std::ios::out | std::ios::trunc);
            clearStream << "";
            clearStream.close();
        }
    }
}