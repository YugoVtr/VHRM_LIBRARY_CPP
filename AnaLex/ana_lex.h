#ifndef ANA_LEX_H
#define ANA_LEX_H

#include <exception>
#include <string>
#include <unordered_map>
#include <fstream>

#include "../ManipulaArquivo/manipula_arquivo.cpp"

using std::string;
typedef std::unordered_map<string, string> map_string;

namespace VHRM {
    class AnaLex
    {
        private:
            map_string palav_reserv; 
            map_string tok_s_atrib; 
            void initTokens(); 

        public:
            AnaLex(string);
            ~AnaLex();
            string getToken(string); 
    };

} // END NAMESPACE

#endif // ANA_LEX_H
