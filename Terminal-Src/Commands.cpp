#include <Commands.hpp>
#include <iostream>
#include <string>
#include <dirent.h>
using namespace std;
Commands::Commands(string command){
    Commands::cmd = command;
}
string Commands::getCommand(){
    return Commands::cmd;
}
void Commands::setDirectory(string d){
   Commands::cwd = d;
}
string Commands::getCWDirectory(){
     return Commands::cwd;
}
void Commands::getFiles(){
   DIR *dir;
   const *char;
   struct dirent *entry;
    if((dir = opendir(getCWDirectory())) != NULL){
        while((entry = readdir(dir)) != NULL){
            cout<<entry->d_name + ",";
        }
    }

}
