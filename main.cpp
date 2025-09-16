#include "student.h"
#include <vector>
#include <iostream>

// Функция для добавления студента в базу данных
void addStudent(std::vector<Student>& database) {
    Student student;
    std::cout << "Введите имя студента: ";
    std::cin >> student.name;
    std::cout << "Введите возраст студента: ";
    std::cin >> student.age;
    std::cout << "Введите специальность студента: ";
    std::cin >> student.major;
    std::cout << "Введите средний балл студента: ";
    std::cin >> student.gpa;

    database.push_back(student);
    std::cout << "Студент добавлен в базу данных.\n";
}

// Функция для вывода всех студентов из базы данных
void displayStudents(const std::vector<Student>& database) {
    if (database.empty()) {
        std::cout << "База данных пуста.\n";
        return;
    }
    
    std::cout << "Список студентов:\n";
    for (size_t i = 0; i < database.size(); ++i) {
        std::cout << "Студент #" << i + 1 << ":\n";
        std::cout << "Имя: " << database[i].name << "\n";
        std::cout << "Возраст: " << database[i].age << "\n";
        std::cout << "Специальность: " << database[i].major << "\n";
        std::cout << "Средний балл: " << database[i].gpa << "\n\n";
    }
}

// Функция поиска дубликатов
std::vector<Student> findDuplicates(const std::vector<Student>& database) {
    std::vector<Student> duplicates;
    
    if (database.size() < 2) {
        return duplicates;
    }
    
    // Поиск дубликатов
    for (size_t i = 0; i < database.size(); ++i) {
        for (size_t j = i + 1; j < database.size(); ++j) {
            if (database[i] == database[j]) {
                // Проверяем, нет ли уже этого дубликата
                bool exists = false;
                for (const auto& dup : duplicates) {
                    if (dup == database[i]) {
                        exists = true;
                        break;
                    }
                }
                
                if (!exists) {
                    duplicates.push_back(database[i]);
                }
            }
        }
    }
    
    return duplicates;
}

int main() {
    std::vector<Student> database;

    int choice;
    do {
        std::cout << "Меню:\n";
        std::cout << "1. Добавить студента\n";
        std::cout << "2. Вывести список студентов\n";
        std::cout << "3. Найти дубликаты студентов\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent(database);
                break;
            case 2:
                displayStudents(database);
                break;
            case 3: {
                auto duplicates = findDuplicates(database);
                if (duplicates.empty()) {
                    std::cout << "Дубликатов не найдено.\n";
                } else {
                    std::cout << "Найдены дубликаты (" << duplicates.size() << "):\n";
                    displayStudents(duplicates);
                }
                break;
            }
            case 0:
                std::cout << "Выход из программы.\n";
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
        }
    } while (choice != 0);

    return 0;
}