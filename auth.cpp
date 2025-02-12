#include <iostream>
#include <string>
#include "auth.h"

bool authenticateUser() {
    std::string username, password;
    std::string correctUsername = "admin";
    std::string correctPassword = "password123";

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    return (username == correctUsername && password == correctPassword);
}
