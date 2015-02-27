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
   //Constructor to get command
   Commands(string command);
   /**
   Getters and Setters
   **/

   //returns inputed command
   string getCommand();
   //sets the command
   void setCommand(string newCmd);

   //sets directory
   void setDirectory(string d);

   //get directory
   string getCWDirectory();

   //allocate files and folders names to array
   void getFiles();

   private:
   //used to localize command in cpp file
   string cmd;
   //localize directory
   string cwd;

};


#endif // COMMANDS_HPP_INCLUDED
