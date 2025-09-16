#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <vector>

struct Student {
    std::string name;
    int age;
    std::string major;
    double gpa;

    // Оператор сравнения для всех полей
    bool operator==(const Student& other) const {
        return name == other.name && 
               age == other.age && 
               major == other.major && 
               gpa == other.gpa;
    }
};

// Функция для добавления студента
void addStudent(std::vector<Student>& database);

// Функция для вывода всех студентов
void displayStudents(const std::vector<Student>& database);

// Функция поиска дубликатов
std::vector<Student> findDuplicates(const std::vector<Student>& database);

#endif