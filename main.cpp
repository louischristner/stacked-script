#include <iostream>

#include "src/classes/Literal.cpp"
#include "src/classes/Stack.cpp"
#include "src/classes/Dictionary.cpp"

#include "src/exceptions/InvalidTypeException.cpp"

struct Engine {
    Stack<Literal> stack;
    Stack<std::string> userDefinedFunctions;
    Dictionary<std::string, void (*)(Engine &)> operations;
};

void add(Engine &engine)
{
    Literal value2 = engine.stack.pop();
    Literal value1 = engine.stack.pop();

    if (value1.getType() != value2.getType() || value1.getType() == Literal::BOOLEAN) {
        throw InvalidTypeException("Arguments are invalid: " + value1.toString() + " " + value2.toString());
    }

    switch (value1.getType()) {
        case Literal::INTEGER:
            engine.stack.add(
                Literal(
                    Literal::INTEGER,
                    std::to_string(
                        std::stoi(value1.getValue()) + std::stoi(value2.getValue())
                    )
                )
            );
            break;
        case Literal::STRING:
            engine.stack.add(
                Literal(
                    Literal::INTEGER,
                    value1.getValue() + value2.getValue()
                )
            );
        default:
            break;
    }
}

int main(void)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "1"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));

    engine.operations.add("+", add);

    engine.operations.get("+")(engine);
    std::cout << engine.stack.pop().getValue() << std::endl;

    return 0;
}