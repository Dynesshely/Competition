#include <iostream>
#include <string>

constexpr unsigned int XOR_KEY = 0x185;

unsigned int calc_name(const std::string& name, unsigned int xor_key) {
    unsigned int eax = 0x0;
    unsigned int edx = 0x0;

    for (char ch : name) {
        edx &= 0xffffff00;
        edx += ch;
        edx ^= xor_key;
        eax += edx;
    }
    return eax;
}

void keygen() {
    std::string name;
    std::cin >> name;

    if (name.length() > 19) {
        std::cout << "error" << std::endl;
        return;
    }

    unsigned int name_calc = calc_name(name, XOR_KEY);
    std::cout << name_calc << std::endl;
}

int main() {
    keygen();

    return 0;
}
