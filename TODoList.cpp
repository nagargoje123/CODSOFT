#include <iostream>
#include <vector>
#include <iomanip>

struct Task {
    std::string description;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(std::vector<Task>& taskList);
void viewTasks(const std::vector<Task>& taskList);
void markCompleted(std::vector<Task>& taskList);
void removeTask(std::vector<Task>& taskList);

int main() {
    std::vector<Task> taskList;

    char choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case '1':
                addTask(taskList);
                break;
            case '2':
                viewTasks(taskList);
                break;
            case '3':
                markCompleted(taskList);
                break;
            case '4':
                removeTask(taskList);
                break;
            case '5':
                std::cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

    } while (choice != '5');

    return 0;
}

void displayMenu() {
    std::cout << "\n==== To-Do List Manager ====\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
}

void addTask(std::vector<Task>& taskList) {
    Task newTask;
    std::cin.ignore(); // Clear the input buffer
    std::cout << "Enter task description: ";
    std::getline(std::cin, newTask.description);
    newTask.completed = false;
    taskList.push_back(newTask);
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<Task>& taskList) {
    std::cout << "\n==== Task List ====\n";
    std::cout << std::setw(4) << "ID" << std::setw(20) << "Description" << std::setw(15) << "Status\n";
    std::cout << "-------------------------\n";

    for (size_t i = 0; i < taskList.size(); ++i) {
        std::cout << std::setw(4) << i + 1 << std::setw(20) << taskList[i].description;

        if (taskList[i].completed) {
            std::cout << std::setw(15) << "Completed\n";
        } else {
            std::cout << std::setw(15) << "Pending\n";
        }
    }
}

void markCompleted(std::vector<Task>& taskList) {
    viewTasks(taskList);

    if (!taskList.empty()) {
        int taskId;
        std::cout << "Enter the ID of the task to mark as completed: ";
        std::cin >> taskId;

        if (taskId >= 1 && taskId <= static_cast<int>(taskList.size())) {
            taskList[taskId - 1].completed = true;
            std::cout << "Task marked as completed!\n";
        } else {
            std::cout << "Invalid task ID. Please try again.\n";
        }
    }
}

void removeTask(std::vector<Task>& taskList) {
    viewTasks(taskList);

    if (!taskList.empty()) {
        int taskId;
        std::cout << "Enter the ID of the task to remove: ";
        std::cin >> taskId;

        if (taskId >= 1 && taskId <= static_cast<int>(taskList.size())) {
            taskList.erase(taskList.begin() + taskId - 1);
            std::cout << "Task removed successfully!\n";
        } else {
            std::cout << "Invalid task ID. Please try again.\n";
        }
    }
}
