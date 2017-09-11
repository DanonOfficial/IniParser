//
// Created by danonofficial on 07.09.17.
//

#ifndef OOP_NOSUCHVARIABLE_H
#define OOP_NOSUCHVARIABLE_H
#include <stdexcept>
namespace error {
    class NoSuchVariable : public std::exception {
    public:

        explicit NoSuchVariable(std::string msg) noexcept : msg(std::move(msg)) {}

        ~NoSuchVariable()  noexcept override = default;

        const char *what() const noexcept override {
            return msg.c_str();
        }

    private:
        std::string msg;
    };
}
#endif //OOP_NOSUCHVARIABLE_H
