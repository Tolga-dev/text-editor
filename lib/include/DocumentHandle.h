//
// Created by xamblot on 4/10/23.
//

#ifndef TEXTEDITOR_DOCUMENTHANDLE_H
#define TEXTEDITOR_DOCUMENTHANDLE_H


#include <iostream>
#include <fstream>

class DocumentHandle
{
public:

    DocumentHandle() = default;
    ~DocumentHandle() = default;
    DocumentHandle(DocumentHandle const& DocumentHandle) = delete;
    DocumentHandle(DocumentHandle&& DocumentHandle)= default;
    DocumentHandle& operator=(const DocumentHandle& DocumentHandle) = delete;
    DocumentHandle& operator=(DocumentHandle&& DocumentHandle) = default;

    void Open_File();
    void Init(std::string& file_name);

    std::ifstream p_file_ptr;
    std::string p_file_name;

};


#endif //TEXTEDITOR_DOCUMENTHANDLE_H
