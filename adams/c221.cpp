#include <iostream>
#include <string>

int main() {
    std::string corpus = "abcdefghijklmnopqrstuvwxyz0123456789";

    for (int i = 0; i < corpus.length(); i++) {
        std::cout << "Character: " << corpus[i] << ", ascii value: " 
                    << static_cast<int>(corpus[i]) << std::endl;
    }

    return 0;
}
