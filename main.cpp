#include <iostream>

#include "headers/Engine.hpp"
#include "src/parser/parser.hpp"

#include "src/reader/reader.hpp"

int main(int ac, char **av)
{
    Engine engine;
    std::string file_content;

    if (ac < 2) {
        std::cout << "Need file as argument" << "\n";
        return 0;
    }

    file_content = reader(av[1]);
    user_defined_functions_parser(file_content, engine);
    parser(file_content, engine);
    while (engine.stack.size() > 0)
        std::cout << engine.stack.pop().toString() << "\n";

    return 0;
}

// int main(void)
// {
//     Engine engine;

//     parser("1 1 +", engine);
//     std::cout << "Remaining stack element:" << std::endl;
//     while (engine.stack.size() > 0) {
//         std::cout << engine.stack.pop().toString() << std::endl;
//     }

//     return 0;
// }
