#pragma once

#include "Vector3.h"
#include "Vector4.h"

namespace nuy { namespace maths {

	struct Matrix4
	{
		/* NOTE(andrey): Use elements in Column Major Ordering (OpenGL is also this way).
		*				 elements[row + col * 4]
		*/
		union
		{
			float elements[4 * 4];
			Vector4 columns[4];
		};

		Matrix4();
		Matrix4(float diagonal);
		Matrix4(float* elements);

		static Matrix4 Identity();

		friend Matrix4 operator*(Matrix4 left, const Matrix4& right);
		Matrix4& operator*=(const Matrix4& other);
		Matrix4& Multiply(const Matrix4& other);

		static Matrix4 Orthographic(float left, float right, float bottom, float top, float near, float far);
		static Matrix4 Perspective(float fov, float aspectRation, float near, float far);

		static Matrix4 Translate(const Vector3& translation);
		static Matrix4 Rotate(const float angle, const Vector3& axis);
		static Matrix4 Scale(const Vector3& scale);

		friend std::ostream& operator<<(std::ostream& stream, const Matrix4& m);
	};

} }