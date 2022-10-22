#include <iostream>
#include <fstream>
#include <string>

void dealWith(const std::string& path);
void addTags(std::string& line, const std::string& tag);

int main(int argc, char* argv[]) {
    if(argc > 1){
        dealWith(argv[1]);
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
        dealWith(path);
        std::cout << "You can keep doing.\n" << std::endl;
    }

    return 0;
}

void dealWith(const std::string& path){
    auto pos = path.find(".txt");
    auto newpath = path;
    newpath.insert(pos, "_added");

    std::ifstream src(path);
    std::ofstream dst(newpath);

    std::string s;
    while(getline(src, s)){
        addTags(s, "> ");
        dst << s << std::endl;
    }

    src.close();
    dst.close();
}

void addTags(std::string& line, const std::string& tag){
    line = tag + line;
}
