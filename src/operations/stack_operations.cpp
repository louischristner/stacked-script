#include "../../headers/operations/operations.hpp"

void parser(const std::string &command, IEngine &engine);

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

void spread(IEngine &engine)
{
    Literal value = engine.stack.pop();

    if (value.getType() != Literal::BLOCK)
        throw InvalidTypeException(value.toString());

    parser(value.getValue(), engine);
}

void spread_swap(IEngine &engine)
{
    Literal block = engine.stack.pop();
    Literal previous = engine.stack.pop();

    if (block.getType() != Literal::BLOCK)
        throw InvalidTypeException(block.toString());

    parser(block.getValue(), engine);
    engine.stack.add(previous);
}