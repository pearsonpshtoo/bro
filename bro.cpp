#include<iostream>
#include<string.h>
#include<stdio.h>


#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>

using namespace std;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::shared_ptr<FILE> pipe(popen(cmd, "r"), pclose);
    if (!pipe) throw std::runtime_error("popen() failed!");
    while (!feof(pipe.get())) {
        if (fgets(buffer.data(), 128, pipe.get()) != nullptr){
            result += buffer.data();
	}
    }
    return result;
}

int main(int argc, char *argv[]){
	string command;
	string tCommand;
	
	if (strcmp(argv[1], "gimme") == 0){
		command = "install";	
	}
	else if (strcmp(argv[1], "wassupdate") == 0)
		command = "update";
	else if (strcmp(argv[1], "wassupgrade") == 0)
		command = "upgrade";

	if (argc < 3){
		tCommand = "sudo apt-get " + command;
	}
	else if (strcmp(argv[2], "yuh") == 0){
		tCommand = "sudo apt-get " + command + " -y";
	}
	else {
		tCommand = "sudo apt-get " + command + " ";
	       	for (int a = 2; a < argc ; a++)	
			tCommand = tCommand + argv[a] + " ";
	}
	cout << "Entered command: \"";
	for (int i = 0; i < argc ; ++i){
		cout << argv[i];
		if (argc - i > 1)
			cout << " ";
	}
	cout << "\"" << endl;
	cout << "Translated command: \"" << tCommand << "\"" << endl;
	cout << exec(tCommand.c_str());

}
