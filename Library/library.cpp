#include "library.h"

namespace VHRM {
    vector<string> Library::split(string subject, string pattern) {
        vector<string> resultado; 
        std::regex word_regex(pattern);
        auto words_begin = std::sregex_iterator(
            subject.begin(),
            subject.end(),
            word_regex
        );
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
            std::smatch match = *i;
            resultado.push_back( match.str() );
        }
        
        return resultado; 
    } // END SPLIT
} // END NAMESPACE 

