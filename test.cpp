#include "student.h"
#include <gtest/gtest.h>
#include <vector>

// Тест 1: Оператор сравнения студентов
TEST(StudentTest, EqualityOperator) {
    Student s1 = {"Ivan", 20, "CS", 4.5};
    Student s2 = {"Ivan", 20, "CS", 4.5};
    Student s3 = {"Maria", 21, "Math", 4.8};
    
    EXPECT_TRUE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
}

// Тест 2: Разные студенты не равны
TEST(StudentTest, DifferentStudentsNotEqual) {
    Student s1 = {"Ivan", 20, "CS", 4.5};
    Student s2 = {"Ivan", 21, "CS", 4.5};
    Student s3 = {"Ivan", 20, "Math", 4.5};
    Student s4 = {"Ivan", 20, "CS", 4.0};
    
    EXPECT_FALSE(s1 == s2);
    EXPECT_FALSE(s1 == s3);
    EXPECT_FALSE(s1 == s4);
}

// Тест 3: Поиск дубликатов в пустой базе
TEST(DuplicateTest, EmptyDatabase) {
    std::vector<Student> empty_db;
    auto duplicates = findDuplicates(empty_db);
    EXPECT_TRUE(duplicates.empty());
}

// Тест 4: Поиск дубликатов с одним дубликатом
TEST(DuplicateTest, SingleDuplicate) {
    std::vector<Student> db = {
        {"Ivan", 20, "CS", 4.5},
        {"Maria", 21, "Math", 4.8},
        {"Ivan", 20, "CS", 4.5}
    };
    
    auto duplicates = findDuplicates(db);
    ASSERT_EQ(duplicates.size(), 1);
    EXPECT_TRUE(duplicates[0] == Student{"Ivan", 20, "CS", 4.5});
}

// Тест 5: Поиск множественных дубликатов
TEST(DuplicateTest, MultipleDuplicates) {
    std::vector<Student> db = {
        {"Ivan", 20, "CS", 4.5},
        {"Maria", 21, "Math", 4.8},
        {"Ivan", 20, "CS", 4.5},
        {"Maria", 21, "Math", 4.8},
        {"Petr", 22, "Physics", 3.9}
    };
    
    auto duplicates = findDuplicates(db);
    EXPECT_EQ(duplicates.size(), 2);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}