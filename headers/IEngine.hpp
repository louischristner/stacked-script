#ifndef IENGINE_HPP_
#define IENGINE_HPP_

#include "Dictionary.hpp"
#include "Literal.hpp"
#include "Stack.hpp"

struct IEngine {
    virtual ~IEngine() = default;

    Stack<Literal> stack;
    Dictionary<std::string, std::string> userDefinedFunctions;
    Dictionary<std::string, void (*)(IEngine &)> operations;
};

#endif /* !IENGINE_HPP_ */
