#ifndef LITERAL_HPP_
#define LITERAL_HPP_

#include <string>

class Literal {
    public:
        enum Type {
            INTEGER,
            STRING,
            BOOLEAN,
            BLOCK
        };

        Literal(Type type, std::string value);

        Type getType() const;
        std::string getValue() const;

        std::string toString() const;

    private:
        std::string enumToString() const;

    private:
        Type _type;
        std::string _value;
};

#endif /* !LITERAL_HPP_ */
