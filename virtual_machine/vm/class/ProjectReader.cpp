#include "ProjectReader.h"

std::map <std::string, Class*> ProjectReader::read(std::string projectPath){
    if(projectPath[projectPath.length()-1] != '/'){
        projectPath += '/';
    }

    std::map <std::string, Class*> project;
    ClassReader classReader;

    std::vector <std::string> files = dirFiles(projectPath);
    for(unsigned int i = 0; i < files.size(); i++){
        std::string clsName = files[i];
        project[clsName] = classReader.fromFile(projectPath + clsName + ".sa");
    }

    return project;
}

void ProjectReader::refreshRelations(std::map <std::string, Class*> & project){
    std::map<std::string, Class*>::iterator i;
    for(i = project.begin(); i != project.end(); i++){
        if(i->second == NULL){
            continue;
        }
        i->second->updateRelations();
        ClassReader::refresh(i->second);
    }
}

std::vector <std::string> ProjectReader::dirFiles(std::string projectPath){
    std::vector <std::string> files = dirFilesAbsolute(projectPath);
    for(unsigned int i = 0; i < files.size(); i++){
        files[i] = files[i].substr(projectPath.length(), files[i].length() - projectPath.length() - 3);
    }
    return files;
}

std::vector <std::string> ProjectReader::dirFilesAbsolute(std::string projectPath){
    if(projectPath[projectPath.length()-1] != '/'){
        projectPath += '/';
    }

    std::vector <std::string> files;
    DIR * dir;
    struct dirent * ent;
    if ((dir = opendir(projectPath.c_str())) != NULL){
        while ((ent = readdir(dir)) != NULL){
            std::string name = ent->d_name;
            if (name == "." || name == ".."){
                continue;
            }

            if(ent->d_type == DT_DIR){
                std::vector <std::string> filesRec = dirFilesAbsolute(projectPath + name);
                files.insert(files.end(), filesRec.begin(), filesRec.end());
                continue;
            }
            files.push_back(projectPath + name);
        }
        closedir(dir);
    }
    return files;
}
