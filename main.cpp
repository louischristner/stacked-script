#include <iostream>

#include "headers/Engine.hpp"

int main(void)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "1"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));
    engine.operations.get("+")(engine);

    std::cout << engine.stack.pop().getValue() << std::endl;

    return 0;
}