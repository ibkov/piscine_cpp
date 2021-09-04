#include <iostream>
#include <string>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;

    std::cout << "string: " << str << std::endl;
    std::cout << "Address in memory string: " << &str << std::endl;
    std::cout << "stringPTR: " << stringPTR << std::endl;
    std::cout << "stringREF: " << &stringREF << std::endl;
    std::cout << "Show stringPTR: " << *stringPTR << std::endl;
    std::cout << "Show stringREF: " << stringREF << std::endl;

}