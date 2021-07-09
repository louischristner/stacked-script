#include <iostream>

#include "../src/headers/Engine.hpp"

#include "test.hpp"

void assert_that(bool condition)
{
    if (!condition)
        throw InvalidTestException();
}

void ensure_that_addition_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "1"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));

    engine.operations.get("+")(engine);

    assert_that(engine.stack.pop().getValue() == "2");
}

void ensure_that_substraction_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "1"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));

    engine.operations.get("-")(engine);

    assert_that(engine.stack.pop().getValue() == "0");
}

void ensure_that_multiplication_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "2"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));

    engine.operations.get("*")(engine);

    assert_that(engine.stack.pop().getValue() == "2");
}

void ensure_that_division_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "1"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));

    engine.operations.get("/")(engine);

    assert_that(engine.stack.pop().getValue() == "1");
}

void ensure_that_modulo_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));
    engine.stack.add(Literal(Literal::INTEGER, "2"));

    engine.operations.get("%")(engine);

    assert_that(engine.stack.pop().getValue() == "0");
}

void ensure_that_swap_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));
    engine.stack.add(Literal(Literal::INTEGER, "2"));

    engine.operations.get("swap")(engine);

    assert_that(engine.stack.pop().getValue() == "4");
}

void ensure_that_dup_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));

    engine.operations.get("dup")(engine);
    engine.operations.get("*")(engine);

    assert_that(engine.stack.pop().getValue() == "16");
}

void ensure_that_true_integer_comparison_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));
    engine.stack.add(Literal(Literal::INTEGER, "4"));

    engine.operations.get("=")(engine);

    assert_that(engine.stack.pop().getValue() == "true");
}

void ensure_that_true_string_comparison_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::STRING, "value"));
    engine.stack.add(Literal(Literal::STRING, "value"));

    engine.operations.get("=")(engine);

    assert_that(engine.stack.pop().getValue() == "true");
}

void ensure_that_true_boolean_comparison_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::BOOLEAN, "true"));
    engine.stack.add(Literal(Literal::BOOLEAN, "true"));

    engine.operations.get("=")(engine);

    assert_that(engine.stack.pop().getValue() == "true");
}

void ensure_that_false_integer_comparison_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));
    engine.stack.add(Literal(Literal::INTEGER, "2"));

    engine.operations.get("=")(engine);

    assert_that(engine.stack.pop().getValue() == "false");
}

void ensure_that_false_string_comparison_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::STRING, "value"));
    engine.stack.add(Literal(Literal::STRING, "eulav"));

    engine.operations.get("=")(engine);

    assert_that(engine.stack.pop().getValue() == "false");
}

void ensure_that_false_boolean_comparison_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::BOOLEAN, "true"));
    engine.stack.add(Literal(Literal::BOOLEAN, "false"));

    engine.operations.get("=")(engine);

    assert_that(engine.stack.pop().getValue() == "false");
}

void ensure_that_comparison_between_different_types_occurs_without_technical_errors()
{
    Engine engine;

    engine.stack.add(Literal(Literal::STRING, "true"));
    engine.stack.add(Literal(Literal::BOOLEAN, "false"));

    engine.operations.get("=")(engine);

    assert_that(engine.stack.pop().getValue() == "false");
}

int main(void)
{
    ensure_that_addition_occurs_without_technical_errors();
    ensure_that_substraction_occurs_without_technical_errors();
    ensure_that_multiplication_occurs_without_technical_errors();
    ensure_that_division_occurs_without_technical_errors();
    ensure_that_modulo_occurs_without_technical_errors();
    ensure_that_swap_occurs_without_technical_errors();
    ensure_that_dup_occurs_without_technical_errors();
    ensure_that_true_integer_comparison_occurs_without_technical_errors();
    ensure_that_true_string_comparison_occurs_without_technical_errors();
    ensure_that_true_boolean_comparison_occurs_without_technical_errors();
    ensure_that_false_integer_comparison_occurs_without_technical_errors();
    ensure_that_false_string_comparison_occurs_without_technical_errors();
    ensure_that_false_boolean_comparison_occurs_without_technical_errors();
    ensure_that_comparison_between_different_types_occurs_without_technical_errors();

    std::cout << "Success !" << std::endl;

    return 0;
}
