// SPDX-License-Identifier: MIT
pragma solidity >=0.8.0;

contract stud {
    // Struct to represent a Student
    struct Student {
        uint256 prn;    // PRN (Permanent Registration Number)
        string name;
        string class;
        string branch;
    }

    Student[] public students;   // Array to store student records

    // Function to add a new student
    function add_student(string memory name, string memory class, string memory branch) public {
        uint256 prn = students.length + 1;   // Incremental PRN generation
        Student memory ns = Student(prn, name, class, branch);
        students.push(ns);  // Add the new student to the array
    }

    // Function to get the total number of students
    function get_students() public view returns(uint256) {
        return students.length;
    }

    // Function to get details of a specific student based on PRN
    function get_student_details(uint256 prn) public view returns (Student memory) {
        require(prn > 0 && prn <= students.length, 'Enter valid prn');
        return students[prn - 1];
    }

    // Function to update details of a student based on PRN
    function updateStudentDetails(uint256 prn, string memory newName, string memory newClass, string memory newBranch) public {
        require(prn > 0 && prn <= students.length, 'Enter valid PRN');
        
        students[prn - 1].name = newName;
        students[prn - 1].class = newClass;
        students[prn - 1].branch = newBranch;
    }

    // Function to delete a student based on PRN
    function deleteStudent(uint256 prn) public {
        require(prn > 0 && prn <= students.length, 'Enter valid PRN');
        for (uint256 i = prn - 1; i < students.length - 1; i++) {
            students[i].prn = students[i + 1].prn - 1;
            students[i].name = students[i + 1].name;
            students[i].class = students[i + 1].class;
            students[i].branch = students[i + 1].branch;
        }
        students.pop();  // Remove the last element (duplicate of the second-last element)
    }

    // Function to get details of all students
    function getAllStudents() public view returns (Student[] memory) {
        return students;
    }
}
