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

void DrawBlock(ForeColour colour) 
{
    std::cout << "\033[" << colour << "m" << "■\033[0m";
}

int main() {
    std::cout << "\033[033m" << "아름다운 색!! 우왕" << std::endl;

    int score = 0; // 스코어 선언

    std::cout << "화면에 그림을 그리는 프로그램입니다." << std::endl;
    std::cout << "학번: 202327032" << std::endl;
    std::cout << "이름: 신지성" << std::endl;
    std::cout << std::endl;
    std::cout << "화면에 그릴 물체코드를 입력하세요 (프로그램 종료를 원하면 64 입력): " << std::endl;

    while (true) {
        int objectCode;
        std::cin >> objectCode;

        switch (objectCode) {
        case 1:
            DrawBlock(White);
            break;
        case 2:
            DrawBlock(Red);
            score -= 1; 
            break;
        case 4:
            DrawBlock(Green);
            score += 1; 
            break;
        case 8:
            DrawBlock(Yellow);
            break;
        case 16:
            DrawBlock(Cyan);
            break;
        case 32:
            DrawBlock(Magenta);
            break;
        case 64:
            std::cout << "프로그램을 종료합니다." << std::endl;
            return 0;
        default:
            std::cout << "잘못된 코드입니다. 다시 입력해주세요." << std::endl;
            break;
        }

        // std::cout << " 현재 스코어: " << score << std::endl; // 스코어 출력
    }

    return 0;
}
