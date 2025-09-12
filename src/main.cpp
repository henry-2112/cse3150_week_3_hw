#include <iostream>
#include "/Users/henry2112/Desktop/cse3150/hw/week_2/include/greeting_utils.h"
using std::cout;
using std::string;
using std::cin;
using std::endl;
using namespace greetingUtils;

int main(){
    string name;
    cout << "Enter name: ";
    std::getline(cin, name);
    string greeting = create_message(name);
    char* greeting_c_string = format_as_c_string(greeting);
    cout << greeting_c_string << endl;
    delete greeting_c_string;
    return 0;
}