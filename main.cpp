#include <iostream>

#include "type_list.h"

int main() {

    using types = make_type_list<int, char, bool, void>::result;

    std::cout << "length of <char, bool, void>: " << length_of<types>::value << std::endl;
    std::cout << "index of char: " << index_of<types, int>::value << std::endl;
    std::cout << "index of bool: " << index_of<types, char>::value << std::endl;
    std::cout << "index of void: " << index_of<types, bool>::value << std::endl;
    std::cout << "index of int: " << index_of<types, long>::value << std::endl;

    std::cout << "list contains bool: " << contains<types, bool>::value << std::endl;
    std::cout << "list contains int: " << contains<types, long>::value << std::endl;

    return 0;
}
