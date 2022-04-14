#include "reader.hpp"

std::string reader(const std::string &filepath)
{
    std::ifstream file_stream(filepath);

    if (!file_stream.good()) {
        throw InvalidReaderException("Invalid file: " + filepath);
    }

    std::string content(
        (std::istreambuf_iterator<char>(file_stream)),
        (std::istreambuf_iterator<char>()));

    file_stream.close();

    for (std::size_t index = 0; index < content.size(); index++)
        if (content[index] == '\n' || content[index] == '\t')
            content[index] = ' ';

    return content;
}