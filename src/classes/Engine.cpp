#include "Literal.cpp"
#include "Stack.cpp"
#include "Dictionary.cpp"

struct Engine {
    Stack<Literal> stack;
    Stack<std::string> userDefinedFunctions;
    Dictionary<std::string, void (*)(Engine &)> operations;
};