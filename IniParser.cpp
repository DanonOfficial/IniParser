//
// Created by danonofficial on 03.09.17.
//


#include <fstream>
#include "IniParser.h"


bool isLiteralOrNumeric(char a);


namespace parser {
    IniParser::IniParser(const std::string name) {
        std::ifstream in(name);
        if (!in) {
            throw error::NoFileError("There is no this file))0)");
        } else {
            std::string temp;//string that get
            std::string sectionName;//name of section
            std::string variableName;//name of new variable
            std::string variableValue;//value of new variable;
            getline(in, temp);
            size_t stringCount = 1;
            while (in) {
                for (int i = 0; i < temp.length(); i++) {
                    if (temp[i] == ' ') {
                        continue;
                    }
                    if (temp[i] == ';') {
                        break;
                    }
                    if (temp[i] == '[') {
                        sectionName.clear();
                        i++;
                        while (temp[i] != ']') {
                            if (i > temp.length() || temp[i] == ' ') {
                                throw error::SectionError(
                                        "SectionName error at " + std::to_string(stringCount) + " str");
                            }
                            sectionName += temp[i];
                            i++;
                        }
                        break;
                    }
                    if (isLiteralOrNumeric(temp[i])) {
                        variableName.clear();
                        while (isLiteralOrNumeric(temp[i])) {//creating name wow bug with exception
                            if (i > temp.length()) {
                                throw error::VariableError(
                                        "Wrong Variable name at " + std::to_string(stringCount) + " str");
                            }
                            variableName += temp[i];
                            i++;
                        }
                        while (temp[i] != '=') {
                            i++;
                            if (isLiteralOrNumeric(temp[i])) {
                                throw error::VariableError(
                                        "Wrong Variable name at " + std::to_string(stringCount) + " str");
                            }
                        }
                        i++;
                        while (!isLiteralOrNumeric(temp[i])) {//looking for value
                            if (i > temp.length()) {
                                throw error::VariableError(
                                        "There is no value of variable at " + std::to_string(stringCount) + " str");
                            }
                            i++;
                        }
                        variableValue.clear();
                        while (i < temp.length() && temp[i] != ';') {//creating value
                            variableValue += temp[i];
                            i++;
                        }
                        data[sectionName][variableName] = variableValue;
                        break;
                    }
                }
                getline(in, temp);
                stringCount++;
            }
        }
    }

    IniParser::~IniParser() {
        data.clear();
    }

    void IniParser::printData() const {
        for (auto i = data.begin(); i != data.end(); i++) {
            std::cout << "section name: " << (*i).first << std::endl;
            for (auto j = (*i).second.begin(); j != (*i).second.end(); j++) {
                std::cout << (*j).first << " = " << (*j).second << std::endl;
            }
        }
    }

    bool IniParser::isHaveSection(const std::string name) const {
        auto isHere = data.find(name);
        return isHere != data.end();
    }

    bool IniParser::isHaveVariable(const std::string sectionName, const std::string variableName) const {
        if(isHaveSection(sectionName)){
            auto isHere =(*data.find(sectionName)).second.find(variableName);
            return isHere != (*data.find(sectionName)).second.end();
        }
        return false;
    }
}

bool isLiteralOrNumeric(char a) {
    return (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9');
}
