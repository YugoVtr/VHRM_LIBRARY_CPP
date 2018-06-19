#ifndef MANIPULA_ARQUIVO_H
#define MANIPULA_ARQUIVO_H

#include <exception>
#include <string>
#include <vector>
#include <fstream>
#include <unordered_map>

#include "../Library/library.cpp"

using std::string;
typedef std::unordered_map<string, string> map_string;

namespace VHRM {
    class ManipulaArquivo
    {
        private:
            std::ifstream file;

        public:
            ManipulaArquivo(string);
            ~ManipulaArquivo();
            map_string readAsMap(string);  
            string read();
            void copy(string);            
    };

} // END NAMESPACE

#endif // MANIPULA_ARQUIVO_H
