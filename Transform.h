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

    // 이동 함수
    Vertex MoveVertex(Vertex point, Vector meter);

    // 회전 함수 (시계 방향)
    Vertex RotateVertex(Vertex point, float angle_degree);

    // 크기 조정 함수
    Vertex ScaleVertex(Vertex point, Vector meter);

} // namespace Transform
