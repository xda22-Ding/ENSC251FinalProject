#compile and link the application
all: main

#run the application
run: main
	./main

#link main.o, student.o, and student_list.o to executable main
main: main.o student.o student_list.o 
	g++ -g -o main main.o student.o student_list.o

#compile the main.cpp to main.o
main.o: main.cpp student.hpp student_list.hpp
	g++ -g -c main.cpp

#compile the student.cpp to student.o
student.o: student.cpp student.hpp
	g++ -g -c student.cpp

#compile the student_list.cpp to student_list.o
student_list.o: student_list.cpp student_list.hpp
	g++ -g -c student_list.cpp

#remove built files
clean:
	rm -rf main main.o student.o student_list.o *~
