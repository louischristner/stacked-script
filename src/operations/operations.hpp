#ifndef OPERATIONS_HPP_
#define OPERATIONS_HPP_

#include "../headers/Engine.hpp"

#include "../exceptions/InvalidTypeException.hpp"

void add(IEngine &engine);
void sub(IEngine &engine);
void mul(IEngine &engine);
void div(IEngine &engine);
void mod(IEngine &engine);

#endif /* !OPERATIONS_HPP_ */
