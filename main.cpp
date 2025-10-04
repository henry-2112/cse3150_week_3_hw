#include <iostream>
#include <cstring>   // for strlen, strcpy
#include <numeric>

// TODO: function prototypes

// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
    if (size >= capacity){
        throw "Maxed capacity!";
    }

    names[size] = name;
    gpas[size] = gpa;

    size++;
}

// TODO: implement updateGPA
void updateGPA(double* gpaPtr, double newGpa){
    *gpaPtr = newGpa;
}

// TODO: implement printStudent
void printStudent(char* name, double gpa){
    std::cout << name << ": " << gpa << std::endl;
}

// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
    double sum = std::accumulate(gpas, gpas + size, 0.0);
    double average; 

    if(size == 0){
        throw "No GPAs found";
    }
    else{
        average = sum / size;
    }
    return static_cast<int>(average);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char* names[capacity];
    double gpas[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                if(size == capacity){
                    std::cout << "List full" << std::endl;
                    break;
                }

                char* name = new char[100];
                double gpa;
                std::cout << "Enter name: " << std::endl;
                std::cin >> name;
                std::cout << "Enter GPA: " << std::endl;
                std::cin >> gpa;
                addStudent(name, gpa, names, gpas, size, capacity);
                break;
            }
            case 2: {
                // TODO: implement menu logic
                double newGpa;
                int index;

                std::cout << "Enter index of GPA you'd like to change: " << std::endl;
                std::cin >> index;
                std::cout << "Enter new GPA: " << std::endl;
                std::cin >> newGpa;

                try{
                    if(index < 0 || index >= size){
                        throw "Invalid index!";
                    }
                    updateGPA(&gpas[index], newGpa);
                } catch (const char* msg){
                    std::cout << msg << std::endl;
                }

                break;
            }
            case 3: {
                // TODO: implement menu logic
                if(size == 0){
                    std::cout << "No students" << std::endl;
                }

                for(int i = 0; i < size; i++){
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                if(size > capacity){
                    std::cout << "List full" << std::endl;
                }
                else if(size == 0){
                    std::cout << "No students" << std::endl;
                }
                else{
                    std::cout << "Average GPA: " << averageGPA(gpas, size) << std::endl;;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for(int i = 0; i < size; ++i){
        delete[] names[i];
    }

    return 0;
}
