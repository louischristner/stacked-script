#include <criterion/criterion.h>

#include "../src/headers/Engine.hpp"

Test(literal_tests, ensure_that_addition_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "1"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));

    engine.operations.get("+")(engine);

    cr_assert(engine.stack.pop().getValue() == "2");
}

Test(literal_tests, ensure_that_substraction_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "1"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));

    engine.operations.get("-")(engine);

    cr_assert(engine.stack.pop().getValue() == "0");
}

Test(literal_tests, ensure_that_multiplication_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "2"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));

    engine.operations.get("*")(engine);

    cr_assert(engine.stack.pop().getValue() == "2");
}

Test(literal_tests, ensure_that_division_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "1"));
    engine.stack.add(Literal(Literal::INTEGER, "1"));

    engine.operations.get("/")(engine);

    cr_assert(engine.stack.pop().getValue() == "1");
}

Test(literal_tests, ensure_that_modulo_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));
    engine.stack.add(Literal(Literal::INTEGER, "2"));

    engine.operations.get("%")(engine);

    cr_assert(engine.stack.pop().getValue() == "0");
}

Test(literal_tests, ensure_that_true_integer_comparison_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));
    engine.stack.add(Literal(Literal::INTEGER, "4"));

    engine.operations.get("=")(engine);

    cr_assert(engine.stack.pop().getValue() == "true");
}

Test(literal_tests, ensure_that_true_string_comparison_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::STRING, "value"));
    engine.stack.add(Literal(Literal::STRING, "value"));

    engine.operations.get("=")(engine);

    cr_assert(engine.stack.pop().getValue() == "true");
}

Test(literal_tests, ensure_that_true_boolean_comparison_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::BOOLEAN, "true"));
    engine.stack.add(Literal(Literal::BOOLEAN, "true"));

    engine.operations.get("=")(engine);

    cr_assert(engine.stack.pop().getValue() == "true");
}

Test(literal_tests, ensure_that_false_integer_comparison_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));
    engine.stack.add(Literal(Literal::INTEGER, "2"));

    engine.operations.get("=")(engine);

    cr_assert(engine.stack.pop().getValue() == "false");
}

Test(literal_tests, ensure_that_false_string_comparison_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::STRING, "value"));
    engine.stack.add(Literal(Literal::STRING, "eulav"));

    engine.operations.get("=")(engine);

    cr_assert(engine.stack.pop().getValue() == "false");
}

Test(literal_tests, ensure_that_false_boolean_comparison_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::BOOLEAN, "true"));
    engine.stack.add(Literal(Literal::BOOLEAN, "false"));

    engine.operations.get("=")(engine);

    cr_assert(engine.stack.pop().getValue() == "false");
}

Test(literal_tests, ensure_that_comparison_between_different_types_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::STRING, "true"));
    engine.stack.add(Literal(Literal::BOOLEAN, "false"));

    engine.operations.get("=")(engine);

    cr_assert(engine.stack.pop().getValue() == "false");
}

Test(literal_tests, ensure_that_true_greater_than_comparison_between_integer_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "3"));
    engine.stack.add(Literal(Literal::INTEGER, "2"));

    engine.operations.get(">")(engine);

    cr_assert(engine.stack.pop().getValue() == "true");
}

Test(literal_tests, ensure_that_false_greater_than_comparison_between_integer_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "2"));
    engine.stack.add(Literal(Literal::INTEGER, "3"));

    engine.operations.get(">")(engine);

    cr_assert(engine.stack.pop().getValue() == "false");
}
