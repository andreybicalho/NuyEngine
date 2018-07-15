#pragma once

#include <iostream>

namespace nuy { namespace maths {
	
	struct Vector2
	{
		float X, Y;
		
		Vector2();
		Vector2(float scalar);
		Vector2(float x, float y);

		/** Global 2D zero vector constant (0,0) */
		static const Vector2 ZeroVector;

		/** Global 2D unit vector constant (1,1) */
		static const Vector2 UnitVector;
		
		Vector2 operator+(const Vector2& other) const;
		Vector2 operator-(const Vector2& other) const;
		Vector2 operator*(const Vector2& other) const;
		Vector2 operator/(const Vector2& other) const;

		Vector2 operator+(const float scalar) const;
		Vector2 operator-(const float scalar) const;
		Vector2 operator*(const float scalar) const;
		Vector2 operator/(const float scalar) const;

		Vector2& Add(const Vector2& other);
		Vector2& Subtract(const Vector2& other);
		Vector2& Multiply(const Vector2& other);
		Vector2& Divide(const Vector2& other);
		
		Vector2& operator+=(const Vector2& other);
		Vector2& operator-=(const Vector2& other);
		Vector2& operator*=(const Vector2& other);
		Vector2& operator/=(const Vector2& other);

		Vector2& operator+=(const float scalar);
		Vector2& operator-=(const float scalar);
		Vector2& operator*=(const float scalar);
		Vector2& operator/=(const float scalar);

		bool operator==(const Vector2& other) const;
		bool operator!=(const Vector2& other) const;

		bool operator<(const Vector2& other) const;
		bool operator<=(const Vector2& other) const;
		bool operator>(const Vector2& other) const;
		bool operator>=(const Vector2& other) const;

		friend std::ostream& operator<<(std::ostream& stream, const Vector2& vector);

		//String ToString() const;
	};

} }