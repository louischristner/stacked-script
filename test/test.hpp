#ifndef TEST_HPP_
#define TEST_HPP_

#include <string>
#include <exception>

class InvalidTestException : public std::exception {
    public:
        explicit InvalidTestException() noexcept : Msg("Invalid test") {}
        explicit InvalidTestException(const std::string &msg) noexcept : Msg(msg) {}
        const char *what() const noexcept override {
            return Msg.data();
        }

    private:
        std::string Msg;
};

#endif /* !TEST_HPP_ */
