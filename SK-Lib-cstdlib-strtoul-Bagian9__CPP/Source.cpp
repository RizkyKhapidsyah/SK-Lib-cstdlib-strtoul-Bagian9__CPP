#include <cstdlib>
#include <iostream>
#include <string>
#include <errno.h>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main() {
    const char* p = "10 200000000000000000000000000000 30 -40 - 42";
    char* end = nullptr;
    std::cout << "Parsing '" << p << "':\n";

    for (unsigned long i = std::strtoul(p, &end, 10);
        p != end;
        i = std::strtoul(p, &end, 10))
    {
        std::cout << "'" << std::string(p, end - p) << "' -> ";
        p = end;
        
        if (errno == ERANGE) {
            errno = 0;
            std::cout << "range error, got ";
        }

        std::cout << i << '\n';
    }

    std::cout << "After the loop p points to '" << p << "'\n";

    _getch();
    return 0;
}