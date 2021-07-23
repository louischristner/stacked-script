#include "../../headers/operations/operations.hpp"

void add(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getType() != value2.getType()) {
        throw InvalidTypeException(value1.toString() + " " + value2.toString());
    }

    engine.stack.add(
        Literal(
            Literal::INTEGER,
            std::to_string(
                std::stoi(value1.getValue()) + std::stoi(value2.getValue())
            )
        )
    );
}

void sub(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getType() != value2.getType()) {
        throw InvalidTypeException(value1.toString() + " " + value2.toString());
    }

    engine.stack.add(
        Literal(
            Literal::INTEGER,
            std::to_string(
                std::stoi(value1.getValue()) - std::stoi(value2.getValue())
            )
        )
    );
}

void mul(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getType() != value2.getType()) {
        throw InvalidTypeException(value1.toString() + " " + value2.toString());
    }

    engine.stack.add(
        Literal(
            Literal::INTEGER,
            std::to_string(
                std::stoi(value1.getValue()) * std::stoi(value2.getValue())
            )
        )
    );
}

void div(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getType() != value2.getType()) {
        throw InvalidTypeException(value1.toString() + " " + value2.toString());
    }

    engine.stack.add(
        Literal(
            Literal::INTEGER,
            std::to_string(
                std::stoi(value1.getValue()) / std::stoi(value2.getValue())
            )
        )
    );
}

void mod(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getType() != value2.getType()) {
        throw InvalidTypeException(value1.toString() + " " + value2.toString());
    }

    engine.stack.add(
        Literal(
            Literal::INTEGER,
            std::to_string(
                std::stoi(value1.getValue()) % std::stoi(value2.getValue())
            )
        )
    );
}

void cmp(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    engine.stack.add(
        Literal(
            Literal::BOOLEAN,
            (value1.getType() == value2.getType() && value1.getValue() == value2.getValue())
                ? "true" : "false"
        )
    );
}

void gt(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getType() != value2.getType()) {
        throw InvalidTypeException(value1.toString() + " " + value2.toString());
    }

    engine.stack.add(
        Literal(
            Literal::BOOLEAN,
            std::stoi(value1.getValue()) > std::stoi(value2.getValue())
                ? "true" : "false"
        )
    );
}

void lt(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getType() != value2.getType()) {
        throw InvalidTypeException(value1.toString() + " " + value2.toString());
    }

    engine.stack.add(
        Literal(
            Literal::BOOLEAN,
            std::stoi(value1.getValue()) < std::stoi(value2.getValue())
                ? "true" : "false"
        )
    );
}

void ge(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getType() != value2.getType()) {
        throw InvalidTypeException(value1.toString() + " " + value2.toString());
    }

    engine.stack.add(
        Literal(
            Literal::BOOLEAN,
            std::stoi(value1.getValue()) >= std::stoi(value2.getValue())
                ? "true" : "false"
        )
    );
}

void le(IEngine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getType() != value2.getType()) {
        throw InvalidTypeException(value1.toString() + " " + value2.toString());
    }

    engine.stack.add(
        Literal(
            Literal::BOOLEAN,
            std::stoi(value1.getValue()) <= std::stoi(value2.getValue())
                ? "true" : "false"
        )
    );
}