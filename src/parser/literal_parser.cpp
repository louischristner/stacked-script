#include "parser.hpp"

bool literal_string_parser(const std::string &command, size_t &index, IEngine &engine)
{
    size_t next_space = command.find('"', index + 1);
    std::string sub_command = command.substr(index, next_space - index);

    if (sub_command[0] == '"') {
        engine.stack.add(Literal(Literal::STRING,
            sub_command.substr(1, sub_command.size() - 1)));
        index += sub_command.size();
        return true;
    }

    return false;
}

bool literal_boolean_parser(const std::string &command, size_t &index, IEngine &engine)
{
    size_t next_space = command.find(' ', index);
    std::string sub_command = command.substr(index, next_space - index);
    std::regex boolean_regex("^(true)|(false)$");

    if (std::regex_search(sub_command, boolean_regex)) {
        engine.stack.add(Literal(Literal::BOOLEAN, sub_command));
        index += sub_command.size();
        return true;
    }

    return false;
}

bool literal_integer_parser(const std::string &command, size_t &index, IEngine &engine)
{
    size_t next_space = command.find(' ', index);
    std::string sub_command = command.substr(index, next_space - index);
    std::regex integer_regex("^-?[0-9]+$");

    if (std::regex_search(sub_command, integer_regex)) {
        engine.stack.add(Literal(Literal::INTEGER, sub_command));
        index += sub_command.size();
        return true;
    }

    return false;
}

bool literal_block_parser(const std::string &command, size_t &index, IEngine &engine)
{
    size_t i = index + 1;
    size_t block_count = 1;

    if (command[index] == '[') {
        for  (; command[i]; i++) {
            block_count += (command[i] == '[') ? 1 : 0;
            block_count -= (command[i] == ']') ? 1 : 0;
            if (block_count == 0)
                break;
        }

        if (block_count != 0)
            return false;

        engine.stack.add(Literal(Literal::BLOCK,
            command.substr(index + 1, i - (index + 1))));
        index = i;
        return true;
    }

    return false;
}

bool literal_parser(const std::string &command, size_t &index, IEngine &engine)
{
    std::vector<bool (*)(
        const std::string &command,
        size_t &index,
        IEngine &engine
    )> parsingFunctions = {
        literal_block_parser,
        literal_boolean_parser,
        literal_integer_parser,
        literal_string_parser
    };

    for (size_t parserIndex = 0; parserIndex < parsingFunctions.size(); parserIndex++) {
        if (parsingFunctions[parserIndex](command, index, engine)) {
            return true;
        }
    }

    return false;
}
