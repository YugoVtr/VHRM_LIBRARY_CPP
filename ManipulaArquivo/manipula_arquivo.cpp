#include "manipula_arquivo.h"

namespace VHRM {
    ManipulaArquivo::ManipulaArquivo(string nome) :
        file(nome)
    {
        if (! file.is_open())  { throw string("err"); }

    } // END CONSTRUCTOR

    map_string ManipulaArquivo::readAsMap(string delimitador) {
        string linha(""); 
        map_string resultado; 
        while( getline(this->file, linha) ) {
            std::vector<string> c = Library::split(
                linha,
                "([^" + delimitador + "]+)"
            );
            resultado[c[0]] = c[1]; 
        }
        this->file.seekg (0, this->file.beg);
        return resultado; 
    }

    string ManipulaArquivo::read() {
        string linha(""); 
        string resultado(""); 
        while( getline(this->file, linha) ) {
            resultado += linha + string("\n"); 
        }
        this->file.seekg (0, this->file.beg);
        return resultado; 
    }

    void ManipulaArquivo::copy(string to) {
        std::ofstream f_copy(to);
        f_copy << this->read(); 
        f_copy.close(); 
    }

    ManipulaArquivo::~ManipulaArquivo() {
        file.close(); 
    } // END DESTRUCTOR
} // END NAMESPACE 

