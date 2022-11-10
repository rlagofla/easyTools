#include <iostream>
#include <fstream>

void encrypt(const std::string& path);

int main(int argc, char *argv[]) {
    if(argc > 1){
        encrypt(argv[1]);
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
        encrypt(path);
        std::cout << "You can keep doing encryption.\n" << std::endl;
    }

    return 0;
}

void encrypt(const std::string& path){
    auto pos = path.find(".txt");
    auto newpath = path;
    newpath.insert(pos, "Encrypted");

    std::ifstream src(path);
    std::ofstream dst(newpath);

    char c1, c2;
    src >> c1 >> c2;
    char key = c1 ^ c2;
    dst << static_cast<int>(c2) << ' ' << static_cast<int>(c1);

    std::string s;
    while(getline(src, s)){
        for(auto c : s){
            c ^= key;
            dst << ' ' << static_cast<int>(c);
        }
        dst << ' ' << static_cast<int>('\n' ^ key);
    }

    src.close();
    dst.close();
}
