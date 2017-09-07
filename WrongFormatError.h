//
// Created by danonofficial on 07.09.17.
//

#ifndef OOP_WRONGFORMATERROR_H
#define OOP_WRONGFORMATERROR_H

#include <string>
#include <stdexcept>

namespace error {
    class WrongFormatError : std::exception {
    public:

        explicit WrongFormatError(std::string msg) noexcept : msg(msg) {}

        ~WrongFormatError() noexcept override = default;

        const char *what() const noexcept override {
            return msg.c_str();
        }

    private:
        std::string msg;
    };
}
#endif //OOP_WRONGFORMATERROR_H
