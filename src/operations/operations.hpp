#ifndef OPERATIONS_HPP_
#define OPERATIONS_HPP_

#include "../headers/Engine.hpp"

#include "../exceptions/InvalidTypeException.hpp"

// literal operations
void add(IEngine &engine);
void sub(IEngine &engine);
void mul(IEngine &engine);
void div(IEngine &engine);
void mod(IEngine &engine);
void gt(IEngine &engine);

// stack operations
void swap(IEngine &engine);
void dup(IEngine &engine);
void cmp(IEngine &engine);

#endif /* !OPERATIONS_HPP_ */
