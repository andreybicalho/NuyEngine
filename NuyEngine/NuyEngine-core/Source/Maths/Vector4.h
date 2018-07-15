#pragma once

#include <iostream>

namespace nuy { namespace maths {
	
	struct Vector4
	{
		float X, Y, Z, W;
		
		Vector4();
		Vector4(float scalar);
		Vector4(float x, float y, float z, float w);

		/** Global 3D zero vector constant (0,0,0,0) */
		static const Vector4 ZeroVector;

		/** Global 3D unit vector constant (1,1,1,1) */
		static const Vector4 UnitVector;
		
		Vector4 operator+(const Vector4& other) const;
		Vector4 operator-(const Vector4& other) const;
		Vector4 operator*(const Vector4& other) const;
		Vector4 operator/(const Vector4& other) const;

		Vector4 operator+(const float scalar) const;
		Vector4 operator-(const float scalar) const;
		Vector4 operator*(const float scalar) const;
		Vector4 operator/(const float scalar) const;

		Vector4 Add(const Vector4& other);
		Vector4 Subtract(const Vector4& other);
		Vector4 Multiply(const Vector4& other);
		Vector4 Divide(const Vector4& other);
		
		Vector4 operator+=(const Vector4& other);
		Vector4 operator-=(const Vector4& other);
		Vector4 operator*=(const Vector4& other);
		Vector4 operator/=(const Vector4& other);

		Vector4 operator+=(const float scalar);
		Vector4 operator-=(const float scalar);
		Vector4 operator*=(const float scalar);
		Vector4 operator/=(const float scalar);

		bool operator==(const Vector4& other) const;
		bool operator!=(const Vector4& other) const;

		bool operator<(const Vector4& other) const;
		bool operator<=(const Vector4& other) const;
		bool operator>(const Vector4& other) const;
		bool operator>=(const Vector4& other) const;

		friend std::ostream& operator<<(std::ostream& stream, const Vector4& vector);
		
	};

} }