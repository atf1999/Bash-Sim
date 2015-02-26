#include <iostream>
#include <windows.h>
#include <direct.h>
#include <conio.h>
#include <Commands.hpp>
using namespace std;
//Function to get cwd of the exe
string getDirectory();
void programInit();
//String to hold command
string command = "";
//String for directory
string directory = "";
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

void programInit(){
//Creates directory
cout << directory + ">" << endl;
cin>> command;//Input for command

//Initialize class object
Commands input = Commands(command);
cout<<input.getCommand();



}
