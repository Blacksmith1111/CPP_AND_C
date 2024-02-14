#include <iostream>
#include <vector>
#include <list>
#include <string>

int main() {
    std::list<std::string> fileContent;
    std::string input("f");
    while (input != "") {
		std::getline(std::cin, input);
        fileContent.push_back(input);
    }

    int currentLine = 0; // Номер текущей строки
    std::string buffer; // Буфер обмена

    std::string command("f");
    while (command != "") {
		getline(std::cin, command);
        if (command == "Down") {
            if (currentLine + 1 < static_cast<int>(fileContent.size())) {
                currentLine++;
            }
        } else if (command == "Up") {
            if (currentLine - 1 >= 0) {
                currentLine--;
            }
        } else if (command == "Ctrl+X") {
            if (!fileContent.empty()) {
                buffer = std::move(*std::next(fileContent.begin(), currentLine));
                fileContent.erase(std::next(fileContent.begin(), currentLine));
                if (currentLine == static_cast<int>(fileContent.size()) && currentLine > 0) {
                    currentLine--;
                }
            }
        } else if (command == "Ctrl+V") {
            if (!buffer.empty()) {
                fileContent.insert(std::next(fileContent.begin(), currentLine), buffer);
                currentLine++;
            }
        }
    }

    for (const auto& line : fileContent) {
        std::cout << line << std::endl;
    }

    return 0;
}
