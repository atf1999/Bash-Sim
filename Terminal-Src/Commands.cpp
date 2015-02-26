#include <Commands.hpp>
#include <iostream>
#include <string>
using namespace std;
Commands::Commands(string command){
    Commands::cmd = command;
}
string Commands::getCommand(){
   return cmd;
}
