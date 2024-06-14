#include <GLFW/glfw3.h>
#include "Object.h"

void render(GLFWwindow* window);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void update(float delta_time);

Player player;
Floor floorObject;

int main()
{
    // GLFW 초기화
    if (!glfwInit())
        return -1;

    // window 생성
    GLFWwindow* window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // 현재 window를 컨텍스트로 설정
    glfwMakeContextCurrent(window);

    // 배경색 설정 (하늘색: R:0, G:30, B:100)
    glClearColor(0.0f, 0.12f, 0.39f, 1.0f);

    // 객체 초기화
    player = Player();
    floorObject = Floor();

    // 키 콜백 함수 등록
    glfwSetKeyCallback(window, keyCallback);

    // 메인 루프
    while (!glfwWindowShouldClose(window))
    {
        // 시간 측정 시작
        static double last_frame_time = glfwGetTime();
        double current_time = glfwGetTime();
        float delta_time = static_cast<float>(current_time - last_frame_time);
        last_frame_time = current_time;

        // 화면을 지우고 배경색으로 채우기
        glClear(GL_COLOR_BUFFER_BIT);

        // 플레이어 업데이트
        player.Update(delta_time);

        // 객체들 그리기
        player.Draw();
        floorObject.Draw();

        // 이벤트 처리 (키 입력 등)
        glfwPollEvents();

        // 버퍼 스왑 (더블 버퍼링)
        glfwSwapBuffers(window);
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS || action == GLFW_REPEAT) {
        if (key == GLFW_KEY_SPACE) {
            player.Jump();
        }
    }
}
