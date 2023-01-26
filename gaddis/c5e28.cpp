#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string name = "";
    std::cout << "Enter your name: ";
    getline(std::cin, name);

    std::string description = "";
    std::cout << "Describe yourself: ";
    getline(std::cin, description);

    std::string title = "";
    std::cout << "Enter a title for your webpage: ";
    getline(std::cin, title);

    std::string filename = "data/" + title + ".html";

    std::ofstream webpage;
    webpage.open(filename);

    if (webpage) {
        webpage << "<html>\n";
        webpage << "<head>\n";
        webpage << "\t<title>" << title << "</title>\n";
        webpage << "<head>\n";
        webpage << "<body>\n";
        webpage << "\t<center>\n";
        webpage << "\t<h1>" << name << "</h1>\n";
        webpage << "\t</center>\n";
        webpage << "\t<hr>\n";
        webpage << "\t" << description << "\n";
        webpage << "\t</hr>\n";
        webpage << "</body>\n";
        webpage << "</html>";

        webpage.close();

        std::cout << "File saved." << std::endl;
    } else {
        std::cout << "Error creating the file." << std::endl;
    }

    return 0;
}