#include "Transform.h"
#include <cmath>

// 방법 1: _USE_MATH_DEFINES를 사용하여 M_PI 정의하기
#define _USE_MATH_DEFINES
#include <math.h>

namespace Transform {

    // 회전 함수 (시계 방향)
    Vertex RotateVertex(Vertex point, float angle_degree) {
        float angle_rad = angle_degree * (M_PI / 180.0f); // 각도를 라디안으로 변환
        float x_new = point.x * cos(angle_rad) - point.y * sin(angle_rad);
        float y_new = point.x * sin(angle_rad) + point.y * cos(angle_rad);
        point.x = x_new;
        point.y = y_new;
        return point;
    }

} // namespace Transform
