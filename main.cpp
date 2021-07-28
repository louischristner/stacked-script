#include <iostream>

#include "headers/Engine.hpp"
#include "src/parser/parser.hpp"

int main(void)
{
    Engine engine;

    parser("1 1 +", engine);
    std::cout << engine.stack.pop().getValue() << std::endl;

    return 0;
}
