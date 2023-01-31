#include <iostream> 
#include <fstream>

int braces_balance (char* filepath) {
	std::ifstream fin(filepath);
	if (fin.fail()) {
		std::cerr << "Unable to open the file!" << std::endl;
		exit(-1);
	}
	
	int balance = 0;
	std::string line = "";
	while (!fin.eof()) {
		std::getline(fin, line);
		for (int i = 0; i < line.size(); ++i) {
			if (line[i] == '{') {
				++balance;
			} else if (line[i] == '}') {
				--balance;
				if (balance < 0) {
					return -1;
				}
			}
		}
	}
	if (balance) {
		return -1;
	}
	return 0;
}


int main (int argc, char** argv) { 
	
	if (argc == 1) {
		std::cerr << "Please, enter file's path!" << std::endl;
		exit(1);
	} 

	std::ofstream fout("result.txt");
	for (int i = 1; i < argc; ++i) {
		if (!braces_balance(argv[i])) {
			fout << "The balance of curly braces in the file " << argv[i] << " is maintained \n";
		} else {	
			fout << "The balance of curly braces in the file " << argv[i] << " is disturbed \n";
		}
		
			
	}	
	return 0; 
}
