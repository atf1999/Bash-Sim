#include <Commands.hpp>
#include <iostream>
#include <string>
#include <dirent.h>
#include <vector>
using namespace std;
//Fully localize command to class instance
Commands::Commands(string command){
    Commands::cmd = command;
}
//Returns command
string Commands::getCommand(){
    return Commands::cmd;
}
void Commands::setCommand(string newCmd){
   Commands::cmd = newCmd;
}
//Fully localize variable of the directory
void Commands::setDirectory(string d){
   Commands::cwd = d;
}
//returns the directory
string Commands::getCWDirectory(){
     return Commands::cwd;
}
//used for the ls command
void Commands::getFiles(){
   //Used to open directory
   DIR *dir;
   //gets directory entries
   struct dirent *entry;
   //vector to hold files and folders
   vector<string>names;
   //makes sure directory is not null
    if((dir = opendir(getCWDirectory().c_str())) != NULL){
        while((entry = readdir(dir)) != NULL){
            //Adds Items to vector
            names.push_back(entry->d_name);


        }
        //prints all but the last comma
        for(int j = 0; j < names.size(); ++ j){
            cout<<names[j];
            cout<<"\n";
        }
        cout<<"\n";
    }

}
