#ifndef LIBRARY_H
#define LIBRARY_H

#include <string> 
#include <vector> 
#include <regex>

using std::vector; 
using std::string; 

namespace VHRM {
    
    class Library
    {
        private:
            Library() {}
   
        public:
            static vector<string> split(string, string); 
    };

} // END NAMESPACE

#endif // LIBRARY_H
