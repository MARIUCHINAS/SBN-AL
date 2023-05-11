#include <iostream>
#include <string>

std::string encrypt(std::string input, int shifter) {
    std::string output = input;
    for (int shift = 0; shift != input.length(); shift++) {
        output[shift] = (int)input[shift] + shifter;
        if ((int)output[shift] > 255) {
            output[shift] = (int)input[shift] - shifter;
        }
    }
    return output;
}  

std::string decrypt(std::string input, int shifter) {
    std::string output = input;
    for (int shift = 0; shift != input.length(); shift++) {
        output[shift] = (int)input[shift] - shifter;
        if ((int)output[shift] > 255) {
            output[shift] = (int)input[shift] + shifter;
        }
    }
    return output;
}

int main() {
    std::string input;
    std::string shift_input;
    int shift_num;

    std::cout << "Input: ";
    std::getline(std::cin, input);

    std::cout << "Shift Input: ";
    std::getline(std::cin, shift_input);
    
    try
    {
        shift_num = std::stoi(shift_input);
    }
    catch (const std::out_of_range)
    {
        std::cout << "Microsoft C++ exception: std::out_of_range at memory location" << std::endl;
        std::cin.get();
        return 1;
    }
    catch (const std::exception&)
    {
        std::cout << "Something Went Wrong" << std::endl;
        std::cin.get();
        return 1;
    }

    std::string encrypted = encrypt(input, shift_num);

    std::string decrypted = decrypt(encrypted, shift_num);

    std::cout << "Encrypted: " << encrypted << std::endl;

    std::cout << "Decrypted: " << decrypted << std::endl;
}
