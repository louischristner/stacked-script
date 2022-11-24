#include "../../headers/Engine.hpp"

#define FUNC_START_ID ':'
#define FUNC_END_ID ';'

void remove_user_defined_function(std::string &command, const size_t &startIndex, const size_t &endIndex)
{
    for (size_t index = startIndex; index < endIndex; index++)
        command[index] = ' ';
}

size_t get_function_start(const std::string &command, size_t index)
{
    for (size_t startIndex = index; startIndex < command.size(); startIndex++)
        if (command[startIndex] != ' ')
            return startIndex;

    return command.size();
}

std::string get_function_name(const std::string &command, const size_t &startIndex)
{
    size_t endIndex = command.find(' ', startIndex);

    return command.substr(startIndex, endIndex - startIndex);
}

bool user_defined_function_parser(std::string &command, size_t &index, IEngine &engine)
{
    std::string functionName;
    std::string functionBody;
    size_t funcStartIndex = index + 1;
    size_t funcEndIndex = funcStartIndex;

    for (; funcEndIndex < command.size(); funcEndIndex++) {
        if (command[funcEndIndex] == FUNC_END_ID) {

            funcStartIndex = get_function_start(command, funcStartIndex);
            functionName = get_function_name(command, funcStartIndex);
            funcStartIndex = funcStartIndex + functionName.size();

            engine.userDefinedFunctions.add(
                functionName,
                command.substr(funcStartIndex, funcEndIndex - funcStartIndex)
            );

            remove_user_defined_function(command, index, funcEndIndex);
            index = funcEndIndex;

            return true;
        }
    }

    return false;
}

void user_defined_functions_parser(std::string &command, IEngine &engine)
{
    for (size_t index = 0; index < command.size(); index++) {
        if (command[index] == ' ') continue;
        if (command[index] == FUNC_START_ID) {
            if (user_defined_function_parser(command, index, engine))
                continue;
        }
    }
}