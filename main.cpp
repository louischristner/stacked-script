#include <iostream>

#include "headers/Engine.hpp"
#include "src/parser/parser.hpp"

int main(void)
{
    Engine engine;

    parser("1 1 +", engine);
    std::cout << "Remaining stack element:" << std::endl;
    while (engine.stack.size() > 0) {
        std::cout << engine.stack.pop().toString() << std::endl;
    }

    return 0;
}
