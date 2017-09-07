//
// Created by danonofficial on 05.09.17.
//

#ifndef OOP_SECTIONERROR_H
#define OOP_SECTIONERROR_H

#include <stdexcept>

namespace error {
    class SectionError : std::exception {
    public:

        SectionError(std::string msg) noexcept : msg(msg) {}

        ~SectionError() noexcept = default;

        const char *what() const noexcept {
            return msg.c_str();
        }

    private:
        std::string msg;
    };
}
#endif //OOP_SECTIONERROR_H
