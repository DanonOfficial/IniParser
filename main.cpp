#include <iostream>
#include <map>

using namespace std;

#include "IniParser.h"

int main() {
    try {
        std::cout << "wow\n";
        parser::IniParser a;
        a.initialize("kek.ini");
        std::cout << a.getData<std::string>(string("DEBUG"), string("DBAddressIP")) << std::endl;
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
