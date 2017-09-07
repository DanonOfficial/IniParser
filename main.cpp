#include <iostream>
#include <map>

using namespace std;

#include "IniParser.h"

int main() {
    try {
        std::cout << "wow\n";
        parser::IniParser a("kek.txt");
        std::cout << a.getData<float>(string("DEBUG"), string("PlentySockMaxSsize")) << std::endl;
    }
    catch (error::VariableError &a) {
        std::cout << a.what() << std::endl;
    }
    catch (error::NoFileError &a) {
        std::cout << a.what() << std::endl;
    }
    catch (error::WrongFormatError &a){
        std::cout << a.what() << std::endl;
    }
    return 0;
}