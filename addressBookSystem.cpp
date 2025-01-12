#include <iostream>
#include <string>
using namespace std;

class Contacts {
private:
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    int zip;
    long long phoneNumber;
    string email;

public:
    Contacts(string fName, string lName, string addr, string cty, string st, int z, long long phone, string mail)
        : firstName(fName), lastName(lName), address(addr), city(cty), state(st), zip(z), phoneNumber(phone), email(mail) {}

    void displayContact() {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Address: " << address << ", " << city << ", " << state << ", " << zip << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

int main() {
    cout << "Welcome to Address Book Program" << endl;

    Contacts* contact1 = new Contacts("John", "Doe", "123 Main St", "New York", "NY", 10001, 1234567890, "john.doe@example.com");
    
    cout << "\nContact Details:\n";
    contact1->displayContact();

    delete contact1;

    return 0;
}
