/*
** EPITECH PROJECT, 2021
** stacked-script
** File description:
** Literal
*/

#include "../../headers/Literal.hpp"

Literal::Literal(Type type, std::string value):
    _type(type), _value(value) {}

Literal::Type Literal::getType() const {
    return _type;
}

std::string Literal::getValue() const {
    return _value;
}

std::string Literal::toString() const {
    return "(" + enumToString() + " : " + _value + ")";
}

std::string Literal::enumToString() const {
    switch (_type) {
        case INTEGER:
            return "INTEGER";
        case STRING:
            return "STRING";
        case BOOLEAN:
            return "BOOLEAN";
        case BLOCK:
            return "BLOCK";
        default:
            return "UNTYPED";
    }
}