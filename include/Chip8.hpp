#pragma once

#include <cstdint>


void summer(char const*);

class Chip8 {
    public:
        Chip8();

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

        std::default_random_engine randGen;
        std::uniform_int_distribution<uint8_t> randByte;

        void OP_0nnn(); // Jump to a machine code routine at nnn. (Ignored for modern interpreters)
        void OP_00E0(); // CLS
        void OP_00EE(); // RET
        void OP_1nnn(); // JP addr
        void OP_2nnn(); // CALL addr
        void OP_3xkk(); // SE Vx, byte
        void OP_4xkk(); // SNE Vx, byte
        void OP_5xy0(); // SE Vx, Vy
        void OP_6xkk(); // LD Vx, byte
        void OP_7xkk(); // ADD Vx, byte
        void OP_8xy0(); // LD Vx, Vy
        void OP_8xy1(); // OR Vx, Vy
        void OP_8xy2(); // AND Vx, Vy
        void OP_8xy3(); // XOR Vx, Vy
        void OP_8xy4(); // ADD Vx, Vy
        void OP_8xy5(); // SUB Vx, Vy
        void OP_8xy6(); // SHR Vx {, Vy}
        void OP_8xy7(); // SUBN Vx, Vy
        void OP_8xyE(); // SHL Vx {, Vy}
        void OP_9xy0(); // SNE Vx, Vy
        void OP_Annn(); // LD I, addr
        void OP_Bnnn(); // JP V0, addr
        void OP_Cxkk(); // RND Vx, byte
        void OP_Dxyn(); // DRW Vx, Vy, nibble
        void OP_Ex9E(); // SKP Vx
        void OP_ExA1(); // SKNP Vx
        void OP_Fx07(); // LD Vx, DT
        void OP_Fx0A(); // LD Vx, K
        void OP_Fx15(); // LD DT, Vx
        void OP_Fx18(); // LD ST, Vx
        void OP_Fx1E(); // ADD I, Vx
        void OP_Fx29(); // LD F, Vx
        void OP_Fx33(); // LD B, Vx
        void OP_Fx55(); // LD [I], Vx
        void OP_Fx65(); // LD Vx, [I]



};
