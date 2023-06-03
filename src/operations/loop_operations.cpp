#include "../../headers/operations/operations.hpp"

void parser(const std::string &command, IEngine &engine);

void times_loop(IEngine &engine)
{
    Literal block = engine.stack.pop();
    Literal value = engine.stack.pop();

    if (block.getType() != Literal::BLOCK || value.getType() != Literal::INTEGER) {
        throw InvalidTypeException(value.toString() + " " + block.toString());
    }

    for (size_t index = 1; index <= std::stoi(value.getValue()); index++) {
        parser(block.getValue(), engine);
    }
}

void loop_loop(IEngine &engine)
{
    Literal block = engine.stack.pop();
    Literal cond = Literal(Literal::BOOLEAN, "false");

    if (block.getType() != Literal::BLOCK) {
        throw InvalidTypeException(block.toString());
    }

    while (true) {
        parser(block.getValue(), engine);
        cond = engine.stack.pop();

        if (cond.getType() != Literal::BOOLEAN) {
            throw InvalidTypeException(cond.toString() + " " + block.toString());
        }

        if (cond.getValue() == "false") {
            break;
        }
    }
}