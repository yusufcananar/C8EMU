#pragma once

#include <cstdint>

void summer();

class Chip8 {
    public:
    uint8_t registers[16]{};
    uint8_t memory[4096]{};
    uint16_t index{}; //index Register
    uint16_t pc{}; // Program Counter
    uint8_t sp{}; // Stack Pointer
    uint16_t stack[16]{};
    uint8_t delayTimer{};
    uint8_t soundTimer{};  
    uint8_t keypad[16]{};
    uint32_t video[64 * 32]{};
    uint16_t opcode;
};
