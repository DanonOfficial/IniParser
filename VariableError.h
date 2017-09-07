//
// Created by danonofficial on 05.09.17.
//

#ifndef OOP_VARIABLENAMEERROR_H
#define OOP_VARIABLENAMEERROR_H

#include <stdexcept>

namespace error {
    class VariableError : std::exception {
    public:

        VariableError(std::string msg) noexcept : msg(msg) {}

        ~VariableError() noexcept = default;

        const char *what() const noexcept {
            return msg.c_str();
        }

    private:
        std::string msg;
    };
}


#endif //OOP_VARIABLENAMEERROR_H
