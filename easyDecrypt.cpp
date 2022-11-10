#include <iostream>
#include <fstream>

void decode(const std::string& path);

int main(int argc, char *argv[]) {
    if(argc > 1){
        decode(argv[1]);
        return 0;
    }

    std::cout << "\nThanks for using!\n"
              << "Of course you can drag the .txt file into here.\n"
              << "But if you're windows, it's more convenient\n"
              << "*to just drag the txt onto the exe icon, rather than open it!*\n"
              << std::endl;
    std::string path;
    while(getline(std::cin, path)){
        system("clear");
        if(path.find_last_of(' ') == path.size() - 1) path.pop_back();
        decode(path);
        std::cout << "You can keep decryption.\n" << std::endl;
    }

    return 0;
}

void decode(const std::string& path){
    auto newpath = path;
    auto pos = path.find(".txt");
    newpath.insert(pos, "Decode");

    std::ifstream src(path);
    std::ofstream dst(newpath);

    int c1, c2;
    src >> c1 >> c2;
    char key = c1 ^ c2;
    dst << static_cast<char>(c2) << static_cast<char>(c1);

    int c;
    while (src >> c){
        char tmp = static_cast<char>(c) ^ key;
        dst << tmp;
    }

    src.close();
    dst.close();
}
