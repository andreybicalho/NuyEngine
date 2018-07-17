#include "Matrix4.h"
#include "Maths.h"

#include <iomanip>

namespace nuy { namespace maths {

	Matrix4::Matrix4()
	{
		memset(elements, 0, 4 * 4 * sizeof(float));
	}

	Matrix4::Matrix4(float diagonal)
	{
		memset(elements, 0, 4 * 4 * sizeof(float));
		
		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	Matrix4::Matrix4(float* elements)
	{
		memcpy(this->elements, elements, 4 * 4 * sizeof(float));
	}

	Matrix4 Matrix4::Identity()
	{
		return Matrix4(1.0f);
	}

	Matrix4 operator*(Matrix4 left, const Matrix4& right)
	{
		return left.Multiply(right);
	}

	Matrix4& Matrix4::operator*=(const Matrix4& other)
	{
		return Multiply(other);
	}

	Matrix4& Matrix4::Multiply(const Matrix4& other)
	{
		float data[16];
		for (int y = 0; y < 4; y++)
		{
			for (int x = 0; x < 4; x++)
			{
				float sum = 0.0f;
				for (int e = 0; e < 4; e++)
				{
					sum += elements[x + e * 4] * other.elements[e + y * 4];
				}
				data[x + y * 4] = sum;
			}
		}

		memcpy(elements, data, 4 * 4 * sizeof(float));
		return *this;
	}

	Matrix4 Matrix4::Orthographic(float left, float right, float bottom, float top, float near, float far)
	{
		Matrix4 result;

		// diagonal
		result.elements[0 + 0 * 4] = 2 / (right - left);
		result.elements[1 + 1 * 4] = 2 / (top - bottom);
		result.elements[2 + 2 * 4] = 2.0f / (near - far); // NOTE(andrey): 2.0f / (near - far) is the same as -2 / (far - near); The first one has less computation though.
		result.elements[3 + 3 * 4] = 1.0f;

		// last column
		result.elements[0 + 3 * 4] = -((right + left) / (right - left));
		result.elements[1 + 3 * 4] = -((top + bottom) / (top - bottom));
		result.elements[2 + 3 * 4] = -((far + near) / (far - near));
		//result.elements[3 + 3 * 4] = 1.0f;

		return result;

	}

	Matrix4 Matrix4::Perspective(float fov, float aspectRation, float near, float far)
	{
		Matrix4 result;

		float q = 1.0f / tan(ToRadians(0.5f * fov));
		float a = q / aspectRation;
		float b = (near + far) / (near - far); // NOTE(andrey): (near + far) / (near - far) is the same as -((far + near) / (far - near)).
		float c = (2.0f * near * far) / (near - far); // NOTE(andrey): 2.0f * near * far) / (near - far);

		// diagonal
		result.elements[0 + 0 * 4] = a;
		result.elements[1 + 1 * 4] = q;
		result.elements[2 + 2 * 4] = b;
		//result.elements[3 + 3 * 4] = 0.0f;

		// element in the third column
		result.elements[3 + 2 * 4] = -1.0f;

		// last column
		result.elements[2 + 3 * 4] = c;

		return result;
	}

	Matrix4 Matrix4::Translate(const Vector3& translation)
	{
		Matrix4 result(1.0f);

		result.elements[0 + 3 * 4] = translation.X;
		result.elements[1 + 3 * 4] = translation.Y;
		result.elements[2 + 3 * 4] = translation.Z;

		return result;
	}

	Matrix4 Matrix4::Rotate(const float angle, const Vector3& axis)
	{
		Matrix4 result(1.0f);

		float r = ToRadians(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1.0f - c;

		float x = axis.X;
		float y = axis.Y;
		float z = axis.Z;

		// first column
		result.elements[0 + 0 * 4] = x * x * omc + c;
		result.elements[0 + 1 * 4] = y * x * omc + z * s;
		result.elements[0 + 2 * 4] = x * z * omc - y * s;

		// second column
		result.elements[1 + 0 * 4] = x * y * omc - z * s;
		result.elements[1 + 1 * 4] = y * y * omc + c;
		result.elements[1 + 2 * 4] = y * z * omc + x * s;

		// third column
		result.elements[2 + 0 * 4] = x * z * omc + y * s;
		result.elements[2 + 1 * 4] = y * z * omc - x * s;
		result.elements[2 + 2 * 4] = z * z * omc + c;

		return result;
	}

	Matrix4 Matrix4::Scale(const Vector3& scale)
	{
		Matrix4 result;

		result.elements[0 + 0 * 4] = scale.X;
		result.elements[1 + 1 * 4] = scale.Y;
		result.elements[2 + 2 * 4] = scale.Z;
		result.elements[3 + 3 * 4] = 1.0f;

		return result;
	}

	// visualization
	std::ostream& operator<<(std::ostream& stream, const Matrix4& m)
	{
		stream  << std::endl
			<< m.elements[0 + 0 * 4] << std::setw(10) << m.elements[0 + 1 * 4] << std::setw(10) << m.elements[0 + 2 * 4] << std::setw(10) << m.elements[0 + 3 * 4] << std::endl
			<< m.elements[1 + 0 * 4] << std::setw(10) << m.elements[1 + 1 * 4] << std::setw(10) << m.elements[1 + 2 * 4] << std::setw(10) << m.elements[1 + 3 * 4] << std::endl
			<< m.elements[2 + 0 * 4] << std::setw(10) << m.elements[2 + 1 * 4] << std::setw(10) << m.elements[2 + 2 * 4] << std::setw(10) << m.elements[2 + 3 * 4] << std::endl
			<< m.elements[3 + 0 * 4] << std::setw(10) << m.elements[3 + 1 * 4] << std::setw(10) << m.elements[3 + 2 * 4] << std::setw(10) << m.elements[3 + 3 * 4] << std::endl;
		
		return stream;
	}

} }