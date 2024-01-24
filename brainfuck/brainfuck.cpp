#include "brainfuck.hpp"

int main() {
    std::string file_name;
    std::cout << "Input file name: ";
    std::getline(std::cin, file_name);

    std::ifstream file(file_name);
    if (!file.is_open()) {
        std::cerr << "unable to open: " << file_name << std::endl;
        return 1;
    }
    std::string input_code((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    execute(input_code);
    
    system("pause");
    return 0;
}
