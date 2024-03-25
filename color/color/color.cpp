#include <iostream>

enum ForeColour {
    Default = 0,
    Black = 30,
    Red = 31,
    Green = 32,
    Yellow = 33,
    Blue = 34,
    Magenta = 35,
    Cyan = 36,
    White = 37,
};

int main() {
    const int WHITE_BLOCK = 1;       // 0b00000001
    const int RED_BLOCK = 2;         // 0b00000010
    const int GREEN_BLOCK = 4;       // 0b00000100
    const int YELLOW_BLOCK = 8;      // 0b00001000
    const int CYAN_BLOCK = 16;       // 0b00010000
    const int MAGENTA_BLOCK = 32;    // 0b00100000
    const int EXIT_PROGRAM = 64;     // 0b01000000

    std::cout << "흰색 블록을 그리는 키 코드: 1 (00000001)" << std::endl;
    std::cout << "빨강색 블록을 그리는 키 코드: 2 (00000010)" << std::endl;
    std::cout << "녹색 블록을 그리는 키 코드: 4 (00000100)" << std::endl;
    std::cout << "노란색 블록을 그리는 키 코드: 8 (00001000)" << std::endl;
    std::cout << "청록색 블록을 그리는 키 코드: 16 (00010000)" << std::endl;
    std::cout << "마젠타색 블록을 그리는 키 코드: 32 (00100000)" << std::endl;
    std::cout << "프로그램 종료: 64 (01000000)" << std::endl;

    int input;
    do {
        std::cout << "\n블록을 그릴 색상의 키 코드를 입력하세요: ";
        std::cin >> input;

        if (input & WHITE_BLOCK)
            std::cout << "\x1b[0;" << (30 + White) << "m█"; // ANSI escape sequence to set color
        if (input & RED_BLOCK)
            std::cout << "\x1b[0;" << (30 + Red) << "m█"; // ANSI escape sequence to set color
        if (input & GREEN_BLOCK)
            std::cout << "\x1b[0;" << (30 + Green) << "m█"; // ANSI escape sequence to set color
        if (input & YELLOW_BLOCK)
            std::cout << "\x1b[0;" << (30 + Yellow) << "m█"; // ANSI escape sequence to set color
        if (input & CYAN_BLOCK)
            std::cout << "\x1b[0;" << (30 + Cyan) << "m█"; // ANSI escape sequence to set color
        if (input & MAGENTA_BLOCK)
            std::cout << "\x1b[0;" << (30 + Magenta) << "m█"; // ANSI escape sequence to set color

        std::cout << std::endl; // 출력이 다 끝난 후에 개행을 추가해줍니다.

    } while (!(input & EXIT_PROGRAM));

    std::cout << "\n프로그램을 종료합니다." << std::endl;

    return 0;
}

/*while (true) {
        std::cout << "화면에 그릴 물체코드를 입력하세요 (종료하려면 " << EXIT << "을 입력하세요): ";
        int input = 0;
        std::cin >> input;

        if (input == EXIT) {
            std::cout << "프로그램을 종료합니다." << std::endl;
            break; // 루프를 종료합니다.
        }

        if (input & WHITE) {
            std::cout << "\x1b[033m" << (int)WHITE << "m";
            std::cout << "■";
        }
        if (input & RED) {
            std::cout << "\x1b[033m" << (int)RED << "m";
            std::cout << "■";
        }
        if (input & GREEN) {
            std::cout << "\x1b[033m" << (int)GREEN << "m";
            std::cout << "■";
        }
        if (input & YELLOW) {
            std::cout << "\x1b[033m" << (int)YELLOW << "m";
            std::cout << "■";
        }
        if (input & CYAN) {
            std::cout << "\x1b[033m" << (int)CYAN << "m";
            std::cout << "■";
        }
        if (input & MAGENTA) {
            std::cout << "\x1b[033m" << (int)MAGENTA << "m";
            std::cout << "■";
        }
    }

    return 0;
    */