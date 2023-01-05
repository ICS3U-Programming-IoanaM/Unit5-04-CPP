// !/usr/bin/env python3
// Copyright (c) 2022 Ioana Marinescu All rights reserved.
// Created By: Ioana Marinescu

// Date: Jan. 4, 2022
// a calculator program


#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>


std::string Calculate(std::string sign, float num1, float num2) {
    // variables
    float answer;

    // addition
    if (sign == "+") {
        answer = num1 + num2;

    // subtraction
    } else if (sign == "-") {
        answer = num1 - num2;

    // multiplication
    } else if (sign == "*") {
        answer = num1 * num2;

    // division
    } else if (sign == "/") {
        answer = num1 / num2;

    // modulus
    } else if (sign == "%") {
        answer = fmod(num1, num2);

    // invalid sign input
    } else {
        return "invalid";
    }

    // returning final value
    return std::to_string(answer);
}


int main() {
    // variables
    std::string userSign, firstNumStr, secondNumStr, result;
    float firstNumFl, secondNumFl;

    // staring message
    std::cout << "This program does a calculation between"
              << " 2 numbers.\nThe operands you can use"
              << " are +, -, *, /, and %." << std::endl;

    // getting user input for the operand
    std::cout << "Enter the operand: ";
    std::cin >> userSign;

    // getting user input for the first number
    std::cout << "Enter the first number: ";
    std::cin >> firstNumStr;

    // getting user input for the second number
    std::cout << "Enter the second number: ";
    std::cin >> secondNumStr;

    // exception handling
    try {
        // casting string to float
        firstNumFl = stof(firstNumStr);
        secondNumFl = stof(secondNumStr);

        // calls function do the calculation
        result = Calculate(userSign, firstNumFl, secondNumFl);

        // displays results
        if (result == "invalid") {
            std::cout << std::fixed << std::setprecision(2)
                      << std::setfill('0') << "The result of "
                      << firstNumFl << " " << userSign << " "
                      << secondNumFl << " is " << result
                      << "." << std::endl;
        } else {
            std::cout << std::fixed << std::setprecision(2)
                      << std::setfill('0') << "The result of "
                      << firstNumFl << " " << userSign << " "
                      << secondNumFl << " is " << stof(result)
                      << "." << std::endl;
        }

        // invalid input was entered
    } catch(std::invalid_argument) {
        std::cout << std::fixed << std::setprecision(2)
                  << std::setfill('0') << "The result of "
                  << firstNumStr << " " << userSign << " "
                  << secondNumStr << " is invalid."
                  << std::endl;
    }
}
