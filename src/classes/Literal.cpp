#include <string>

class Literal {
    public:
        enum Type {
            INTEGER,
            STRING,
            BOOLEAN
        };

        Literal(Type type, std::string value):
            _type(type), _value(value) {}

        Type getType() const {
            return _type;
        }

        std::string getValue() const {
            return _value;
        }

        std::string toString() const {
            return "(" + enumToString() + " : " + _value + ")";
        }

    private:
        std::string enumToString() const {
            switch (_type) {
                case INTEGER:
                    return "INTEGER";
                case STRING:
                    return "STRING";
                case BOOLEAN:
                    return "BOOLEAN";
                default:
                    return "UNTYPED";
            }
        }

    private:
        Type _type;
        std::string _value;
};