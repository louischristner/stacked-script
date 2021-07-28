#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <regex>
#include <string>
#include <vector>

#include "../../headers/IEngine.hpp"

void parser(const std::string &, IEngine &);
bool literal_parser(const std::string &, size_t &, IEngine &);
bool operation_parser(const std::string &, size_t &, IEngine &);


#endif /* !PARSER_HPP_ */
