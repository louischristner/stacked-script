#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <regex>
#include <string>
#include <vector>

#include "../../headers/IEngine.hpp"

void parser(const std::string &, IEngine &);
bool literal_parser(const std::string &, size_t &, IEngine &);
bool function_parser(const std::string &, size_t &, IEngine &);
bool operation_parser(const std::string &, size_t &, IEngine &);

void user_defined_functions_parser(std::string &, IEngine &);

#endif /* !PARSER_HPP_ */
