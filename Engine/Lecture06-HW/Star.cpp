#include "Star.h"
#include "Vector2D.h"
#include "GLFW/glfw3.h"

void Star::update()
{


}

void Star::render()
{
	const int starDrawSequence[3][3] =
	{
		{ 0, 3, 4 },
		{ 0, 5, 3 },
		{ 3, 2, 1 }
	};

	const Vector2D starPoints[6] =
	{
		Vector2D(0, 0.6),
		Vector2D(-0.5, 0.25),
		Vector2D(0.5, 0.25),
		Vector2D(0, -0.25),
		Vector2D(-0.4, -0.5),
		Vector2D(0.4, -0.5)
	};

	glColor3f(color.r, color.g, color.b);
	for (int i = 0; i < 3; i++)
	{
		glBegin(GL_TRIANGLES);
		for (int j = 0; j < 3; j++)
		{
			Vector2D star = starPoints[starDrawSequence[i][j]];
			// 크기 변환 연산
			star.x = star.x * 0.1;
			star.y = star.y * 0.1;

			star.x = star.x * transform.GetScale().x;
			star.y = star.y * transform.GetScale().y;

			// 위치 변환 연산
			star = star + transform.GetPosition();
			glVertex2d(star.x, star.y);
		}
		glEnd();
	}
}
