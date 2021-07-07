#include <unordered_map>

template<typename T, typename U>
class Dictionary {
    public:
        void add(T key, U value) {
            if (_dictionary.find(key) == _dictionary.end()) {
                _dictionary.insert(std::make_pair(key, value));
            }
        }

        U get(T key) {
            return _dictionary[key];
        }

    private:
        std::unordered_map<T, U> _dictionary;
};