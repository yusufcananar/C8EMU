#include "../include/Chip8.hpp"
#include <iostream>
#include <fstream>


//---------------------------TEST FUNCTION------------------------------------------
void summer(char const* filename){
    std::cout << "*********SUMMER**********\n";
    uint8_t memory[4096]{};
    // Open the file as a stream of binary and move the file pointer to the end
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    std::cout << file.is_open() <<"\n";
    if (file.is_open()){

        // Get size of file and allocate a buffer to hold the contents
        file.seekg (0, file.end);
        std::streampos size = file.tellg();
        char* buffer = new char[size];

        // Go back to the beginning of the file and fill the buffer
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        // Load the ROM contents into the Chip8's memory, starting at 0x200
        for (long i = 0; i < size; ++i){
            memory[0x200 + i] = buffer[i];
        }

        // Free the buffer
        delete[] buffer;
    }
}
//----------------------------------------------------------------------------------



const unsigned int START_ADDRESS = 0x200; // Program memory start adress


Chip8::Chip8()
{
	// Initialize PC
	pc = START_ADDRESS;
}

void Chip8::LoadROM(char const* filename){
    
    // Open the file as a stream of binary and move the file pointer to the end
    std::ifstream file(filename, std::ios::binary | std::ios::ate);

    if (file.is_open()){

        // Get size of file and allocate a buffer to hold the contents
        file.seekg (0, file.end);
        std::streampos size = file.tellg();
        char* buffer = new char[size];

        // Go back to the beginning of the file and fill the buffer
        file.seekg(0, std::ios::beg);
        file.read(buffer, size);
        file.close();

        // Load the ROM contents into the Chip8's memory, starting at 0x200
        for (long i = 0; i < size; ++i){
            memory[START_ADDRESS + i] = buffer[i];
        }

        // Free the buffer
        delete[] buffer;
    }
}
