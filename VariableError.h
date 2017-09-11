//
// Created by danonofficial on 05.09.17.
//

#ifndef OOP_VARIABLENAMEERROR_H
#define OOP_VARIABLENAMEERROR_H

#include <stdexcept>

namespace error {
    class VariableError : public std::exception {
    public:

        explicit VariableError(std::string msg) noexcept : msg(std::move(msg)) {}

        ~VariableError() noexcept override= default;

        const char *what() const noexcept override {
            return msg.c_str();
        }

    private:
        std::string msg;
    };
}


#endif //OOP_VARIABLENAMEERROR_H
