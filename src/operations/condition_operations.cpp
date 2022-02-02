#include "../../headers/operations/operations.hpp"

void parser(const std::string &command, IEngine &engine);

void if_cond(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();
    Literal cond = engine.stack.pop();

    if (cond.getType() != Literal::BOOLEAN || value1.getType() != Literal::BLOCK || value2.getType() != Literal::BLOCK) {
        throw InvalidTypeException(cond.toString() + " " + value1.toString() + " " + value2.toString());
    }

    if (cond.getValue() == "true") {
        parser(value1.getValue(), engine);
    } else {
        parser(value2.getValue(), engine);
    }
}

void when_cond(IEngine &engine)
{
    Literal value = engine.stack.pop();
    Literal cond = engine.stack.pop();

    if (cond.getType() != Literal::BOOLEAN || value.getType() != Literal::BLOCK) {
        throw InvalidTypeException(cond.toString() + " " + value.toString());
    }

    if (cond.getValue() == "true") {
        parser(value.getValue(), engine);
    }
}