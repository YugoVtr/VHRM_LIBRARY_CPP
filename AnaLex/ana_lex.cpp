#include "ana_lex.h"

namespace VHRM {
    AnaLex::AnaLex(string file) {
        string ext(".txt");
        string dir("AnaLex/Testes/");
        string link(dir + file + ext); 
        string backup(dir + file + string("Backup") + ext);
        ManipulaArquivo obj_file(link);
        obj_file.copy(backup); 
        initTokens(); 
    } // END CONSTRUCTOR

    void AnaLex::initTokens() {
        
        try {
            string pr_dir("AnaLex/Tokens/palavras_reservadas.txt");
            ManipulaArquivo pr(pr_dir);
            this->palav_reserv = pr.readAsMap(";");

            string tsa_dir("AnaLex/Tokens/tokens_sem_atributos.txt");
            ManipulaArquivo tsa(tsa_dir);
            this->tok_s_atrib = tsa.readAsMap("?");
        }
        catch(const std::exception& e) {
            throw e; 
        }
    
    } // END INITTOKENS

    string AnaLex::getToken(string palavra) { 
        map_string::const_iterator find;
        find = this->palav_reserv.find( palavra ); 
        if ( find  != this->palav_reserv.end()) {
            return find->second; 
        }
        find = this->tok_s_atrib.find( palavra );
        if ( find  != this->tok_s_atrib.end()) {
            return find->second; 
        }
        return ""; 
    }

    AnaLex::~AnaLex() {

    } // END DESTRUCTOR
} // END NAMESPACE 

