//
// Created by danonofficial on 03.09.17.
//

#ifndef OOP_INI_READER_H
#define OOP_INI_READER_H

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include "NoFileError.h"
#include "SectionError.h"
#include "VariableError.h"
#include "WrongFormatError.h"
#include "NoSuchVariable.h"

namespace parser {
    class IniParser {
    public:
        IniParser() = default;

        void printData() const;

        void initialize(const std::string &name);

        bool isHaveSection(const std::string &name) const;

        bool isHaveVariable(const std::string &sectionName, const std::string &variableName) const;

        template<typename T>
        T getData(const std::string &sectionName, const std::string &variableName) const;

        virtual ~IniParser() = default;


    private:
        std::map<std::string, std::map<std::string, std::string>> data;


    };

    template<class T>
    T IniParser::getData(const std::string &sectionName, const std::string &variableName) const {
        if (!isHaveVariable(sectionName, variableName)) {
            throw error::NoSuchVariable(
                    "Please check variable and section name\n section: " + sectionName + "\n variable: " +
                    variableName);
        }
        std::stringstream in;
        in << (*(*data.find(sectionName)).second.find(variableName)).second;
        T res;
        in >> res;
        if (!in.eof()) {
            throw error::WrongFormatError("Not compatible data types");
        }
        return res;
    }
}


#endif //OOP_INI_READER_H
