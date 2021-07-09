#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <string>

#include "Dictionary.hpp"
#include "Literal.hpp"
#include "Stack.hpp"

struct Engine {
    Stack<Literal> stack;
    Stack<std::string> userDefinedFunctions;
    Dictionary<std::string, void (*)(Engine &)> operations;
};

#endif /* !ENGINE_HPP_ */
