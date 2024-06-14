#pragma once

namespace Transform {

    struct Vertex {
        float x;
        float y;
    };

    struct Vector {
        float x_meter;
        float y_meter;
    };

    // �̵� �Լ�
    Vertex MoveVertex(Vertex point, Vector meter);

    // ȸ�� �Լ� (�ð� ����)
    Vertex RotateVertex(Vertex point, float angle_degree);

    // ũ�� ���� �Լ�
    Vertex ScaleVertex(Vertex point, Vector meter);

} // namespace Transform
