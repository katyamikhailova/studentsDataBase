CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra
GTEST_FLAGS = -lgtest -lgtest_main -pthread

all: student_database student_tests

student_database: main.cpp student.h
	$(CXX) $(CXXFLAGS) main.cpp -o student_database

student_tests: test.cpp student.h
	$(CXX) $(CXXFLAGS) test.cpp -o student_tests $(GTEST_FLAGS)

test: student_tests
	./student_tests

clean:
	rm -f student_database student_tests

.PHONY: all test clean