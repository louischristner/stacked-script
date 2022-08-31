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

    cr_assert(engine.stack.pop().getValue() == "hello world");
}

Test(parser_tests, ensure_that_true_if_condition_parsing_occurs_without_technical_errors)
{
    Engine engine;

    parser("true [ 2 1 ] [ 3 4 ] if +", engine);

    cr_assert(engine.stack.pop().getValue() == "3");
    cr_assert(engine.stack.size() == 0);
}

Test(parser_tests, ensure_that_false_if_condition_parsing_occurs_without_technical_errors)
{
    Engine engine;

    parser("false [ 2 1 ] [ 3 4 ] if +", engine);

    cr_assert(engine.stack.pop().getValue() == "7");
    cr_assert(engine.stack.size() == 0);
}

Test(parser_tests, ensure_that_true_when_condition_parsing_occurs_without_technical_errors)
{
    Engine engine;

    parser("true [ 2 1 + ] when", engine);

    cr_assert(engine.stack.pop().getValue() == "3");
    cr_assert(engine.stack.size() == 0);
}

Test(parser_tests, ensure_that_false_when_condition_parsing_occurs_without_technical_errors)
{
    Engine engine;

    parser("false [ 2 1 + ] when", engine);

    cr_assert(engine.stack.size() == 0);
}

Test(parser_tests, ensure_that_times_loop_parsing_occurs_without_technical_errors)
{
    Engine engine;

    parser("1 10 [ 1 + ] times", engine);

    cr_assert(engine.stack.pop().getValue() == "11");
    cr_assert(engine.stack.size() == 0);
}

Test(parser_tests, ensure_that_loop_loop_parsing_occurs_without_technical_errors)
{
    Engine engine;

    parser("0 1 [ swap over + dup 100 > ] loop", engine);

    cr_assert(engine.stack.pop().getValue() == "144");
    cr_assert(engine.stack.size() == 1);
}