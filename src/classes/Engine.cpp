#include "../../headers/Engine.hpp"

Engine::Engine()
{
    operations.add("+", add);
    operations.add("-", sub);
    operations.add("*", mul);
    operations.add("/", div);
    operations.add("%", mod);
    operations.add("=", cmp);
    operations.add(">", gt);
    operations.add("<", lt);
    operations.add(">=", ge);
    operations.add("<=", le);

    operations.add("swap", swap);
    operations.add("dup", dup);
    operations.add("over", over);
    operations.add("drop", drop);
    operations.add("nip", nip);
    operations.add("print", print);

    operations.add("if", if_cond);
    operations.add("when", when_cond);
}
