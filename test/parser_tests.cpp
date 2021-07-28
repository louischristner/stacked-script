#include <criterion/criterion.h>

#include "../headers/Engine.hpp"
#include "../src/parser/parser.hpp"

Test(parser_tests, ensure_that_integer_parsing_occurs_without_technical_errors)
{
    Engine engine;

    parser("1 1 + 2 * dup over + swap /", engine);

    cr_assert(engine.stack.pop().getValue() == "2");
}

Test(parser_tests, ensure_that_boolean_parsing_occurs_without_technical_errors)
{
    Engine engine;

    parser("true 4 2 = =", engine);

    cr_assert(engine.stack.pop().getValue() == "false");
}

Test(parser_tests, ensure_that_string_parsing_occurs_without_technical_errors)
{
    Engine engine;

    parser("\"hello world\"", engine);

    std::string p = engine.stack.pop().getValue();
    std::cout << p << std::endl;

    cr_assert(p == "hello world");
}
