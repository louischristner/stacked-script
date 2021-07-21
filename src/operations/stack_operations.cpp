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

void over(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    engine.stack.add(value1);
    engine.stack.add(value2);
    engine.stack.add(value1);
}

void drop(IEngine &engine)
{
    engine.stack.pop();
}

void nip(IEngine &engine)
{
    Literal value = engine.stack.pop();

    engine.stack.pop();
    engine.stack.add(value);
}

void print(IEngine &engine)
{
    Literal value = engine.stack.pop();

    std::cout << value.getValue();
}