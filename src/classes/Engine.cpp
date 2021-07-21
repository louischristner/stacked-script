#include "../headers/Engine.hpp"

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

    operations.add("swap", swap);
    operations.add("dup", dup);
}
