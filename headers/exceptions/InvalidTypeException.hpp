#ifndef INVALIDTYPEEXCEPTION_HPP_
#define INVALIDTYPEEXCEPTION_HPP_

#include <string>
#include <exception>

class InvalidTypeException : public std::exception {
    public:
        explicit InvalidTypeException(const std::string &msg) noexcept : Msg(msg) {}
        const char *what() const noexcept override {
            return Msg.data();
        }

    private:
        std::string Msg;
};

#endif /* !INVALIDTYPEEXCEPTION_HPP_ */
