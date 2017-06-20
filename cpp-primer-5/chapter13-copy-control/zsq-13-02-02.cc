#include "has_ptr.h"

int main() {
        HasPtr p1("alice");
        {
                HasPtr p2 = p1;
                std::cout << p2.get_string() << std::endl;
        }
        std::cout << p1.get_string() << std::endl;
        return 0;
}
