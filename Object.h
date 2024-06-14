#pragma once

#include <GLFW/glfw3.h>
#include "Transform.h"

// Base class
class Object {
public:
    virtual void Draw() const = 0;
    virtual void OnCollisionEnter(Object& other) {}
    virtual void Update(float delta_time) {}
    virtual float GetYPosition() const { return 0.0f; } // �⺻ ����
};

// Derived classes
class Player : public Object {
private:
    float size_cm = 50.0f; // 50cm ũ�� ���簢��
    float thickness_cm = 3.0f; // 3cm �β� �׵θ�
    float x_pos_meter = 0.0f; // x ��ǥ (���� ����)
    float y_pos_meter = 100.0f; // y ��ǥ (���� ����)
    float jump_speed = 5.0f; // ���� �ӵ� (����/��)
    float gravity = 9.8f; // �߷� ���ӵ� (����/��^2)
    bool is_jumping = false; // ���� �� ����
public:
    void Draw() const override {
        // �÷��̾� �׸��� (������ ���簢��)
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glVertex2f(x_pos_meter - size_cm / 2.0f, y_pos_meter - size_cm / 2.0f);
        glVertex2f(x_pos_meter + size_cm / 2.0f, y_pos_meter - size_cm / 2.0f);
        glVertex2f(x_pos_meter + size_cm / 2.0f, y_pos_meter + size_cm / 2.0f);
        glVertex2f(x_pos_meter - size_cm / 2.0f, y_pos_meter + size_cm / 2.0f);
        glEnd();

        // �׵θ� �׸���
        glColor3f(0.0f, 0.0f, 0.0f); // ������ �׵θ�
        glLineWidth(thickness_cm);
        glBegin(GL_LINE_LOOP);
        glVertex2f(x_pos_meter - size_cm / 2.0f, y_pos_meter - size_cm / 2.0f);
        glVertex2f(x_pos_meter + size_cm / 2.0f, y_pos_meter - size_cm / 2.0f);
        glVertex2f(x_pos_meter + size_cm / 2.0f, y_pos_meter + size_cm / 2.0f);
        glVertex2f(x_pos_meter - size_cm / 2.0f, y_pos_meter + size_cm / 2.0f);
        glEnd();
    }

    void Update(float delta_time) override {
        // �߷� ����
        if (!is_jumping) {
            y_pos_meter -= 0.5 * gravity * delta_time * delta_time;
        }
    }

    void Jump() {
        if (!is_jumping) {
            is_jumping = true;
            // ���� �ӵ��� ����
            y_pos_meter += jump_speed;
        }
    }

    void ApplyGravity(float delta_time) {
        if (is_jumping) {
            // �߷� ����
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
        // �浹 ���� ���� �߰�
        // ���⼭�� ������ �÷��̾��� y ��ġ�� �ٸ� ��ü�� y ��ġ�� ���Ͽ� �浹 ���θ� Ȯ��
        if (other.GetYPosition() <= y_pos_meter) {
            is_jumping = false; // ���� ���� �ƴ�
            SetYPosition(other.GetYPosition()); // �ٸ� ��ü�� y ��ġ�� ����
        }
    }
};

class Floor : public Object {
private:
    float y_pos_meter = 0.0f; // �ٴ��� y ��ǥ (���� ����)
public:
    void Draw() const override {
        // �ٴ� �׸��� (Ȳ��)
        glColor3f(1.0f, 0.78f, 0.06f); // Ȳ��
        glBegin(GL_QUADS);
        glVertex2f(-400.0f, y_pos_meter); // ���� �Ʒ�
        glVertex2f(400.0f, y_pos_meter); // ������ �Ʒ�
        glVertex2f(400.0f, y_pos_meter - 10.0f); // ������ ��
        glVertex2f(-400.0f, y_pos_meter - 10.0f); // ���� ��
        glEnd();
    }

    float GetYPosition() const override {
        return y_pos_meter;
    }
};
