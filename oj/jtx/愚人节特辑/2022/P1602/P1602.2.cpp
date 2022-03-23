#include <iostream>
#define ENIUQ(TEMPLATE) std::cout << TEMPLATE << "(" << #TEMPLATE << ");}"; return 0;

int main(){ENIUQ("#include <iostream>\n#define ENIUQ(TEMPLATE) std::cout << TEMPLATE << \"(\" << #TEMPLATE << \");}\"; return0;\n\nint main(){ENIUQ;");}