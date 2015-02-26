#ifndef COMMANDS_HPP_INCLUDED
#define COMMANDS_HPP_INCLUDED
#include <string>
using namespace std;
/**
Commands class: Parses Command inputs

Commands supported:
    ls: display files in current directory
    cd: change directory being used
**/
class Commands{
   public:
   //Used if user uses ls command
   Commands(string command);
   string getCommand();
   private:
    string cmd;


};


#endif // COMMANDS_HPP_INCLUDED
