#include <iostream>
#include "/Users/henry2112/Desktop/cse3150/hw/week_2/include/greeting_utils.h"
using std::cout;
using std::string;
using std::cin;
using std::endl;

namespace greetingUtils{
    string create_message(const std::string& name){
        string greeting;

        greeting = "Hello, " + name;
        return greeting;
    }

    char* format_as_c_string(const std::string& msg){
        size_t size = msg.size() + 1;
        char* c_string = new char[size];
        std::strcpy(c_string, msg.c_str()); // Copy the string including null terminator
        return c_string;
    }
}