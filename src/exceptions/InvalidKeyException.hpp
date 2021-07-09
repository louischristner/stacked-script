#ifndef INVALIDKEYEXCEPTION_HPP_
#define INVALIDKEYEXCEPTION_HPP_

#include <string>
#include <exception>

class InvalidKeyException : public std::exception {
    public:
        explicit InvalidKeyException(const std::string &msg) noexcept : Msg(msg) {}
        const char *what() const noexcept override {
            return Msg.data();
        }

    private:
        std::string Msg;
};


#endif /* !INVALIDKEYEXCEPTION_HPP_ */
