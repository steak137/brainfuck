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
        switch (c) {
        case '+':
            mem[ptr]++;
            break;
        case '-':
            mem[ptr]--;
            break;
        case '>':
            ptr = (ptr + 1) % MEM_SIZE;
            break;
        case '<':
            ptr = (ptr + MEM_SIZE - 1) % MEM_SIZE;
            break;
        case '.':
            std::cout << mem[ptr];
            break;
        case ',':
            char input;
            std::cin >> input;
            mem[ptr] = input;
            break;
        case '[':
            if (mem[ptr] == 0) {
                int loop_count = 1;
                while (loop_count > 0) {
                    idx++;
                    if (bf_code[idx] == '[')
                        loop_count++;
                    else if (bf_code[idx] == ']')
                        loop_count--;
                }
            }
            break;
        case ']':
            if (mem[ptr] != 0) {
                int loop_count = 1;
                while (loop_count > 0) {
                    idx--;
                    if (bf_code[idx] == '[')
                        loop_count--;
                    else if (bf_code[idx] == ']')
                        loop_count++;
                }
            }
            break;
        default:
            break;
        }
        idx++;
    }
}
