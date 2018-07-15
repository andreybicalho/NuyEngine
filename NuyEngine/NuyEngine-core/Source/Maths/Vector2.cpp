#include "Vector2.h"

namespace nuy { namespace maths {
	
	// globals static initialization
	const Vector2 Vector2::ZeroVector(0.0f, 0.0f);
	const Vector2 Vector2::UnitVector(1.0f, 1.0f);

	Vector2::Vector2()
		: X(0.0f), Y(0.0f)
	{
	}

	Vector2::Vector2(float scalar)
		: X(scalar), Y(scalar)
	{
	}

	Vector2::Vector2(float x, float y)
		: X(x), Y(y)
	{
	}

	// arithmetics
	Vector2 Vector2::operator+(const Vector2& other) const
	{
		return Vector2(X + other.X, Y + other.Y);
	}

	Vector2 Vector2::operator+(const float scalar) const
	{
		return Vector2(X + scalar, Y + scalar);
	}

	Vector2 Vector2::operator-(const Vector2& other) const
	{
		return Vector2(X - other.X, Y - other.Y);
	}

	Vector2 Vector2::operator-(const float scalar) const
	{
		return Vector2(X - scalar, Y - scalar);
	}

	Vector2 Vector2::operator*(const Vector2& other) const
	{
		return Vector2(X * other.X, Y * other.Y);
	}

	Vector2 Vector2::operator*(const float scalar) const
	{
		return Vector2(X * scalar, Y * scalar);
	}

	Vector2 Vector2::operator/(const Vector2& other) const
	{
		return Vector2(X / other.X, Y / other.Y);
	}
	
	Vector2 Vector2::operator/(const float scalar) const
	{
		return Vector2(X / scalar, Y / scalar);
	}

	Vector2 Vector2::Add(const Vector2& other)
	{
		X += other.X;
		Y += other.Y;

		return *this;
	}

	Vector2 Vector2::Subtract(const Vector2& other)
	{
		X -= other.X;
		Y -= other.Y;

		return *this;
	}

	Vector2 Vector2::Multiply(const Vector2& other)
	{
		X *= other.X;
		Y *= other.Y;

		return *this;
	}

	Vector2 Vector2::Divide(const Vector2& other)
	{
		X /= other.X;
		Y /= other.Y;

		return *this;
	}

	Vector2 Vector2::operator+=(const float scalar)
	{
		X += scalar;
		Y += scalar;

		return *this;
	}

	Vector2 Vector2::operator-=(const float scalar)
	{
		X -= scalar;
		Y -= scalar;

		return *this;
	}

	Vector2 Vector2::operator*=(const float scalar)
	{
		X *= scalar;
		Y *= scalar;

		return *this;
	}

	Vector2 Vector2::operator/=(const float scalar)
	{
		X /= scalar;
		Y /= scalar;

		return *this;
	}

	Vector2 Vector2::operator+=(const Vector2& other)
	{
		return Add(other);
	}

	Vector2 Vector2::operator-=(const Vector2& other)
	{
		return Subtract(other);
	}

	Vector2 Vector2::operator*=(const Vector2& other)
	{
		return Multiply(other);
	}

	Vector2 Vector2::operator/=(const Vector2& other)
	{
		return Divide(other);
	}


	// logic
	bool Vector2::operator==(const Vector2& other) const
	{
		return X == other.X && Y == other.Y;
	}

	bool Vector2::operator!=(const Vector2& other) const
	{
		return !(*this == other);
	}

	bool Vector2::operator<(const Vector2 & other) const
	{
		return X < other.X && Y < other.Y;
	}
	
	bool Vector2::operator<=(const Vector2& other) const
	{
		return X <= other.X && Y <= other.Y;
	}

	bool Vector2::operator>(const Vector2& other) const
	{
		return X > other.X && Y > other.Y;
	}

	bool Vector2::operator>=(const Vector2& other) const
	{
		return X >= other.X && Y >= other.Y;
	}

	// visualization
	std::ostream& operator<<(std::ostream& stream, const Vector2& vector)
	{
		stream << "Vector2: (" << vector.X << ", " << vector.Y << ")";
		return stream;
	}

} }