#pragma once

#include <iostream>

namespace nuy { namespace maths {
	
	struct Vector3
	{
		float X, Y, Z;
		
		Vector3();
		Vector3(float scalar);
		Vector3(float x, float y, float z);

		/** Global 3D zero vector constant (0,0,0) */
		static const Vector3 ZeroVector;

		/** Global 3D unit vector constant (1,1,1) */
		static const Vector3 UnitVector;
		
		Vector3 operator+(const Vector3& other) const;
		Vector3 operator-(const Vector3& other) const;
		Vector3 operator*(const Vector3& other) const;
		Vector3 operator/(const Vector3& other) const;

		Vector3 operator+(const float scalar) const;
		Vector3 operator-(const float scalar) const;
		Vector3 operator*(const float scalar) const;
		Vector3 operator/(const float scalar) const;

		Vector3& Add(const Vector3& other);
		Vector3& Subtract(const Vector3& other);
		Vector3& Multiply(const Vector3& other);
		Vector3& Divide(const Vector3& other);
		
		Vector3& operator+=(const Vector3& other);
		Vector3& operator-=(const Vector3& other);
		Vector3& operator*=(const Vector3& other);
		Vector3& operator/=(const Vector3& other);

		Vector3& operator+=(const float scalar);
		Vector3& operator-=(const float scalar);
		Vector3& operator*=(const float scalar);
		Vector3& operator/=(const float scalar);

		bool operator==(const Vector3& other) const;
		bool operator!=(const Vector3& other) const;

		bool operator<(const Vector3& other) const;
		bool operator<=(const Vector3& other) const;
		bool operator>(const Vector3& other) const;
		bool operator>=(const Vector3& other) const;

		friend std::ostream& operator<<(std::ostream& stream, const Vector3& vector);
		
	};

} }