#include <iostream>
#include <string>
#include <fstream>
#include <unistd.h>
#include <filesystem>

int main(int argc, char** argv) {
    std::string input;
    const std::string prompt = "Type 'generate' to generate an image or 'exit' to exit";
    const std::string prng_path = "./prng-service.txt";
    const std::string image_service_path = "./image-service.txt";

    std::string prn;
    std::string image_path;

    std::ofstream *ofs;
    std::ifstream *ifs;

    while(input != "exit") {
        std::cout << prompt << std::endl;
        std::cin >> input;

        if(input != "generate") continue;

        ofs = new std::ofstream(prng_path, std::ios::out | std::ios::trunc);
        *ofs << "run";
        ofs->close();
        delete ofs;

        usleep(4000000);

        prn.clear();
        ifs = new std::ifstream(prng_path, std::ios::in);
        *ifs >> prn;
        ifs->close();
        delete ifs;

        ofs = new std::ofstream(image_service_path, std::ios::out | std::ios::trunc);
        *ofs << prn;
        ofs->close();
        delete ofs;

        usleep(3000000);

        image_path.clear();
        ifs = new std::ifstream(image_service_path, std::ios::in);
        *ifs >> image_path;
        ifs->close();
        delete ifs;

        std::cout << "The path to the image is: " << image_path << std::endl << std::endl;
    }
}