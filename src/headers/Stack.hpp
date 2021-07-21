#ifndef STACK_HPP_
#define STACK_HPP_

#include <vector>

#include <vector>

template<typename T>
class Stack {
    public:
        void add(T value) {
            _stack.push_back(value);
        }

        T pop(void) {
            T value = _stack[_stack.size() - 1];

            _stack.pop_back();
            return value;
        }

        size_t size(void) const {
            return _stack.size();
        }

    private:
        std::vector<T> _stack;
};

#endif /* !STACK_HPP_ */
