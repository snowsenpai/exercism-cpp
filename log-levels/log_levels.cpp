#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message
    return line.substr(line.find(" ") + 1);
}

std::string log_level(std::string line) {
    // return the log level
    return line.substr(1, line.find("]"));
}

std::string reformat(std::string line) {
    // return the reformatted message
    std::string message = line.substr(line.find(" ") + 1);
    std::string level = line.substr(1, line.find("]"));

    return message + " (" + level + ")";
}
}  // namespace log_line
