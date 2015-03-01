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
//String to hold command
string command = "";
//String for directory
string directory = "";
//lowercase command
string lowerCommand = "";
//Double slash helps avoid escape literal
string dSlash = "\\";
//get slash
string slash = dSlash.substr(0, 1);


//Objects for coloring console text
   HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
   WORD wOldColor;
   CONSOLE_SCREEN_BUFFER_INFO textSchema;
int main()
{


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

void programInit(){
   //Creates directory
   cout << directory + ">" << endl;
   cin>> command;//Input for command

   //Convert to lowercase
   locale loc;
   for(int i = 0; i < command.length(); ++i){lowerCommand += std::tolower(command[i], loc);}


   //Initialize class object
   Commands input(lowerCommand);

   //adds directory
   input.setDirectory(directory);


   if(input.getCommand() == "ls"){
        //Console text to green
        SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        //prints current files
        input.getFiles();
        //Console text to regular
        SetConsoleTextAttribute(h, wOldColor);
        //clears command
        reset();
        //recursivity
        programInit();
   }
   else if(input.getCommand() == "cd"){
          //Console text to green
          SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
          //Prints directory
          cout<<input.getCWDirectory()<<"\n\n";
          //change color to regular
          SetConsoleTextAttribute(h, wOldColor);
          //clears the command
          reset();
          //recursive the file
          programInit();
   }
   else if(input.getCommand() == "exit"){
    //exit program
   }
   else if(input.getCommand() == "bash"){reset();/*clear command*/main();/*restarts program*/}
   else if(input.getCommand() == "time"){
    //text to green
    SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    //time objects
    time_t now = time(0);
    char *date = ctime(&now);
    //print the time
    cout<<date;

    //text to regular color
    SetConsoleTextAttribute(h,wOldColor);

    //clear command
    reset();
    //recursivity
    programInit();
   }
   else{
        SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout<<"Command " <<"'"<<input.getCommand()<<"'"<<" is not supported"<<endl;
        SetConsoleTextAttribute(h, wOldColor);
        reset();
        programInit();
}
}
