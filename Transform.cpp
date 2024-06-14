#include "Transform.h"
#include <cmath>

// ��� 1: _USE_MATH_DEFINES�� ����Ͽ� M_PI �����ϱ�
#define _USE_MATH_DEFINES
#include <math.h>

namespace Transform {

    // ȸ�� �Լ� (�ð� ����)
    Vertex RotateVertex(Vertex point, float angle_degree) {
        float angle_rad = angle_degree * (M_PI / 180.0f); // ������ �������� ��ȯ
        float x_new = point.x * cos(angle_rad) - point.y * sin(angle_rad);
        float y_new = point.x * sin(angle_rad) + point.y * cos(angle_rad);
        point.x = x_new;
        point.y = y_new;
        return point;
    }

} // namespace Transform
