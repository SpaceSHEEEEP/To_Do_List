#include <iostream>
#include <vector>
#include <fstream>
#include <limits> 

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
        myFile.open("tasks.txt", std::ios::in);                

        std::cout << "here you go" << '\n';
    }

    // print out tasks
    seeTasks("tasks.txt");

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
        std::cout << "--------------------------------------" << std::endl;

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
        std::cout << "cancelling" << "\n";
        return;
    }

    // add new task to myFile
    myFile << newTask << '\n'; // end txt file with new line
    std::cout << "New task added!" << "\n"; 
    std::cout << "--------------------------------------" << std::endl;

    myFile.close();
    return;
}

void deleteTask(std::string fileName) {
    std::ifstream readFile{fileName};
    char readChar{};

    // find how many tasks there are 
    int numOfTasks{0};
    
    while(readFile.good()) { 
        readChar = static_cast<char>(readFile.get());

        if (readChar == '\n') {
            numOfTasks++;
        }
    }

    // get which task to delete
    int deleteIndex{};
    while (true) {
        std::cout << "Enter task number to be deleted: ";
        std::cin >> deleteIndex;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (deleteIndex <= numOfTasks) {break;}
    }

    // i think ill just rewrite the file. its simpler
    std::string myStr{};
    readFile.clear();
    readFile.seekg(0);

    // rewrite file
    std::ofstream writeFile{"newTasks.txt"};
    std::string line{};
    for (int i{1}; i <= numOfTasks; i++) {
        getline(readFile, line);
        if (i == deleteIndex) {continue;}
        writeFile << line << '\n';
    }
    
    std::cout << "Deleted!" << '\n';
    
    // delete old tasks.txt file
    readFile.close();
    remove("tasks.txt");

    // rename newTasks.txt to tasks.txt
    rename("newTasks.txt", "tasks.txt");
    writeFile.close();
}

void seeTasks(std::string fileName) {
    std::fstream myFile{fileName, std::ios::in};
    int counter{1};
    std::string strTasks{};
    
    // print out stuff on the file
    std::cout << "This is what you should be doing:" << '\n';
    while(std::getline(myFile, strTasks)) {
        std::cout << "  " << counter << ". " << strTasks << '\n';
        counter++;
    }

    std::cout << "--------------------------------------" << std::endl;
    myFile.close();
}
