#include <iostream>
#include <vector>
#include <string>

// Customer structure
struct Customer {
    std::string name;
    std::string email;
    std::string phone;
    std::string address;
};

// CRM System class
class CRMSystem {
private:
    std::vector<Customer> customers;

public:
    // Function to add a new customer
    void addCustomer(const std::string& name, const std::string& email, const std::string& phone, const std::string& address) {
        Customer newCustomer;
        newCustomer.name = name;
        newCustomer.email = email;
        newCustomer.phone = phone;
        newCustomer.address = address;
        customers.push_back(newCustomer);

        std::cout << "Customer added successfully.\n";
    }

    // Function to display all customers
    void displayCustomers() const {
        if (customers.empty()) {
            std::cout << "No customers found.\n";
        }
        else {
            std::cout << "All Customers:\n";
            for (const auto& customer : customers) {
                std::cout << "Name: " << customer.name << "\n";
                std::cout << "Email: " << customer.email << "\n";
                std::cout << "Phone: " << customer.phone << "\n";
                std::cout << "Address: " << customer.address << "\n\n";
            }
        }
    }
};

int main() {
    CRMSystem crmSystem;

    // Prompt user to add customers
    std::string name, email, phone, address;
    char addMore;
    do {
        std::cout << "Enter customer details:\n";
        std::cout << "Name: ";
        std::cin >> name;
        std::cout << "Email: ";
        std::cin >> email;
        std::cout << "Phone: ";
        std::cin >> phone;
        std::cout << "Address: ";
        std::cin.ignore(); // Ignore newline character
        std::getline(std::cin, address);

        crmSystem.addCustomer(name, email, phone, address);

        std::cout << "Do you want to add another customer? (y/n): ";
        std::cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    // Display all customers
    crmSystem.displayCustomers();

    return 0;
}
