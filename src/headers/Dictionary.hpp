#ifndef DICTIONARY_HPP_
#define DICTIONARY_HPP_

#include <unordered_map>

#include "../exceptions/InvalidKeyException.hpp"

template<typename T, typename U>
class Dictionary {
    public:
        void add(T key, U value) {
            if (_dictionary.find(key) == _dictionary.end()) {
                _dictionary.insert(std::make_pair(key, value));
            }
        }

        U get(T key) {
            if (_dictionary.find(key) == _dictionary.end())
                throw InvalidKeyException("Key (" + key + ") does not exist.");
            return _dictionary[key];
        }

    private:
        std::unordered_map<T, U> _dictionary;
};

#endif /* !DICTIONARY_HPP_ */
