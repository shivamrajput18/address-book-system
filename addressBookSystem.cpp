#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
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

class AddressBook {
private:
    vector<Contact> contacts;

public:
    void addContact(string fName, string lName, string addr, string cty, string st, int z, long long phone, string mail) {
        contacts.emplace_back(fName, lName, addr, cty, st, z, phone, mail);
        cout << "Contact added successfully.\n";
    }

    Contact* findContact(const string& fName, const string& lName) {
        for (auto& contact : contacts) {
            if (contact.getFirstName() == fName && contact.getLastName() == lName) {
                return &contact;
            }
        }    
        return nullptr;
    }

    void displayAllContacts() const {
        if (contacts.empty()) {
            cout << "Address Book is empty.\n";
            return;
        }
        cout << "\nContacts:\n";
        for (const auto& contact : contacts) {
            contact.displayContact();
            cout << "-----------------------------\n";
        }
    }
};

class AddressBookSystem {
private:
    unordered_map<string, AddressBook> addressBooks;

public:
    void createAddressBook(const string& name) {
        if (addressBooks.find(name) != addressBooks.end()) {
            cout << "Address Book with name '" << name << "' already exists.\n";
        } else {
            addressBooks[name] = AddressBook();
            cout << "Address Book '" << name << "' created successfully.\n";
        }
    }

    AddressBook* getAddressBook(const string& name) {
        if (addressBooks.find(name) != addressBooks.end()) {
            return &addressBooks[name];
        } else {
            cout << "Address Book '" << name << "' does not exist.\n";
            return nullptr;
        }
    }

    void displayAllAddressBooks() const {
        if (addressBooks.empty()) {
            cout << "No Address Books available.\n";
        } else {
            cout << "Available Address Books:\n";
            for (const auto& pair : addressBooks) {
                cout << "- " << pair.first << endl;
            }
        }
    }
};

int main() {
    AddressBookSystem system;
    char choice;

    do {
        cout << "\nAddress Book System Menu:\n";
        cout << "1. Create New Address Book\n";
        cout << "2. Add Contact to Address Book\n";
        cout << "3. Display All Contacts in an Address Book\n";
        cout << "4. Edit Contact in an Address Book\n";
        cout << "5. Display All Address Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                string name;
                cout << "Enter Address Book Name: ";
                cin >> name;
                system.createAddressBook(name);
                break;
            }
            case '2': {
                string name;
                cout << "Enter Address Book Name: ";
                cin >> name;
                AddressBook* book = system.getAddressBook(name);
                if (book) {
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

                    book->addContact(fName, lName, addr, cty, st, z, phone, mail);
                }
                break;
            }
            case '3': {
                string name;
                cout << "Enter Address Book Name: ";
                cin >> name;
                AddressBook* book = system.getAddressBook(name);
                if (book) {
                    book->displayAllContacts();
                }
                break;
            }
            case '4': {
                string name;
                cout << "Enter Address Book Name: ";
                cin >> name;
                AddressBook* book = system.getAddressBook(name);
                if (book) {
                    string fName, lName;
                    cout << "Enter First Name of the Contact: ";
                    cin >> fName;
                    cout << "Enter Last Name of the Contact: ";
                    cin >> lName;

                    Contact* contact = book->findContact(fName, lName);
                    if (contact) {
                        string addr, cty, st, mail;
                        int z;
                        long long phone;

                        cout << "Enter New Address: ";
                        cin.ignore();
                        getline(cin, addr);
                        cout << "Enter New City: ";
                        cin >> cty;
                        cout << "Enter New State: ";
                        cin >> st;
                        cout << "Enter New ZIP Code: ";
                        cin >> z;
                        cout << "Enter New Phone Number: ";
                        cin >> phone;
                        cout << "Enter New Email: ";
                        cin >> mail;

                        contact->editContact(addr, cty, st, z, phone, mail);

                        cout << "Updated Contact Details:\n";
                        contact->displayContact();
                    } else {
                        cout << "Contact not found.\n";
                    }
                }
                break;
            }
            case '5':
                system.displayAllAddressBooks();
                break;
            case '6':
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != '6');

    return 0;
}
