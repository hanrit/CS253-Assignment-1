#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <limits>
#include <sstream> 
#include <iomanip>





class Car {
public:
    Car() : model(""), price(0.0), condition(""), otherDetails(""), rentaldays(0) {}
    Car(const std::string& model, float price, const std::string& condition, const std::string& otherDetails, int rentaldays)
        : model(model), price(price), condition(condition), otherDetails(otherDetails), rentaldays(0) {}
        
        int getrentaldays() const { return rentaldays; }
    void setrentaldays(int days) { rentaldays = days; }

    std::string getModel() const { return model; }
    float getPrice() const { return price; }
    std::string getCondition() const { return condition; }
    std::string getOtherDetails() const { return otherDetails; }
    bool isAvailable() const { return available; }
    void setAvailability(bool avail) { available = avail; }
    void setModel(const std::string& newModel) {
        model = newModel;
    }

    void setPrice(float newPrice) {
        price = newPrice;
    }

    void setCondition(const std::string& newCondition) {
        condition = newCondition;
    }
    int getRentalDays() const {
        return rentaldays;
    }

    bool getAvailability() const {
        return available;
    }

    std::string getRentedTo() const {
        return rentedTo;
    }
    
    void setRentedTo(const std::string& rentedTo) {
        this->rentedTo = rentedTo;
    }
    

private:
    float price;
    mutable bool available; // Marked as mutable
    int rentaldays;
    std::string plateNumber;
    std::string model;
    std::string condition;
    std::string otherDetails;
    int rentalDays;
    std::string rentedTo;
};

class Customer {
public:
    Customer() : id(""), fineDue(0.0), customerRecord(100) {}
    Customer(const std::string& id, const std::vector<std::string>& rentedCars, float fineDue, int customerRecord)
        : id(id), rentedCars(rentedCars), fineDue(fineDue), customerRecord(customerRecord) {}

    std::string getId() const { return id; }
    std::vector<std::string> getRentedCars() const { return rentedCars; }
    float getFineDue() const { return fineDue; }
    int getCustomerRecord() const { return customerRecord; }
    void setId(const std::string& newId) {
        id = newId;
    }
    void setFineDue(double newFineDue) {
        fineDue = newFineDue;
    }
    
    void addRentedCar(const std::string& carId) {
        rentedCars.push_back(carId);
    }
    
    void addToFineDue(float amount) {
        fineDue += amount;
    }
    
    void decreaseScore(int value) {
        customerRecord -= value;
    }

    // Function to remove a rented car
    void removeRentedCar(const std::string& carId) {
        auto it = std::find(rentedCars.begin(), rentedCars.end(), carId);
        if (it != rentedCars.end()) {
            rentedCars.erase(it);
        }
    }

    // Function to display all available cars
void displayAllAvailableCars(const std::unordered_map<std::string, Car>& cars) const {
    std::cout  << "\nAll Available Cars:" <<  std::endl;
    // Definining an array of designs
std::vector<std::string> carDesigns = {
     "__\n"
    ".-'--`-._\n"
    "'-O---O--'",
    " __\n"
    ".-'--`-._\n"
    "'-O---O--'",
    "    ____\n"
    " __/  |_\\_\n"
    "|  _     _``-.\n"
    "'-(_)---(_)--'"
};
int designIndex = 0; // Index to keep track of the current design

for (const auto& pair : cars) {
    const Car& car = pair.second;
    
    // Printing the current design
    std::cout << "Design:\n" << carDesigns[designIndex] << std::endl;
    
    // Increment the design index and reset to 0 if it exceeds the number of designs
    designIndex = (designIndex + 1) % carDesigns.size();

    // Print car details
    std::cout << "Name: " << car.getOtherDetails() << std::endl;
    std::cout << "Model: " << car.getModel() << std::endl;
    std::cout << "Price: " << car.getPrice() << std::endl;
    std::cout << "Condition: " << car.getCondition() << std::endl;
    std::cout << "Availability: " << (car.isAvailable() ? "Available" : "Not Available") << std::endl;
    std::cout << std::endl;
} 

}

    

    // Function to display rented cars
  void displayRentedCars(const std::unordered_map<std::string, Car>& cars) const {
    std::cout << "\nYour Rented Cars:" << std::endl;
    for (const auto& carId : rentedCars) {
        auto it = cars.find(carId);
        if (it != cars.end()) {
            const Car& car = it->second;
            std::cout << "Name: " << car.getOtherDetails() << std::endl; 
            std::cout << "Model: " << car.getModel() << std::endl;
            std::cout << "Rented for: " << car.getrentaldays() << std::endl;

            std::cout << "Condition: " << car.getCondition() << std::endl;
            std::cout << std::endl;
        } else {
            std::cerr << "Error: Car with ID " << carId << " not found." << std::endl;
        }
    }
}



    const std::string& getPassword() const {
        return password;
    }




private:
    std::string id;
    std::vector<std::string> rentedCars;
    float fineDue;
    int customerRecord;
    std::unordered_map<std::string, Car> cars;
        std::string password;

};

class Employee {
public:
    Employee() : id(""), fineDue(0.0), employeeRecord(100) {}
    Employee(const std::string& id, const std::vector<std::string>& rentedCars, float fineDue, int employeeRecord)
        : id(id), rentedCars(rentedCars), fineDue(fineDue), employeeRecord(employeeRecord) {}

    std::string getId() const { return id; }
    std::vector<std::string> getRentedCars() const { return rentedCars; }
    float getFineDue() const { return fineDue; }
    int getEmployeeRecord() const { return employeeRecord; }
     void setId(const std::string& newId) {
        id = newId;
    }
    void setFineDue(double newFineDue) {
        fineDue = newFineDue;
    }

    void addRentedCar(const std::string& carId) {
        rentedCars.push_back(carId);
    }

    void addToFineDue(float amount) {
        fineDue += amount;
    }

    void decreaseScore(int value) {
        employeeRecord -= value;
    }

    void removeRentedCar(const std::string& carId) {
        auto it = std::find(rentedCars.begin(), rentedCars.end(), carId);
        if (it != rentedCars.end()) {
            rentedCars.erase(it);
        }
    }

    void displayAllAvailableCars(const std::unordered_map<std::string, Car>& cars) const {
    std::cout << "\nAll Available Cars:" << std::endl;
    // Define an array of designs
std::vector<std::string> carDesigns = {
     "__\n"
    ".-'--`-._\n"
    "'-O---O--'",
    " __\n"
    ".-'--`-._\n"
    "'-O---O--'",
    "    ____\n"
    " __/  |_\\_\n"
    "|  _     _``-.\n"
    "'-(_)---(_)--'"
};

int designIndex = 0; // Index to keep track of the current design

for (const auto& pair : cars) {
    const Car& car = pair.second;
    
    // Print the current design
    std::cout << "Design:\n" << carDesigns[designIndex] << std::endl;
    
    // Increment the design index and reset to 0 if it exceeds the number of designs
    designIndex = (designIndex + 1) % carDesigns.size();

    // Print car details
    std::cout << "Name: " << car.getOtherDetails() << std::endl;
    std::cout << "Model: " << car.getModel() << std::endl;
    std::cout << "Price: " << car.getPrice() << std::endl;
    std::cout << "Condition: " << car.getCondition() << std::endl;
    std::cout << "Availability: " << (car.isAvailable() ? "Available" : "Not Available") << std::endl;
    std::cout << std::endl;
} 

}


    
    
   void rentOutCar(const std::string& carModel, std::unordered_map<std::string, Car>& cars) {
    auto it = std::find_if(cars.begin(), cars.end(), [&](const auto& pair) {
        return pair.second.getModel() == carModel && pair.second.isAvailable();
    });

    if (it != cars.end() && it->second.isAvailable()) {
        rentedCars.push_back(it->first);
        it->second.setAvailability(false);
        std::cout << "Car rented out successfully!" << std::endl;
    } else {
        std::cout << "Car not found or unavailable for rent." << std::endl;
    }
}


    void displayRentedCars(const std::unordered_map<std::string, Car>& cars) const {
    std::cout << "\nYour Rented Cars:" << std::endl;
    for (const auto& carId : rentedCars) {
        auto it = cars.find(carId);
        if (it != cars.end()) {
            const Car& car = it->second;
            std::cout << "Name: " << car.getOtherDetails() << std::endl; 
            std::cout << "Model: " << car.getModel() << std::endl;
            std::cout << "Rented for: " << car.getrentaldays() << std::endl;
            std::cout << "Condition: " << car.getCondition() << std::endl;
            std::cout << std::endl;
        } else {
            std::cerr << "Error: Car with ID " << carId << " not found." << std::endl;
        }
    }
}


const std::string& getPassword() const {
        return password;
    }

private:
    std::string id;
    std::vector<std::string> rentedCars;
    float fineDue;
    int employeeRecord;
    std::unordered_map<std::string, Car> cars;
    std::string password;

};

class Manager {
public:
    Manager(const std::string& id, const std::string& password) : id(id), password(password) {}

    std::string getId() const { return id; }
    std::string getPassword() const { return password; }

    

    void addcustomer(std::unordered_map<std::string, std::string>& customerCredentials, std::unordered_map<std::string, Customer>& customers) {
        
        std::string username, password;
        std::cout << "Enter username for the new  customer: ";
        std::cin >> username;
        std::cout << "Enter password for the new customer: ";
    
        std::cin >> password;

        // To Check if the username already exists
        if (customerCredentials.find(username) == customerCredentials.end()) {
            // To Add the new customer credentials
            customerCredentials[username] = password;
            // To Create a new customer object and add it to the customers map
            customers.emplace(username, Customer("ID0" + std::to_string(customers.size() + 1), {}, 0.0, 100));
            std::cout << "CUSTOMER added successfully!" << std::endl;
        } else {
            std::cout << "Username already exists. Please choose a different username." << std::endl;
        }
        
    }


    void updateCustomer(std::unordered_map<std::string, std::string>& customerCredentials, std::unordered_map<std::string, Customer>& customers) {
    std::string usernameToUpdate;
    std::cout << "Enter the username of the customer you want to update: ";
    std::cin >> usernameToUpdate;

    auto it = customers.find(usernameToUpdate);
    if (it != customers.end()) {
        std::string newUsername;
        std::cout << "Enter the new username for customer " << usernameToUpdate << ": ";
        std::cin >> newUsername;

        if (customerCredentials.find(usernameToUpdate) != customerCredentials.end()) {
            customerCredentials[newUsername] = customerCredentials[usernameToUpdate];
            customerCredentials.erase(usernameToUpdate);
        }

customers[newUsername] = customers[usernameToUpdate];
        customers.erase(usernameToUpdate);
        std::cout << "Username updated successfully for customer " << newUsername << std::endl;
        
        double newPaymentDues;
        std::cout << "Enter the new payment dues for the customer: ";
        std::cin >> newPaymentDues;

        // To Update the payment dues
        it->second.setFineDue(newPaymentDues);

        std::cout << "Customer Dues updated successfully." << std::endl;
    } else {
        std::cout << "Customer not found." << std::endl;
    }
}



    void deleteCustomer(std::unordered_map<std::string, std::string>& customerCredentials, std::unordered_map<std::string, Customer>& customers) {
    std::string usernameToDelete;
    std::cout << "Enter the username of the customer you want to delete: ";
    std::cin >> usernameToDelete;

    auto it = customers.find(usernameToDelete);
    if (it != customers.end()) {
        // To Delete the customer's username and corresponding credentials
        customerCredentials.erase(usernameToDelete);
        customers.erase(usernameToDelete);
        std::cout << "Customer " << usernameToDelete << " deleted successfully." << std::endl;
    } else {
        std::cout << "Customer not found." << std::endl;
    }
}


    // Functions to manage employees
    void addEmployee(std::unordered_map<std::string, std::string>& employeeCredentials, std::unordered_map<std::string, Employee>& employees) {
        
        std::string username, password;
        std::cout << "Enter username for the new  EMPLOYEE: ";
        std::cin >> username;
        std::cout << "Enter password for the new EMPLOYEE: ";
    
        std::cin >> password;

        // To Check if the username already exists
        if (employeeCredentials.find(username) == employeeCredentials.end()) {
            // To Add the new customer credentials
            employeeCredentials[username] = password;
            // To Create a new customer object and add it to the customers map
            employees.emplace(username, Employee("ID0" + std::to_string(employees.size() + 1), {}, 0.0, 100));
            std::cout << "EMPLOYEE added successfully!" << std::endl;
        } else {
            std::cout << "Username already exists. Please choose a different username." << std::endl;
        }
        
    }

    void updateEmployee(std::unordered_map<std::string, std::string>& employeeCredentials, std::unordered_map<std::string, Employee>& employees) {
    std::string usernameToUpdate;
    std::cout << "Enter the username of the employee you want to update: ";
    std::cin >> usernameToUpdate;

    auto it = employees.find(usernameToUpdate);
    if (it != employees.end()) {
        std::string newUsername;
        std::cout << "Enter the new username for employee " << usernameToUpdate << ": ";
        std::cin >> newUsername;

        // To Update the username in employee credentials
        if (employeeCredentials.find(usernameToUpdate) != employeeCredentials.end()) {
            employeeCredentials[newUsername] = employeeCredentials[usernameToUpdate];
            employeeCredentials.erase(usernameToUpdate);
        }

        // To Update the employee's username
        employees[newUsername] = employees[usernameToUpdate];
        employees.erase(usernameToUpdate);
        std::cout << "Username updated successfully for employee " << newUsername << std::endl;
        
        // To Update payment dues if applicable 
        double newPaymentDues;
        std::cout << "Enter the new payment dues for the employee: ";
        std::cin >> newPaymentDues;

        // To Update the payment dues
        it->second.setFineDue(newPaymentDues);

        std::cout << "Employee Dues updated successfully." << std::endl;
    } else {
        std::cout << "Employee not found." << std::endl;
    }
}


    void deleteEmployee(std::unordered_map<std::string, std::string>& employeeCredentials, std::unordered_map<std::string, Employee>& employees) {
    std::string usernameToDelete;
    std::cout << "Enter the username of the employee you want to delete: ";
    std::cin >> usernameToDelete;

    auto it = employees.find(usernameToDelete);
    if (it != employees.end()) {
        employeeCredentials.erase(usernameToDelete);
        employees.erase(usernameToDelete);
        std::cout << "Employee " << usernameToDelete << " deleted successfully." << std::endl;
    } else {
        std::cout << "Employee not found." << std::endl;
    }
}


    // Functions to manage cars
    void addCar(std::unordered_map<std::string, Car>& cars) {
    std::string plateNumber;
    std::cout << "Enter the plate number of the car: ";
    std::cin >> plateNumber;

    // Check if the car already exists
    if (cars.find(plateNumber) != cars.end()) {
        std::cout << "Car with plate number " << plateNumber << " already exists." << std::endl;
        return;
    }

    // If the car doesn't exist, create a new car object
    std::string model;
    std::string name;
    double price;
    int rentaldays=0;
    std::string condition;
    std::cout << "Enter the name of the car: ";
    std::cin >> name;
    std::cout << "Enter the model of the car: ";
    std::cin >> model;
    std::cout << "Enter the price of the car: ";
    std::cin >> price;
    std::cout << "Enter the condition of the car: ";
    std::cin >> condition;

    // Create a new Car object and add it to the cars map
    cars.emplace(plateNumber, Car(model, price, condition,name,rentaldays));

    std::cout << "Car with plate number " << plateNumber << " added successfully." << std::endl;
}

    void updateCar(std::unordered_map<std::string, Car>& cars) {
    std::string plateNumber;
    std::cout << "Enter the plate number of the car you want to update: ";
    std::cin >> plateNumber;

    auto it = cars.find(plateNumber);
    if (it != cars.end()) {
        std::string newModel;
        std::cout << "Enter the new model for car " << plateNumber << ": ";
        std::cin >> newModel;

        float newPrice;
        std::cout << "Enter the new price for car " << plateNumber << ": ";
        std::cin >> newPrice;

        std::string newCondition;
        std::cout << "Enter the new condition for car " << plateNumber << ": ";
        std::cin >> newCondition;

        // Update the car's details
        it->second.setModel(newModel);
        it->second.setPrice(newPrice);
        it->second.setCondition(newCondition);

        std::cout << "Car details updated successfully." << std::endl;
    } else {
        std::cout << "Car not found." << std::endl;
    }
}




    void deleteCar(std::unordered_map<std::string, Car>& cars) {
    std::string plateNumberToDelete;
    std::cout << "Enter the plate number of the car you want to delete: ";
    std::cin >> plateNumberToDelete;

    auto it = cars.find(plateNumberToDelete);
    if (it != cars.end()) {
        cars.erase(it);
        std::cout << "Car with plate number " << plateNumberToDelete << " has been deleted." << std::endl;
    } else {
        std::cout << "Car with plate number " << plateNumberToDelete << " not found." << std::endl;
    }
}


    // Function to display all cars and their details
   void viewAllCars(const std::unordered_map<std::string, Car>& cars) {
    if (cars.empty()) {
        std::cout << "No cars available." << std::endl;
        return;
    }

    std::cout << "List of all cars:" << std::endl;
     std::cout << std::setw(15) << "Plate Number" << std::setw(15) << "Model" << std::setw(10) << "Price" << std::setw(15) << "Condition" << std::setw(20) << "Other Details" << std::setw(12) << "Rental Days" << std::setw(15) << "Availability" << std::setw(15) << "Rented to" << std::endl;
    std::cout << std::setw(15) << "------------" << std::setw(15) << "-----" << std::setw(10) << "-----" << std::setw(15) << "---------" << std::setw(20) << "-------------" << std::setw(12) << "------------" << std::setw(15) << "------------" << std::setw(15) << "---------" << std::endl;
    
    for (const auto& pair : cars) {
        const Car& car = pair.second;
        std::cout << std::setw(15) << pair.first << std::setw(15) << car.getModel() << std::setw(10) << car.getPrice() << std::setw(15) << car.getCondition() << std::setw(20) << car.getOtherDetails() << std::setw(12) << car.getRentalDays() << std::setw(15) << (car.getAvailability() ? "Available" : "Not Available") << std::setw(15) << (car.getRentedTo() == "" ? "Not rented" : car.getRentedTo()) << std::endl;
    }
}


    // Function to display rented cars and their details
    void displayRentedCars() const {
        std::cout << "Rented Cars:" << std::endl;
        for (const auto& pair : rentedCars) {
            std::cout << "Car ID: " << pair.first << std::endl;
            std::cout << "Model: " << cars.at(pair.first).getModel() << std::endl;
            std::cout << "Rented to: " << pair.second << std::endl;
            std::cout << std::endl;
        }
    }
    
     void managerCustomerRegister(const std::unordered_map<std::string, std::string>& customerCredentials, 
                                 const std::string& username, const std::string& password);



private:
    std::string id;
    std::string password;
    std::unordered_map<std::string, Customer> customers;
    std::unordered_map<std::string, Employee> employees;
    std::unordered_map<std::string, Car> cars;
    std::unordered_map<std::string, std::string> rentedCars; // Car ID -> Customer ID
};



// Functions for login for each type of user


void customerLogin(const std::unordered_map<std::string, std::string>& credentials, std::unordered_map<std::string, Customer>& customers, std::unordered_map<std::string, Car>& cars) {
    std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    // Check if the username exists and if the password matches
    if (credentials.find(username) != credentials.end() && credentials.at(username) == password) {
                std::cout << std::endl;

        std::cout << "Login successful!" << std::endl;

        // If login successful, you can retrieve the customer details from the customers map
        Customer& customer = customers.at(username);
        std::cout << "Welcome, " ; 

        std::cout << username << "!" << std::endl;
                std::cout << std::endl;

        std::cout << "Your ID: " << customer.getId() << std::endl;
        std::cout << "Payment due: " << customer.getFineDue() << std::endl;
        std::cout << "Score: " << customer.getCustomerRecord() << std::endl;

        int choice;
        
        do {
                std::cout << "\nCustomer Actions:" << std::endl;
                std::cout << "1. Browse and Rent Cars" << std::endl;
                std::cout << "2. View and Return Rented Cars" << std::endl;
                std::cout << "3. Show Payment Due" << std::endl;
                std::cout << "4. Log Out" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> choice;

            switch (choice) {
                case 1: {
                    // Call function to display all available cars
                    customer.displayAllAvailableCars(cars);
                    char rentChoice;
                    std::cout << "Do you want to rent a car? (y/n): ";
                    std::cin >> rentChoice;
            
                    if (rentChoice == 'y' || rentChoice == 'Y') {
                        std::string carToRent;
                        std::cout << "Enter the model of the car you want to rent: ";
                        std::cin.ignore(); // Clear newline character from previous input
                        std::getline(std::cin, carToRent);

                        // Check if the entered car model is available
                        auto it = std::find_if(cars.begin(), cars.end(), [&](const auto& pair) {
                        return pair.second.getModel() == carToRent && pair.second.isAvailable();
                    });

                    if (it != cars.end()) {
                        // Move the rented car to the customer's account
                        customer.addRentedCar(it->first);

                        int rentaldays;
            std::cout << "Enter the number of days you want to rent the car for: ";
            std::cin >> rentaldays;
            
            float totalPrice = it->second.getPrice() * rentaldays;

            // Increase the customer's fine dues
            customer.addToFineDue(totalPrice);

            // Update the rental days for the car
            cars.at(it->first).setrentaldays(rentaldays);
            Car car;
                car.setRentedTo(username);

                        // Update the availability of the car
                        cars.at(it->first).setAvailability(false);
                        std::cout << "==================================================="<<std::endl;
                        std::cout << "Car rented successfully for " << rentaldays << " Days !"<< std::endl;
                        std::cout << "Pending dues to be paid are now: Rs." << customer.getFineDue() << std::endl;
                        std::cout << "==================================================="<<std::endl;

            break;
                    
                    } else {
                            std::cout << "Car not found or unavailable for rent." << std::endl;
                        }
            }else if (rentChoice == 'n' || rentChoice == 'N') {

                        break;
            }else{
                                                    std::cout << "invalid input." << std::endl;
break;
                }}
                 
                case 2: {
                    // Call function to display rented cars
                    customer.displayRentedCars(cars);
                    char returnChoice;
    std::cout << "Do you want to return a car? (y/n): ";
    std::cin >> returnChoice;

    if (returnChoice == 'y' || returnChoice == 'Y') {
        std::string carToReturn;
        std::cout << "Enter the model of the car you want to return: ";
        std::cin.ignore(); // Clear newline character from previous input
        std::getline(std::cin, carToReturn);

        // Check if the entered car model is rented by the customer
        // Find an available car matching the entered model
auto it = std::find_if(cars.begin(), cars.end(), 
    [&customer](const auto& pair) {
    if (!pair.second.isAvailable()) {
        customer.addRentedCar(pair.first);
        return true;
    }
    return false;
});



        if (it != cars.end()) {
            // Get the rental days of the car
            int rentaldays = it->second.getrentaldays();

            // Get the actual days rented from the user
            int actualDaysRented;
            std::cout << "Enter the number of days you actually used the car: ";
            std::cin >> actualDaysRented;

            // Calculate the fine and update payment due
            if (actualDaysRented > rentaldays) {
                float fine = (it->second.getPrice() * (actualDaysRented - rentaldays) * 1.5);
                customer.addToFineDue(fine);
                customer.decreaseScore(2 * (actualDaysRented - rentaldays));
            }

            // Remove the rented car from the customer's account
            customer.removeRentedCar(it->first);

            // Update the availability of the car
            cars.at(it->first).setAvailability(true);

            std::cout << "Car returned successfully!" << std::endl;
        } else {
            std::cout << "Car not found or not rented by you." << std::endl;
        }
    }


                    break;
                }
                
                case 3: {
                    std::cout << "=========================="<<std::endl;

                    std::cout << "Payment Due: " <<customer.getFineDue()<< std::endl;
                    std::cout << "=========================="<<std::endl;

                    break;
                }
                
                case 4: {
                    std::cout << "Logging Out....." << std::endl;

                    return;
                }
                
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
            }
        } while (choice != 4);
            
        

    } else {
        std::cout << "Incorrect username or password. Please try again." << std::endl;
    }
}

void employeeLogin(const std::unordered_map<std::string, std::string>& credentials, std::unordered_map<std::string, Employee>& employees, std::unordered_map<std::string, Car>& cars){
    
     std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    // Check if the username exists and if the password matches
    if (credentials.find(username) != credentials.end() && credentials.at(username) == password) {
                std::cout << std::endl;

        std::cout << "Login successful!" << std::endl;

        // If login successful, you can retrieve the customer details from the customers map
        Employee& employee = employees.at(username);
        std::cout << "Welcome, " ; 

        std::cout << username << "!" << std::endl;
                std::cout << std::endl;

        std::cout << "Your ID: " << employee.getId() << std::endl;
        std::cout << "Payment due: " << employee.getFineDue() << std::endl;
        std::cout << "Score: " << employee.getEmployeeRecord() << std::endl;

        int choice;
        
        do {
                std::cout << "\nEmployee Actions:" << std::endl;
                std::cout << "1. Browse and Rent Cars" << std::endl;
                std::cout << "2. View and Return Rented Cars" << std::endl;
                std::cout << "3. Show Payment Due" << std::endl;
                std::cout << "4. Log Out" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> choice;

            switch (choice) {
                case 1: {
                    // Call function to display all available cars
                    employee.displayAllAvailableCars(cars);
                    char rentChoice;
                    std::cout << "Do you want to rent a car? (y/n): ";
                    std::cin >> rentChoice;
            
                    if (rentChoice == 'y' || rentChoice == 'Y') {
                        std::string carToRent;
                        std::cout << "Enter the model of the car you want to rent: ";
                        std::cin.ignore(); // Clear newline character from previous input
                        std::getline(std::cin, carToRent);

                        // Check if the entered car model is available
                        auto it = std::find_if(cars.begin(), cars.end(), [&](const auto& pair) {
                        return pair.second.getModel() == carToRent && pair.second.isAvailable();
                    });

                    if (it != cars.end()) {

                        employee.addRentedCar(it->first);

                        int rentaldays;
            std::cout << "Enter the number of days you want to rent the car for: ";
            std::cin >> rentaldays;
            
            float totalPrice = it->second.getPrice() * rentaldays;

            // Increase the customer's fine dues
            employee.addToFineDue(totalPrice);

            // Update the rental days for the car
            cars.at(it->first).setrentaldays(rentaldays);
            
                        // Update the availability of the car
                        cars.at(it->first).setAvailability(false);
                        std::cout << "==================================================="<<std::endl;
                        std::cout << "Car rented successfully for " << rentaldays << " Days !"<< std::endl;
                        std::cout << "Pending dues to be paid are now: Rs." << employee.getFineDue() << std::endl;
                        std::cout << "==================================================="<<std::endl;

            break;
                    
                    } else {
                            std::cout << "Car not found or unavailable for rent." << std::endl;
                        }
            }else if (rentChoice == 'n' || rentChoice == 'N') {

                        break;
            }else{
                                                    std::cout << "invalid input." << std::endl;
break;
                }}
                 
                case 2: {
                    // Call function to display rented cars
                    employee.displayRentedCars(cars);
                    char returnChoice;
    std::cout << "Do you want to return a car? (y/n): ";
    std::cin >> returnChoice;

    if (returnChoice == 'y' || returnChoice == 'Y') {
        std::string carToReturn;
        std::cout << "Enter the model of the car you want to return: ";
        std::cin.ignore(); // Clear newline character from previous input
        std::getline(std::cin, carToReturn);

        // Check if the entered car model is rented by the customer
        // Find an available car matching the entered model
auto it = std::find_if(cars.begin(), cars.end(), 
    [&employee](const auto& pair) {
    if (!pair.second.isAvailable()) {
        employee.addRentedCar(pair.first);
        return true;
    }
    return false;
});



        if (it != cars.end()) {
            // Get the rental days of the car
            int rentaldays = it->second.getrentaldays();

            // Get the actual days rented from the user
            int actualDaysRented;
            std::cout << "Enter the number of days you actually used the car: ";
            std::cin >> actualDaysRented;

            // Calculate the fine and update payment due
            if (actualDaysRented > rentaldays) {
                float fine = (it->second.getPrice() * (actualDaysRented - rentaldays) * 1.5);
                employee.addToFineDue(fine);
                employee.decreaseScore(2 * (actualDaysRented - rentaldays));
            }

            // Remove the rented car from the customer's account
            employee.removeRentedCar(it->first);

            // Update the availability of the car
            cars.at(it->first).setAvailability(true);

            std::cout << "Car returned successfully!" << std::endl;
        } else {
            std::cout << "Car not found or not rented by you." << std::endl;
        }
    }


                    break;
                }
                
                case 3: {
                    std::cout << "=========================="<<std::endl;

                    std::cout << "Payment Due: " <<employee.getFineDue()<< std::endl;
                    std::cout << "=========================="<<std::endl;

                    break;
                }
                
                case 4: {
                    std::cout << "Logging Out....." << std::endl;

                    return;
                }
                
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
            }
        } while (choice != 4);
            
        

    } else {
        std::cout << "Incorrect username or password. Please try again." << std::endl;
    }
}


void employeeRegister(std::unordered_map<std::string, std::string>& employeeCredentials, std::unordered_map<std::string, Customer>& employees);

void customerRegister(std::unordered_map<std::string, std::string>& customerCredentials, std::unordered_map<std::string, Customer>& customers);

void managerLogin( std::unordered_map<std::string, std::string>& managerCredentials,
                  std::unordered_map<std::string, std::string>& customerCredentials,
                   std::unordered_map<std::string, std::string>& employeeCredentials,
                  std::unordered_map<std::string, Manager>& managers,
                  std::unordered_map<std::string, Customer>& customers,
                  std::unordered_map<std::string, Employee>& employees,
                  std::unordered_map<std::string, Car>& cars) {
    std::string username, password;
    std::cout << "Enter your username: ";
    std::cin >> username;
    std::cout << "Enter your password: ";
    std::cin >> password;

    // Check if the username exists and if the password matches
    if (managerCredentials.find(username) != managerCredentials.end() &&
        managerCredentials.at(username) == password) {
        std::cout << "Login successful!" << std::endl;

        if (managers.find(username) != managers.end()) {
            Manager& manager = managers.at(username);

            // Menu for manager actions
            int choice;
            std::cout << "Manager Menu:" << std::endl;
            std::cout << "1. Add Customer" << std::endl;
            std::cout << "2. Update Customer" << std::endl;
            std::cout << "3. Delete Customer" << std::endl;
            std::cout << "4. Add Employee" << std::endl;
            std::cout << "5. Update Employee" << std::endl;
            std::cout << "6. Delete Employee" << std::endl;
            std::cout << "7. Add Car" << std::endl;
            std::cout << "8. Update Car" << std::endl;
            std::cout << "9. Delete Car" << std::endl;
            std::cout << "10. View All Cars Details" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1: {
                    // Add Customer
                    manager.addcustomer(customerCredentials, customers);
                    break;
                }
                case 2: {
                    // Update Customer
                    manager.updateCustomer(customerCredentials, customers
                        );
                    break;
                }
                case 3: {
                    // Delete Customer
                    manager.deleteCustomer(customerCredentials, customers
                        );
                    break;
                }
                case 4: {
                    // Add Employee
                    manager.addEmployee(employeeCredentials, employees);
                    break;
                }
                case 5: {
                    // Update Employee
                    manager.updateEmployee(employeeCredentials, employees
                        );
                    break;
                }
                case 6: {
                    // Delete Employee
                    manager.deleteEmployee(employeeCredentials, employees
                        );                    
                    break;
                }
                case 7: {
                    // Add Car
                    manager.addCar(cars);
                    break;
                }
                case 8: {
                    // Update Car
                    manager.updateCar(cars);
                    break;
                }
                case 9: {
                    // Delete Car
                    manager.deleteCar(cars);
                    break;
                }
                case 10: {
                    // View All Cars
                    manager.viewAllCars(cars);
                    break;
                }
                default:
                    std::cout << "Invalid choice." << std::endl;
                    break;
            }
        } else {
            std::cout << "Manager not found." << std::endl;
        }
    } else {
        std::cout << "Incorrect username or password. Please try again." << std::endl;
    }
}



void customerRegister(std::unordered_map<std::string, std::string>& customerCredentials, std::unordered_map<std::string, Customer>& customers) {
    std::string username, password;
    std::cout << "Enter your desired username: ";
    std::cin >> username;
    std::cout << "Enter your desired password: ";
    std::cin >> password;

    // Check if the username already exists
    if (customerCredentials.find(username) == customerCredentials.end()) {
        // Add the new customer credentials
        customerCredentials[username] = password;
        // Create a new customer object and add it to the customers map
        customers.emplace(username, Customer("ID0" + std::to_string(customers.size() + 1), {}, 0.0, 100));
        std::cout << "Registration successful!" << std::endl;
    } else {
        std::cout << "Username already exists. Please choose a different username." << std::endl;
    }
}

void employeeRegister(std::unordered_map<std::string, std::string>& employeeCredentials, std::unordered_map<std::string, Employee>& employees) {
    std::string username, password;
    std::cout << "Enter your desired username: ";
    std::cin >> username;
    std::cout << "Enter your desired password: ";
    std::cin >> password;

    // Check if the username already exists
    if (employeeCredentials.find(username) == employeeCredentials.end()) {
        // Add the new employee credentials
        employeeCredentials[username] = password;
        // Create a new employee object and add it to the employees map
        employees.emplace(username, Employee("ID0" + std::to_string(employees.size() + 1), {}, 0.0, 100));
        std::cout << "Registration successful!" << std::endl;
    } else {
        std::cout << "Username already exists. Please choose a different username." << std::endl;
    }
}


int main() {
    
    std::unordered_map<std::string, std::string> customer_credentials = {
        {"customer1", "password1"},
        {"customer2", "password2"},
                {"customer3", "password3"},

        {"customer4", "password4"},
        {"customer5", "password5"},

        // Add more customer credentials here
    };

    std::unordered_map<std::string, std::string> employee_credentials = {
        {"employee1", "password1"},
        {"employee2", "password2"},
        // Add more employee credentials here
    };

    std::unordered_map<std::string, std::string> manager_credentials = {
        {"manager", "managerpassword"}
    };

   std::unordered_map<std::string, Customer> customers;
    customers.emplace("customer1", Customer("ID011", std::vector<std::string>{}, 0.0, 100));
    customers.emplace("customer2", Customer("ID012", std::vector<std::string>{}, 0.0, 100));
    // Add more customers here



    std::unordered_map<std::string, Employee> employees;
    employees.emplace("employee1", Employee("ID021", std::vector<std::string>{}, 0.0, 100));
    employees.emplace("employee2", Employee("ID022", std::vector<std::string>{}, 0.0, 100));
    // Add more employees here

    std::unordered_map<std::string, Manager> managers;
    managers.emplace("manager", Manager("managerID", "managerpassword"));

    std::unordered_map<std::string, Car> cars;
    cars.emplace("car1", Car("718cayman", 23800.0, "Good", "Porsche Cayman",0));
    cars.at("car1").setAvailability(true); // Initially setting availability to true
    cars.emplace("car2", Car("tm03", 16000.0, "Excellent", "Tesla Model 3",0));
    cars.at("car2").setAvailability(true); // Initially setting availability to true
    cars.emplace("car3", Car("etron5r", 20400.0, "Good", "Audi e-tron GT",0));
    cars.at("car3").setAvailability(true); // Initially setting availability to true
    cars.emplace("car4", Car("lx4str", 12000.0, "Good", "Mahindra Thar",0));
    cars.at("car4").setAvailability(true); // Initially setting availability to true
    cars.emplace("car5", Car("chiron7933cc", 30000.0, "Good", "Bugatti Chiron Xe",0));
    cars.at("car5").setAvailability(true); // Initially setting availability to true
    // Add more cars here
    
    std::cout << "                      ___..............._" << std::endl;
    std::cout << "             __.. ' _'.""""""""""""""-               ------ "<< std::endl;
    std::cout << " ______.-'         (_) |      \\           ` \\`-. _" << std::endl;
    std::cout << "/_       --------------'-------\\---....______\\__`.`  -..___" << std::endl;
    std::cout << "| T      _.----._                              |          _.._`--. _" << std::endl;
    std::cout << "| |    .' ..--.. `.           WELCOME TO       |       .'.---..`.     -._" << std::endl;
    std::cout << "\\_j   /  /  __  \\  \\                           |      / /  __  \\ \\        `-. " << std::endl;
    std::cout << " _|  |  |  /  \\  |  |         HANSWHEELS       |     / |  /  \\  | |          |" << std::endl;
    std::cout << "|__\\_j  |  \\__/  |  L__________________________|_____j |  \\__/  | L__________J" << std::endl;
    std::cout << "     `'\\ \\      / ./__________________________________\\ \\      / /___________\\" << std::endl;
    std::cout << "        `.`----'.'                                     `.`----'.'" << std::endl;
    std::cout << "          `\"\"\"\"'                                         `\"\"\"\"'" << std::endl;
        std::cout << std::endl;
        std::cout << "                     ================================="<<std::endl;
        std::cout << "                         Welcome to the HANSWHEELS!   " << std::endl;
        std::cout << "                     ================================="<<std::endl;
                std::cout << std::endl;

        
         
                    std::cout << std::endl;
        std::cout << "======================================================================================"<<std::endl;




    int choice;

    do {
            
            choice = 0;

            std::cout << "\nChoose an option:" << std::endl;
            std::cout << "1. Login" << std::endl;
            std::cout << "2. Register" << std::endl;
                        std::cout << "3. EXIT. Are you SURE you want to EXIT ? ( WARNING! All data will be erased T_T )" << std::endl;

            std::cout << "Enter your choice: ";
            std::cin>>choice;
                            std::cout << "======================================================================================"<<std::endl;
                                                        std::cout << "======================================================================================"<<std::endl;


        if (choice == 1) {
            int userType;
            std::cout << "\nLogin as:" << std::endl;
            std::cout << "1. Customer" << std::endl;
            std::cout << "2. Employee" << std::endl;
            std::cout << "3. Manager" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> userType;

            switch(userType) {
                case 1:
                    std::cout << "\nCustomer Login:" << std::endl;
                    customerLogin(customer_credentials, customers, cars);
                    break;
                case 2:
                    std::cout << "\nEmployee Login:" << std::endl;
                    employeeLogin(employee_credentials, employees, cars);
                    break;
                case 3:
                    std::cout << "\nManager Login:" << std::endl;
                    managerLogin(manager_credentials,customer_credentials,employee_credentials, managers, customers, employees, cars);
                    break;
                default:
                    std::cout << "\nInvalid choice." << std::endl;
                     std::cin.clear(); // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
            }
        } else if (choice == 2) {
            int userType;
            std::cout << "\nRegister as:" << std::endl;
            std::cout << "1. Customer" << std::endl;
            std::cout << "2. Employee" << std::endl;
            std::cout << "Enter your choice: ";
            std::cin >> userType;

            switch(userType) {
                case 1:
                    std::cout << "\nCustomer Registration:" << std::endl;
                    customerRegister(customer_credentials, customers);
                    break;
                case 2:
                    std::cout << "\nEmployee Registration:" << std::endl;
                    employeeRegister(employee_credentials, employees);
                    break;
                default:
                    std::cout << "\nInvalid choice. Please enter a valid number." << std::endl;
                    std::cin.clear(); // Clear the fail state
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
            } 
            
        } else if (choice == 3) {


            std::cout << "Goodbye! (ALL DATA ERASED) " << std::endl;
            break;
        } else {
            std::cout << "Invalid choice. Please enter an integer from 1-3 . ...." << std::endl;
            std::cin.clear(); // Clear the fail state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters
            break;
        }
        
    }while(choice != 3);       

    

    return 0;
}

