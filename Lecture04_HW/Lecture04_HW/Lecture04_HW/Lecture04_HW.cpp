//https://www.glfw.org/
// 프로젝트 - NuGet 패키지 관리 - GLFW 다운
#include <iostream>
#pragma comment(lib, "Opengl32.lib") // OpenGL 라이브러리 링크
#include <GLFW/glfw3.h> // GLFW 헤더

// 전역 변수 선언
bool leftButtonDown = false; // 왼쪽 버튼이 눌려 있는지 여부를 추적
bool rightButtonDown = false; // 오른쪽 버튼이 눌려 있는지 여부를 추적

// GLFW 에러 콜백 함수
void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

// 키 콜백 함수
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // ESC 키를 누르면 윈도우를 닫음
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

// 마우스 버튼 콜백 함수
void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    // 왼쪽 버튼이 눌렸을 때
    if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS) // 버튼이 눌렸을 때
        {
            leftButtonDown = true;
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // 녹색으로 클리어 색 변경
        }
        else if (action == GLFW_RELEASE) // 버튼이 떼어졌을 때
        {
            leftButtonDown = false;
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 검정색으로 클리어 색 원래대로 복구
        }
    }

    // 오른쪽 버튼이 눌렸을 때
    if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS) // 버튼이 눌렸을 때
        {
            rightButtonDown = true;
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // 빨간색으로 클리어 색 변경
        }
        else if (action == GLFW_RELEASE) // 버튼이 떼어졌을 때
        {
            rightButtonDown = false;
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 마젠타색으로 클리어 색 원래대로 복구
        }
    }
}

int main(void)
{
    // GLFW 라이브러리 초기화
    if (!glfwInit())
        return -1;  // 초기화 실패 시 종료

    GLFWwindow* window; // GLFW 윈도우 핸들
    window = glfwCreateWindow(1280, 768, "TestEngine", NULL, NULL); // 윈도우 생성

    if (!window)
    {
        glfwTerminate();
        return -1; // 윈도우 생성 실패 시 종료
    }

    // OpenGL 컨텍스트 생성
    glfwMakeContextCurrent(window);

    // GLFW 에러 콜백 함수 등록
    glfwSetErrorCallback(errorCallback);
    // 키 콜백 함수 등록
    glfwSetKeyCallback(window, keyCallback);
    // 마우스 버튼 콜백 함수 등록
    glfwSetMouseButtonCallback(window, mouseButtonCallback);

    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        // 이벤트 처리
        glfwPollEvents();

        // 클리어 색을 검정으로 설정
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Red, Green, Blue, Alpha
        // Bit단위로 클리어
        glClear(GL_COLOR_BUFFER_BIT);

        // 마우스 오른쪽 버튼이 눌린 상태이고 드래그 중이면 파란색으로 클리어 색 변경
        if (rightButtonDown && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS)
            glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

        // 마우스 왼쪽 버튼이 눌린 상태이고 드래그 중이면 마젠타색으로 클리어 색 변경
        if (leftButtonDown && glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS)
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f);

        // 버퍼 교환
        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}
