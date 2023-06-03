#include <iostream>
#include <criterion/criterion.h>

#include "../headers/Engine.hpp"

Test(stack_tests, ensure_that_swap_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));
    engine.stack.add(Literal(Literal::INTEGER, "2"));

    engine.operations.get("swap")(engine);

    cr_assert(engine.stack.pop().getValue() == "4");
    cr_assert(engine.stack.pop().getValue() == "2");
}

Test(stack_tests, ensure_that_dup_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "4"));

    engine.operations.get("dup")(engine);

    cr_assert(engine.stack.size() == 2);
    cr_assert(engine.stack.pop().getValue() == "4");
    cr_assert(engine.stack.pop().getValue() == "4");
}

Test(stack_tests, ensure_that_over_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::STRING, "hello"));
    engine.stack.add(Literal(Literal::STRING, "world"));

    engine.operations.get("over")(engine);

    cr_assert(engine.stack.size() == 3);
    cr_assert(engine.stack.pop().getValue() == "hello");
    cr_assert(engine.stack.pop().getValue() == "world");
    cr_assert(engine.stack.pop().getValue() == "hello");
}

Test(stack_tests, ensure_that_drop_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::STRING, "the mic"));

    engine.operations.get("drop")(engine);

    cr_assert(engine.stack.size() == 0);
}

Test(stack_tests, ensure_that_nip_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::STRING, "the"));
    engine.stack.add(Literal(Literal::STRING, "mic"));

    engine.operations.get("nip")(engine);

    cr_assert(engine.stack.size() == 1);
    cr_assert(engine.stack.pop().getValue() == "mic");
}

Test(stack_tests, ensure_that_print_occurs_without_technical_errors)
{
    Engine engine;

    std::streambuf *oldStreamBuf = std::cout.rdbuf();
    std::ostringstream stringStream;

    std::cout.rdbuf(stringStream.rdbuf());

    engine.stack.add(Literal(Literal::STRING, "Hello world"));

    engine.operations.get("print")(engine);

    std::cout.rdbuf(oldStreamBuf);

    cr_assert(stringStream.str() == "Hello world");
    cr_assert(engine.stack.size() == 0);
}

Test(stack_tests, ensure_that_spread_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::BLOCK, "1 2 3 4"));

    cr_assert(engine.stack.size() == 1);

    engine.operations.get("spread")(engine);

    cr_assert(engine.stack.size() == 4);
    cr_assert(engine.stack.pop().getValue() == "4");
    cr_assert(engine.stack.pop().getValue() == "3");
    cr_assert(engine.stack.pop().getValue() == "2");
    cr_assert(engine.stack.pop().getValue() == "1");
}

Test(stack_tests, ensure_that_spread_over_occurs_without_technical_errors)
{
    Engine engine;

    engine.stack.add(Literal(Literal::INTEGER, "5"));
    engine.stack.add(Literal(Literal::BLOCK, "1 2 3 4"));

    cr_assert(engine.stack.size() == 2);

    engine.operations.get("sspread")(engine);

    cr_assert(engine.stack.size() == 5);
    cr_assert(engine.stack.pop().getValue() == "5");
    cr_assert(engine.stack.pop().getValue() == "4");
    cr_assert(engine.stack.pop().getValue() == "3");
    cr_assert(engine.stack.pop().getValue() == "2");
    cr_assert(engine.stack.pop().getValue() == "1");
}
