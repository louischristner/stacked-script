#include <iostream>
#include <criterion/criterion.h>

#include "../src/reader/reader.hpp"

Test(reader_tests, ensure_that_reader_occurs_without_technical_errors)
{
    cr_assert(reader("../examples/example0.txt") == "1 1 +");
}

Test(reader_tests, ensure_that_invalid_file_reader_throw_exception)
{
    cr_assert_throw(reader("../strange.txt"), InvalidReaderException);
}
