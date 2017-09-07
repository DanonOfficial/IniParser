//
// Created by danonofficial on 05.09.17.
//

#ifndef OOP_SECTIONERROR_H
#define OOP_SECTIONERROR_H

#include <stdexcept>

namespace error {
    class SectionError : std::exception {
    public:

        explicit SectionError(std::string msg) noexcept : msg(std::move(msg)) {}

        ~SectionError() noexcept override = default;

        const char *what() const noexcept override{
            return msg.c_str();
        }

    private:
        std::string msg;
    };
}
#endif //OOP_SECTIONERROR_H
