#include "operations.hpp"

void swap(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    engine.stack.add(value2);
    engine.stack.add(value1);
}

void dup(IEngine &engine)
{
    Literal value = engine.stack.pop();

    engine.stack.add(value);
    engine.stack.add(value);
}