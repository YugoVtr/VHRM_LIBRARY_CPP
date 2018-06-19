#include <iostream>

#include "AnaLex/ana_lex.cpp" 

using std::cin;
using std::cout;
using std::string;

int main() {
    try {
        VHRM::AnaLex analex("main"); 
        cout << analex.getToken("include"); 
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0; 
}