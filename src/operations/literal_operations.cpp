#include "operations.hpp"

void add(Engine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != Literal::INTEGER || value1.getValue() != value2.getValue()) {
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