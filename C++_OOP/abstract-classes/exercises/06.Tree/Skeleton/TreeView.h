#ifndef TREEVIEW_H
#define TREEVIEW_H

#include <string>
#include <sstream>
#include <vector>

#include "FileSystemObject.h"
#include "Directory.h"
#include "File.h"

class Shortcuts;

std::string getTreeView(std::vector<std::shared_ptr<FileSystemObject>>& rootObjects) {
    std::ostringstream outputStream;

    for (auto& fileSystemObj : rootObjects) {
        outputStream << fileSystemObj->getName() << std::endl;

        std::shared_ptr<Directory> dirPtr = std::dynamic_pointer_cast<Directory>(fileSystemObj);
        std::shared_ptr<File> filePtr = std::dynamic_pointer_cast<File>(fileSystemObj);
        std::shared_ptr<Shortcuts> shortcutsPtr = std::dynamic_pointer_cast<Shortcuts>(fileSystemObj);

        if (dirPtr) {
            std::vector<std::shared_ptr<FileSystemObject>> dirObjects = dirPtr->getDirObjects();
            std::vector<std::shared_ptr<FileSystemObject>>::const_iterator dirObjIt = dirObjects.begin();

            for ( ; dirObjIt != dirObjects.end(); dirObjIt++) {
                outputStream << "--->" << (*dirObjIt)->getName() << std::endl;

                std::shared_ptr<Directory> nestedDirPtr = std::dynamic_pointer_cast<Directory>(*dirObjIt);
                while (nestedDirPtr != nullptr) {
                    std::vector<std::shared_ptr<FileSystemObject>> nestedDirObjects = nestedDirPtr->getDirObjects();
                    std::vector<std::shared_ptr<FileSystemObject>>::const_iterator nestedDirObjIt = nestedDirObjects.begin();
                    bool isPtrNested = false;
                    std::string arrows = "--->--->";
                    while (nestedDirObjIt != nestedDirObjects.end()) {
                        outputStream << arrows << (*nestedDirObjIt)->getName() << std::endl;
                        nestedDirObjIt++;
                        isPtrNested = true;
                    }

                    // std::shared_ptr<Directory> nestedDirPtr = std::dynamic_pointer_cast<Directory>(*nestedDirObjIt);
                    arrows.append("--->");

                    if (isPtrNested) {
                        break;
                    }
                }       
            }
        } 

        if (filePtr && filePtr->getName() != fileSystemObj->getName()) {
            outputStream << filePtr->getName() << std:: endl;
        }


    }

    return outputStream.str();
}

#endif // !TREEVIEW_H
