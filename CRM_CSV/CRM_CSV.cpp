#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

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

    // Function to save customers to a CSV file
    void saveCustomersToCSV(const std::string& filename) const {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << " for writing.\n";
            return;
        }

        for (const auto& customer : customers) {
            file << customer.name << "," << customer.email << "," << customer.phone << "," << customer.address << "\n";
        }

        file.close();
        std::cout << "Customer data saved to " << filename << ".\n";
    }

    // Function to load customers from a CSV file
    void loadCustomersFromCSV(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Unable to open file " << filename << " for reading.\n";
            return;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string name, email, phone, address;
            if (std::getline(iss, name, ',') && std::getline(iss, email, ',') &&
                std::getline(iss, phone, ',') && std::getline(iss, address, ',')) {
                addCustomer(name, email, phone, address);
            }
            else {
                std::cerr << "Error: Invalid line format in CSV file.\n";
            }
        }

        file.close();
        std::cout << "Customer data loaded from " << filename << ".\n";
    }
};

int main() {
    CRMSystem crmSystem;

    // Load existing customer data from CSV file
    crmSystem.loadCustomersFromCSV("customers.csv");

    // Prompt user to add customers
    std::string name, email, phone, address;
    char addMore;
    do {
        std::cout << "Enter customer details:\n";
        std::cout << "Name: ";
        std::getline(std::cin, name);
        std::cout << "Email: ";
        std::getline(std::cin, email);
        std::cout << "Phone: ";
        std::getline(std::cin, phone);
        std::cout << "Address: ";
        std::getline(std::cin, address);

        crmSystem.addCustomer(name, email, phone, address);

        std::cout << "Do you want to add another customer? (y/n): ";
        std::cin >> addMore;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    } while (addMore == 'y' || addMore == 'Y');

    // Save customer data to CSV file
    crmSystem.saveCustomersToCSV("customers.csv");

    // Display all customers
    crmSystem.displayCustomers();

    return 0;
}