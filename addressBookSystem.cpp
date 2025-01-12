#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Contact {
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
    Contact(string fName, string lName, string addr, string cty, string st, int z, long long phone, string mail)
        : firstName(fName), lastName(lName), address(addr), city(cty), state(st), zip(z), phoneNumber(phone), email(mail) {}

    void displayContact() const {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Address: " << address << ", " << city << ", " << state << ", " << zip << endl;
        cout << "Phone Number: " << phoneNumber << endl;
        cout << "Email: " << email << endl;
    }
};

class AddressBook {
private:
    vector<Contact> contacts; 

public:
    void addContact(string fName, string lName, string addr, string cty, string st, int z, long long phone, string mail) {
        Contact newContact(fName, lName, addr, cty, st, z, phone, mail); 
        contacts.push_back(newContact); 
        cout << "Contact added successfully.\n";
    }

    void displayAllContacts() const {
        if (contacts.empty()) {
            cout << "Address Book is empty.\n";
            return;
        }

        cout << "\nAddress Book Contacts:\n";
        for (const auto& contact : contacts) {
            contact.displayContact();
            cout << "-----------------------------\n";
        }
    }
};

int main() {
    cout << "Welcome to Address Book Program\n";

    AddressBook* addressBook = new AddressBook();
    char addMore = 'y';

    while (addMore == 'y' || addMore == 'Y') {
        string fName, lName, addr, cty, st, mail;
        int z;
        long long phone;

        cout << "Enter First Name: ";
        cin >> fName;
        cout << "Enter Last Name: ";
        cin >> lName;
        cout << "Enter Address: ";
        cin.ignore(); 
        getline(cin, addr);
        cout << "Enter City: ";
        cin >> cty;
        cout << "Enter State: ";
        cin >> st;
        cout << "Enter ZIP Code: ";
        cin >> z;
        cout << "Enter Phone Number: ";
        cin >> phone;
        cout << "Enter Email: ";
        cin >> mail;

        addressBook->addContact(fName, lName, addr, cty, st, z, phone, mail);

        cout << "Do you want to add another contact? (y/n): ";
        cin >> addMore;
    }

    cout << "\nNow displaying all contacts in the Address Book:\n";
    addressBook->displayAllContacts();

    delete addressBook;

    return 0;
}
