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
                std::cout << "Phone: " << customer.phone << "\n\n";
                std::cout << "address: " << customer.address << "\n\n";
            }
        }
    }
};

int main() {
    CRMSystemcrmSystem;

    // Example usage of the CRM System
    crmSystem.addCustomer("Divya", "divya123@gmail.com", "123-456-7890", "123 Main St,NewJersey,USA");
    crmSystem.addCustomer("Ramya", "ramya345@gmail.com", "987-654-3210", "456 Elm St,NewJersey,USA");
    crmSystem.addCustomer("Vijay", "vijay678@gmail.com", "555-123-4567", "789 Oak St, New Jersey,USA");

    crmSystem.displayCustomers();

    return 0;
}