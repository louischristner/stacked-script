#include "reader.hpp"

void remove_comments(std::string &content)
{
    std::size_t subIndex = 0;

    for (std::size_t index = 0; index < content.size(); index++) {
        if (content[index] == '\'') {
            for (subIndex = index; content[subIndex] != '\n' && content[subIndex] != '\0'; subIndex++);
            for (std::size_t replaceIndex = index; replaceIndex < subIndex; replaceIndex++) {
                content[replaceIndex] = ' ';
            }
        }
    }
}

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

    remove_comments(content);

    for (std::size_t index = 0; index < content.size(); index++)
        if (content[index] == '\n' || content[index] == '\t')
            content[index] = ' ';

    return content;
}