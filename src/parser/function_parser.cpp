#include "parser.hpp"

bool function_parser(const std::string &command, size_t &index, IEngine &engine)
{
    size_t next_space = command.find(' ', index);

    for (const std::string &operation : engine.userDefinedFunctions.keys()) {
        if (std::strcmp(command.substr(index, next_space - index).c_str(), operation.c_str()) == 0) {
            parser(engine.userDefinedFunctions.get(operation), engine);
            index += operation.size();
            return true;
        }
    }

    return false;
}