#include <iostream>
#include <string>

void toUpperCase(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] -= 32;
        }
    }
}

void toLowerCase(char* str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
        ++i;
    }
}

int main() {
    std::string str;
    std::getline(std::cin >> std::ws, str);

    toLowerCase(&(str[0]));
    std::cout << str << std::endl;

    toUpperCase(&(str[0]));
    std::cout << str << std::endl;

    return 0;   
}
