#include <iostream>
#include <vector>
#include <fstream>

void addTask(std::fstream & myFile);
void deleteTask(std::fstream & myFile);

int main() {
    std::cout << '\n';
    std::cout << "Hello" << std::endl;
    std::cout << "--------------------------------------" << std::endl;

    std::fstream myFile{"tasks.txt", std::ios::out | std::ios::in};

    // check if the file exists
    if (!myFile.is_open()) { 
        std::cout << "i needa make your file for you" << std::endl;

        // make new "tasks.txt" file
        std::ofstream tempFile{"tasks.txt"};
        tempFile << "eat poop\n";
        tempFile.close();
        myFile.open("tasks.txt", std::ios::in | std::ios::out);                

        std::cout << "here you go" << std::endl;
        std::cout << "here's whatcha gotta do:" << '\n' << std::endl;
    }
    else { 
        // this is if the file exists
        std::cout << "This is what you should be doing:" << std::endl;
    }

    // print out tasks
    int counter{1};
    std::string strTasks{};
    // print out stuff on the file
    while(std::getline(myFile, strTasks)) {
        std::cout << counter << ". " << strTasks << '\n';
    }
    std::cout << "--------------------------------------" << std::endl;

    // need to make this a while loop until quit
    // or do while

    while (true) {
        std::cout << "is there anything else you need?" << std::endl;
        std::cout << "1. add a task" << std::endl;
        std::cout << "2. delete a task" << std::endl;
        std::cout << "3. quit" << std::endl;

        int nextCommand{};
        int tempCommand{0};
        std::cin >> nextCommand;
        std::cin.ignore(10000, '\n');

        if (nextCommand == 1) {
            addTask(myFile);
        } 
        else if (nextCommand == 2) {
            deleteTask(myFile);
        }
        else {
            std::cout << "ok bye" << std::endl;
            break;
        }
        
    }


    myFile.close();
    std::cout << "--------------------------------------" << std::endl;
    std::cout << "Sayonara" << '\n' << std::endl;
    return 0;
}

void addTask(std::fstream & myFile) {
    std::cout << "adding task" << '\n';
}

void deleteTask(std::fstream & myFile) {
    std::cout << "deleting task" << '\n';
}


