//
// Created by danonofficial on 07.09.17.
//

#ifndef OOP_NOSUCHVARIABLE_H
#define OOP_NOSUCHVARIABLE_H
#include <stdexcept>
namespace error {
    class NoSuchVariable : std::exception {
    public:

        NoSuchVariable(std::string msg) noexcept : msg(msg) {}

        ~NoSuchVariable() noexcept = default;

        const char *what() const noexcept {
            return msg.c_str();
        }

    private:
        std::string msg;
    };
}
#endif //OOP_NOSUCHVARIABLE_H
