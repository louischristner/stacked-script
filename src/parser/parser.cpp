#include "parser.hpp"

void parser(const std::string &command, IEngine &engine)
{
    std::vector<bool (*)(
        const std::string &command,
        size_t &index,
        IEngine &engine
    )> parsingFunctions = {
        function_parser, operation_parser, literal_parser
    };

    for (size_t index = 0; index < command.size(); index++) {
        if (command[index] == ' ') continue;
        for (size_t parserIndex = 0; parserIndex < parsingFunctions.size(); parserIndex++) {
            if (parsingFunctions[parserIndex](command, index, engine)) {
                continue;
            }
        }
    }
}
