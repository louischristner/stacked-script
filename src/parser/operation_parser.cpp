#include "parser.hpp"

bool operation_parser(const std::string &command, size_t &index, IEngine &engine)
{
    size_t next_space = command.find(' ', index);

    for (const std::string &operation : engine.operations.keys()) {
        if (std::strcmp(command.substr(index, next_space - index).c_str(), operation.c_str()) == 0) {
            engine.operations.get(operation)(engine);
            index += operation.size();
            return true;
        }
    }

    return false;
}
