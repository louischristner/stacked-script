#ifndef INVALIDREADEREXCEPTION_HPP_
#define INVALIDREADEREXCEPTION_HPP_

#include <string>
#include <exception>

class InvalidReaderException : public std::exception {
    public:
        explicit InvalidReaderException(const std::string &msg) noexcept : Msg(msg) {}
        const char *what() const noexcept override {
            return Msg.data();
        }

    private:
        std::string Msg;
};


#endif /* !INVALIDREADEREXCEPTION_HPP_ */
