#pragma once

#include <cstdint>

void summer(char const*);

class Chip8 {
    public:

        uint8_t registers[16]{}; // V0 to VF
        uint8_t memory[4096]{}; // 4KBytes of memory
        uint16_t index{}; //index Register
        uint16_t pc{}; // Program Counter
        uint8_t sp{}; // Stack Pointer
        uint16_t stack[16]{}; // 16 level stack
        uint8_t delayTimer{}; // 8-bit delay timer
        uint8_t soundTimer{}; // 8-bit sound timer
        uint8_t keypad[16]{}; // 16 character keyboard
        uint32_t video[64 * 32]{}; 
        uint16_t opcode; //34 opcodes

        void LoadROM(char const* filename);

};
