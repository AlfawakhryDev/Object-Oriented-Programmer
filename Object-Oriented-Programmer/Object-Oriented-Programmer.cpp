#include <iostream>
#include <string>

using namespace std;

class Person {
private:
    const int id;
    string firstName;
    string lastName;
    string email;
    string phone;

public:
    // Constructor
    Person(int id, const string& firstName, const string& lastName, const string& email, const string& phone)
        : id(id), firstName(firstName), lastName(lastName), email(email), phone(phone) {}

    // Getter for ID (read-only)
    int getId() const {
        return id;
    }

    // Getter and setter methods for other attributes
    const string& getFirstName() const {
        return firstName;
    }

    void setFirstName(const string& fName) {
        firstName = fName;
    }

    const string& getLastName() const {
        return lastName;
    }

    void setLastName(const string& lName) {
        lastName = lName;
    }

    const string& getEmail() const {
        return email;
    }

    void setEmail(const string& eMail) {
        email = eMail;
    }

    const string& getPhone() const {
        return phone;
    }

    void setPhone(const string& phoneNumber) {
        phone = phoneNumber;
    }

    // Method to send an email
    void sendEmail(const string& subject, const string& body) {
        cout << "Sending email to: " << email << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
    }

    // Method to send an SMS
    void sendSms(const string& message) {
        cout << "Sending SMS to phone " << phone << ": " << message << endl;
    }

    // Method to print person details
    void print() {
        cout << "ID: " << id << endl;
        cout << "First Name: " << firstName << endl;
        cout << "Last Name: " << lastName << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
    }
};

class Employee : public Person {
private:
    string title;
    double salary;
    string department;

public:
    // Constructor for Employee
    Employee(int id, const string& firstName, const string& lastName, const string& email,
        const string& phone, const string& title, double salary, const string& department)
        : Person(id, firstName, lastName, email, phone), title(title), salary(salary), department(department) {}

    // Getter and setter methods for Employee-specific attributes
    const string& getTitle() const {
        return title;
    }

    void setTitle(const string& empTitle) {
        title = empTitle;
    }

    double getSalary() const {
        return salary;
    }

    void setSalary(double empSalary) {
        salary = empSalary;
    }

    const string& getDepartment() const {
        return department;
    }

    void setDepartment(const string& empDepartment) {
        department = empDepartment;
    }

    // Method to print employee details
    void print() {
        Person::print(); // Call the base class's print method
        cout << "Title: " << title << endl;
        cout << "Salary: " << salary << endl;
        cout << "Department: " << department << endl;
    }
};

class Programmer : public Employee {

private:

    string mainProgrammingLanguage;

public:
    // Constructor for Programmer
    Programmer(int id, const string& firstName, const string& lastName, const string& email,const string& phone, const string& title, double salary, const string& department, const string& mainProgrammingLanguage)
        :Employee(id, firstName, lastName, email, phone, title, salary, department),
        mainProgrammingLanguage(mainProgrammingLanguage) {}

    // Getter and setter methods for Programmer-specific attribute
    
    const string& getMainProgrammingLanguage() const
    {
        return mainProgrammingLanguage;
    }

    void setMainProgrammingLanguage(const string& language) {
        mainProgrammingLanguage = language;
    }

    // Method to print programmer details
    void print() {
        Employee::print(); // Call the base class's print method
        cout << "Main Programming Language: " << mainProgrammingLanguage << endl;
    }
};

int main() {
    // Example usage:
    Programmer programmer1(1, "John", "Doe", "john.doe@example.com", "123456789",
        "Software Engineer", 60000.0, "Engineering", "C++");

    // Using base class methods
    programmer1.setPhone("987654321");
    programmer1.sendEmail("Hello", "How are you?");
    programmer1.sendSms("How's it going?");

    // Using Programmer-specific methods
    programmer1.setMainProgrammingLanguage("Python");

    // Calling overridden print method
    programmer1.print();

    return 0;
}