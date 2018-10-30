#ifndef PROJECT_READER_H
#define PROJECT_READER_H

#include <map>
#include <string>
#include <dirent.h>
#include "./Class.h"
#include "./ClassReader.h"

class ProjectReader {
              
    private:
        
    
    public:
        std::map <std::string, Class*> read(std::string projectPath);
        std::vector <std::string> dirFiles(std::string projectPath);
        std::vector <std::string> dirFilesAbsolute(std::string projectPath);
        void refreshRelations(std::map <std::string, Class*> & project);
    
};

#endif