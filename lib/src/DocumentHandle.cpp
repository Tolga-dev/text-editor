#include <iostream>
#include "include/DocumentHandle.h"

void DocumentHandle::Init(std::string &f_file_name) {
    Open_File();
    this->p_file_name = f_file_name;
    if(f_file_name.empty())
        std::cerr << "Enter A File Name! " << f_file_name << std::endl;


    this->p_file_ptr.open(this->p_file_name, std::ios::out | std::ios::in);

    if(!this->p_file_ptr.is_open())
        std::cerr << "Error opening file! " << f_file_name << std::endl;

}

void DocumentHandle::Open_File() {
    this->p_file_ptr.open(this->p_file_name,std::ios::out | std::ios::in);
}