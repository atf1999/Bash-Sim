#include <iostream>
#include <windows.h>
#include <direct.h>
#include <locale>
#include <cstdlib>
#include <Commands.hpp>
using namespace std;
//Function to get cwd of the exe
string getDirectory();
//used for recursiveness
void programInit();
//resets the command
void reset();
//exits program;
int close();
//String to hold command
string command = "";
//String for directory
string directory = "";
//lowercase command
string lowerCommand = "";
string dSlash = "\\";
string slash = dSlash.substr(0, 1);
int main()
{
   //Objects for coloring console text
   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   WORD wOldColor;
   CONSOLE_SCREEN_BUFFER_INFO textSchema;

   //Retain current color data
   GetConsoleScreenBufferInfo(h, &textSchema);
   wOldColor = textSchema.wAttributes;

   //Intialize program
   directory = getDirectory();
   cout<<"Bash Command Line Program.  Input a command to execute\n\n";
   programInit();



   return 0;
}
//Function to get exe directory
string getDirectory(){
   char buffer[MAX_PATH];
   GetModuleFileName(NULL, buffer, MAX_PATH);
   string::size_type pos = string(buffer).find_last_of("\\/");
   return string(buffer).substr(0, pos);
}
void reset(){lowerCommand = "";}
int close(){return 0x0;}

void programInit(){
   //Creates directory
   cout << directory + ">" << endl;
   cin>> command;//Input for command

   //Convert to lowercase
   locale loc;
   for(int i = 0; i < command.length(); ++i){
      lowerCommand += std::tolower(command[i], loc);
   }

   //Initialize class object
   Commands input(lowerCommand);

   //adds directory
   input.setDirectory(directory);


   if(input.getCommand() == "ls"){
        cout<<"You inputed the ls command\n\n";
        input.getFiles();
        reset();
        programInit();
   }
   else if(input.getCommand() == "cd"){
          cout<<input.getCWDirectory()<<"\n\n";
          reset();
          programInit();
   }
   else if(input.getCommand() == "exit"){
      close();
   }
   else{
        cout<<"Command " <<"'"<<input.getCommand()<<"'"<<" is not supported";
}



}
