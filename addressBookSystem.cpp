#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
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

    string getFullName() const {
        return firstName + " " + lastName;
    }

    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }

    void editContact(string addr, string cty, string st, int z, long long phone, string mail) {
        address = addr;
        city = cty;
        state = st;
        zip = z;
        phoneNumber = phone;
        email = mail;
        cout << "Contact updated successfully.\n";
    }
};

string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return (first == string::npos || last == string::npos) ? "" : str.substr(first, last - first + 1);
}

string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

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

    void editContact(string name) {
        name = trim(name);  
        name = toLowerCase(name); 

        bool found = false;
        for (auto& contact : contacts) {
            string fullName = contact.getFullName();
            string firstName = contact.getFirstName();
            string lastName = contact.getLastName();

            string fullNameLower = toLowerCase(fullName);
            string firstNameLower = toLowerCase(firstName);
            string lastNameLower = toLowerCase(lastName);

            if (fullNameLower.find(name) != string::npos || firstNameLower.find(name) != string::npos || lastNameLower.find(name) != string::npos) {
                cout << "Found contact: " << fullName << endl;
                string addr, cty, st, mail;
                int z;
                long long phone;

                cout << "Enter new details for " << fullName << ":\n";
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

                contact.editContact(addr, cty, st, z, phone, mail);
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Contact with name " << name << " not found.\n";
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
        cin.ignore(); 
    }

    cout << "\nNow displaying all contacts in the Address Book:\n";
    addressBook->displayAllContacts();

    char editMore = 'y';
    while (editMore == 'y' || editMore == 'Y') {
        string name;
        cout << "\nEnter the full name of the contact to edit (First Last), or just First or Last name: ";
        cin.ignore();  
        getline(cin, name);

        addressBook->editContact(name); 

        cout << "Do you want to edit another contact? (y/n): ";
        cin >> editMore;
        cin.ignore(); 
    }

    delete addressBook;

    return 0;
}
