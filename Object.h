#pragma once

#include <GLFW/glfw3.h>
#include "Transform.h"

// Base class
class Object {
public:
    virtual void Draw() const = 0;
    virtual void OnCollisionEnter(Object& other) {}
    virtual void Update(float delta_time) {}
    virtual float GetYPosition() const { return 0.0f; } // 기본 구현
};

// Derived classes
class Player : public Object {
private:
    float size_cm = 50.0f; // 50cm 크기 정사각형
    float thickness_cm = 3.0f; // 3cm 두께 테두리
    float x_pos_meter = 0.0f; // x 좌표 (미터 단위)
    float y_pos_meter = 100.0f; // y 좌표 (미터 단위)
    float jump_speed = 5.0f; // 점프 속도 (미터/초)
    float gravity = 9.8f; // 중력 가속도 (미터/초^2)
    bool is_jumping = false; // 점프 중 여부
public:
    void Draw() const override {
        // 플레이어 그리기 (빨간색 정사각형)
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(x_pos_meter - size_cm / 2.0f, y_pos_meter - size_cm / 2.0f);
        glVertex2f(x_pos_meter + size_cm / 2.0f, y_pos_meter - size_cm / 2.0f);
        glVertex2f(x_pos_meter + size_cm / 2.0f, y_pos_meter + size_cm / 2.0f);
        glVertex2f(x_pos_meter - size_cm / 2.0f, y_pos_meter + size_cm / 2.0f);
        glEnd();

        // 테두리 그리기
        glColor3f(0.0f, 0.0f, 0.0f); // 검정색 테두리
        glLineWidth(thickness_cm);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x_pos_meter - size_cm / 2.0f, y_pos_meter - size_cm / 2.0f);
        glVertex2f(x_pos_meter + size_cm / 2.0f, y_pos_meter - size_cm / 2.0f);
        glVertex2f(x_pos_meter + size_cm / 2.0f, y_pos_meter + size_cm / 2.0f);
        glVertex2f(x_pos_meter - size_cm / 2.0f, y_pos_meter + size_cm / 2.0f);
        glEnd();
    }

    void Update(float delta_time) override {
        // 중력 적용
        if (!is_jumping) {
            y_pos_meter -= 0.5 * gravity * delta_time * delta_time;
        }
    }

    void Jump() {
        if (!is_jumping) {
            is_jumping = true;
            // 점프 속도로 점프
            y_pos_meter += jump_speed;
        }
    }

    void ApplyGravity(float delta_time) {
        if (is_jumping) {
            // 중력 적용
            y_pos_meter -= 0.5 * gravity * delta_time * delta_time;
        }
    }

    bool IsJumping() const {
        return is_jumping;
    }

    float GetYPosition() const override {
        return y_pos_meter;
    }

    void SetYPosition(float y_meter) {
        y_pos_meter = y_meter;
    }

    void OnCollisionEnter(Object& other) override {
        // 충돌 감지 로직 추가
        // 여기서는 간단히 플레이어의 y 위치와 다른 객체의 y 위치를 비교하여 충돌 여부를 확인
        if (other.GetYPosition() <= y_pos_meter) {
            is_jumping = false; // 점프 중이 아님
            SetYPosition(other.GetYPosition()); // 다른 객체의 y 위치로 설정
        }
    }
};

class Floor : public Object {
private:
    float y_pos_meter = 0.0f; // 바닥의 y 좌표 (미터 단위)
public:
    void Draw() const override {
        // 바닥 그리기 (황색)
        glColor3f(1.0f, 0.78f, 0.06f); // 황색
        glBegin(GL_QUADS);
        glVertex2f(-400.0f, y_pos_meter); // 왼쪽 아래
        glVertex2f(400.0f, y_pos_meter); // 오른쪽 아래
        glVertex2f(400.0f, y_pos_meter - 10.0f); // 오른쪽 위
        glVertex2f(-400.0f, y_pos_meter - 10.0f); // 왼쪽 위
        glEnd();
    }

    float GetYPosition() const override {
        return y_pos_meter;
    }
};
