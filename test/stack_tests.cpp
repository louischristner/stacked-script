#include <criterion/criterion.h>

#include "../src/headers/Engine.hpp"

Test(literal_tests, ensure_that_swap_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));
    engine.stack.add(Literal(Literal::INTEGER, "2"));

    engine.operations.get("swap")(engine);

    cr_assert(engine.stack.pop().getValue() == "4");
}

Test(literal_tests, ensure_that_dup_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));

    engine.operations.get("dup")(engine);
    engine.operations.get("*")(engine);

    cr_assert(engine.stack.pop().getValue() == "16");
}
