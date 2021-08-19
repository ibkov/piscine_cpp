#include <iostream>
#include <ctype.h>
#include <string.h>

void upperstr(char *s) {
    for (size_t i = 0; i < strlen(s); i++) {
        s[i] = toupper(s[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; i++) {
            upperstr(argv[i]);
            std::cout << argv[i];
            if (i == argc - 1)
                std::cout << std::endl;
        }
    }
    return 0;
}