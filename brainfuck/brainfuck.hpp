#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
const int MEM_SIZE = 30000;
void execute(const std::string& bf_code) {
    int idx = 0;
    int ptr = 0;
    std::vector<unsigned char> mem(MEM_SIZE, 0);

    while (idx < bf_code.length()) {
        char c = bf_code[idx];
        if (c == '+') mem[ptr] = (mem[ptr] + 1) % 256;
        if (c == '-') mem[ptr] = (mem[ptr] + 255) % 256;
        if (c == '>') ptr = (ptr + 1) % MEM_SIZE;
        if (c == '<') ptr = (ptr + MEM_SIZE - 1) % MEM_SIZE;
        if (c == '.') std::cout << mem[ptr];
        if (c == ',') {
            std::string input;
            std::getline(std::cin, input);
            mem[ptr] = input.empty() ? 0 : input[0] % 256;
        }
        if (c == '[' && !mem[ptr]) {
            int depth = 1;
            while (depth && idx + 1 < bf_code.length()) {
                idx++;
                if (bf_code[idx] == '[') depth++;
                if (bf_code[idx] == ']') depth--;
            }
        }
        if (c == ']' && mem[ptr]) {
            int depth = 1;
            while (depth && idx - 1 >= 0) {
                idx--;
                if (bf_code[idx] == ']') depth++;
                if (bf_code[idx] == '[') depth--;
            }
        }
        idx++;
    }
}