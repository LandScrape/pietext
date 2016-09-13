//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Copyright (c) 2016 Evan Clemons

//This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

//Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

    //1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

    //2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

    //3. This notice may not be removed or altered from any source distribution.

//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//PieText is a dumb text editor that has very few features.

#include <iostream>
#include <fstream>

float versionNumber = 3.5;

struct fileData {
	
	public:
		std::string filePathString;
		std::string appendFilePathString;
		std::ofstream pieFile;	
		std::ofstream pieFileAppend;
	
};

fileData pieData;


class fileEditor {
		
	public: void openFile() {
			
			while (pieData.pieFile.is_open()) {
					
					pieData.pieFile.clear();
					pieData.pieFile.close();
					
					
			}
				
			//Gets the file path to create
			std::cout << "\nPlease enter the name and path of the file: "; //You might want to enter the extension, too
			std::cin >> pieData.filePathString;
			
			//Makes / opens the file
			const char* filePath = pieData.filePathString.c_str();
			pieData.pieFile.open(filePath);
				
		
	}
	
	public: void writeFile() {
			
			bool editing = true;
			bool hasEdited= false;
			
			while (editing == true) {
				
				
				//Gets user input
				std::string input = " ";
				std::cin >> input;
				
				if (input == "!stop") {
					
					if (hasEdited == true) {
						
						std::cout << "File saved: " << pieData.filePathString.c_str() << std::endl;
						editing = false;
						
					}
					
					if (hasEdited == false) {
						
						std::cout << "No changes have been made. Exiting.\n If a new file was created, it is currently empty.\n" << std::endl;
						hasEdited = false;
						editing = false;
						
					}
					
					
				}
				
				else {
					
					pieData.pieFile << input;
					pieData.pieFile << std::endl;
					hasEdited = true;
			
					
				}
				
			}
			

			
			
			
		
	}
	
	public: void readFile() {
		
		
		
		std::string line;
		
		std::cout << "\nPlease enter the name and path of the file: "; //You might want to enter the extension, too
		std::cin >> pieData.filePathString;
		
		std::cout << "\n";
		
		const char* filePath = pieData.filePathString.c_str();
		
		std::ifstream pieFileRead(filePath);
		
		pieData.pieFile.open(filePath);
		
		if(pieFileRead.is_open()) {
			
			while(getline(pieFileRead,line)) {
				
				std::cout << line << std::endl;
				pieData.pieFile << line;
				
			}
			

		
		}
		
		else {
			
			std::cout << "Unable to open file. Double-check name and file path.\n";
			
		}
		
	}
	
	public: void appendFileOpen() {		
		
		while (pieData.pieFileAppend.is_open()) {
			
			pieData.pieFileAppend.clear();		
			pieData.pieFileAppend.close();
			
					
		}
		
		
		//Gets the file path to create
		std::cout << "\nPlease enter the name and path of the file: "; //You might want to enter the extension, too
		std::cin >> pieData.appendFilePathString;
			
		//Makes / opens the file
		const char* filePath = pieData.appendFilePathString.c_str();
		pieData.pieFileAppend.open(filePath, std::fstream::app);
			
		
		
		
	}
	
	public: void appendFile() {
		
		
		bool editing = true;
		bool hasEdited= false;
			
		while (editing == true) {
				
				
			//Gets user input
			std::string input = " ";
			std::cin >> input;
				
			if (input == "!stop") {
					
				if (hasEdited == true) {
						
					std::cout << "File saved: " << pieData.appendFilePathString.c_str() << std::endl;
					editing = false;
						
				}
					
				if (hasEdited == false) {
						
					std::cout << "No changes have been made. Exiting.\n If a new file was created, it is currently empty.\n" << std::endl;
					hasEdited = false;
					editing = false;
						
				}
					
					
			}
				
			else {
					
				pieData.pieFileAppend << input;
				pieData.pieFileAppend << std::endl;
				hasEdited = true;
			
					
			}
				
		}
		

		
		
		
	}
		
		
		
		
		
		
		
	
};

fileEditor pieEditor;

int main() {
	
	while (true) {
	
		//My software is friendly, so it welcomes you
		std::cout << "Welcome to PieText!" << std::endl;
		
		std::cout << "What would you like to do?\n (c = Create new / override, a = Create new / append,\n v = View, i = Info, e = Exit): ";
		std::string toDo;
		std::cin >> toDo;
		
		if (toDo == "c") {
			
			
			pieEditor.openFile();
			
			std::cout << "Now editing file: " << pieData.filePathString.c_str() << std::endl << std::endl;
			std::cout << "This text editor is not very intelligent. It writes to the file line-by-line\n and saves every time the user presses enter.\n Type '!stop' stop editing.\n" << std::endl;
			
			pieEditor.writeFile();
			
			
			
		
	}
	
	else if (toDo == "v") {
		
		pieEditor.readFile();
		std::cout << "\n";
			
	}
		
			
		
	
	
	else if (toDo == "i") {
		
		std::cout << "\nPieText is a simple application that allows you to create and view text files. \nIt is not very feature-rich,\n and you are probably better off using nano or something.\n" << std::endl;
		std::cout << "Using PieText version " << versionNumber << std::endl << std::endl;
		std::cout << "Copyright (c) 2016 Evan Clemons\n";
		std::cout << "This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.\n";
		std::cout << "Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:\n";
		std::cout << "1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.\n";
		std::cout << "2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.\n";
		std::cout << "3. This notice may not be removed or altered from any source distribution.\n" << std::endl;

		
	}
	
	else if (toDo == "e") {
		
		return 0;
		
	}
	
	else if (toDo == "a") {
		
		
		pieEditor.appendFileOpen();
		
		std::cout << "Now appending file: " << pieData.appendFilePathString.c_str() << std::endl << std::endl;
		std::cout << "This text editor is not very intelligent. It writes to the file line-by-line\n and saves every time the user presses enter.\n Type '!stop' stop editing.\n" << std::endl;		

		pieEditor.appendFile();
		
		
		

		
	}
	
	
	else {
		
		std::cout << "Invalid input." << std::endl;
		
	}
	
	
	

			
		
}


}
