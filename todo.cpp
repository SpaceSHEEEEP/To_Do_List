#include <iostream>
#include <vector>
#include <fstream>
#include <limits> // fix the cin.ignore below

void addTask(std::string fileName);
void deleteTask(std::string fileName);
void seeTasks(std::string fileName);

int main() {
    std::cout << '\n';
    std::cout << "Hello" << '\n';
    std::cout << "--------------------------------------" << '\n';

    std::fstream myFile{"tasks.txt", std::ios::out | std::ios::in};

    // check if the file exists
    if (!myFile.is_open()) { 
        std::cout << "i needa make your file for you" << '\n';

        // make new "tasks.txt" file
        std::ofstream tempFile{"tasks.txt"};
        tempFile << "eat poop" << '\n';
        tempFile.close();
        myFile.open("tasks.txt", std::ios::in | std::ios::out);                

        std::cout << "here you go" << '\n';
        std::cout << "here's whatcha gotta do:" << "\n\n";
    }
    else { 
        // this is if the file exists
        std::cout << "This is what you should be doing:" << '\n';
    }

    // print out tasks
    int counter{1};
    std::string strTasks{};
    // print out stuff on the file
    while(std::getline(myFile, strTasks)) {
        std::cout << counter << ". " << strTasks << '\n';
        counter++;
    }
    counter = 1;
    std::cout << "--------------------------------------" << '\n';

    // need to make this a while loop until quit
    // or do while

    while (true) {
        std::cout << "is there anything else you need?" << '\n';
        std::cout << "1. add a task" << '\n';
        std::cout << "2. delete a task" << '\n';
        std::cout << "3. see tasks" << '\n';
        std::cout << "4. quit" << std::endl;
        std::cout << "Enter an int: ";

        int nextCommand{};
        int tempCommand{0};
        std::cin >> nextCommand;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (nextCommand == 1) {
            addTask("tasks.txt");
        } 
        else if (nextCommand == 2) {
            deleteTask("tasks.txt");
        }
        else if (nextCommand == 3) {
            seeTasks("tasks.txt");
        }
        else {
            break;
        }
        
    }


    myFile.close();
    std::cout << "--------------------------------------" << '\n';
    std::cout << "Sayonara" << "\n\n";
    return 0;
}

void addTask(std::string fileName) {
    std::fstream myFile{fileName, std::ios::app};
    std::string newTask{""};
    
    // get a new task from user
    std::cout << "new task: ";
    while (newTask.empty()) {
        std::getline(std::cin, newTask);
    }

    // check if needa quit
    if (newTask == "cancel") {
        std::cout << "cancelling" << "\n\n";
        return;
    }

    // add new task to myFile
    myFile << newTask << '\n';
    std::cout << "New task added!" << "\n\n"; 
    std::cout << "--------------------------------------" << std::endl;

    myFile.close();
    return;
}

void deleteTask(std::string fileName) {
    std::cout << "deleting task" << '\n';
}

void seeTasks(std::string fileName) {
    std::cout << "seeing the tasks" << '\n';
}
