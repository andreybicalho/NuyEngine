#include "Vector3.h"

namespace nuy { namespace maths {
	
	// globals static initialization
	const Vector3 Vector3::ZeroVector(0.0f, 0.0f, 0.0f);
	const Vector3 Vector3::UnitVector(1.0f, 1.0f, 1.0f);

	Vector3::Vector3()
		: X(0.0f), Y(0.0f), Z(0.0f)
	{
	}

	Vector3::Vector3(float scalar)
		: X(scalar), Y(scalar), Z(scalar)
	{
	}

	Vector3::Vector3(float x, float y, float z)
		: X(x), Y(y), Z(z)
	{
	}

	// arithmetics
	Vector3 Vector3::operator+(const Vector3& other) const
	{
		return Vector3(X + other.X, Y + other.Y, Z + other.Z);
	}

	Vector3 Vector3::operator+(const float scalar) const
	{
		return Vector3(X + scalar, Y + scalar, Z + scalar);
	}

	Vector3 Vector3::operator-(const Vector3& other) const
	{
		return Vector3(X - other.X, Y - other.Y, Z - other.Z);
	}

	Vector3 Vector3::operator-(const float scalar) const
	{
		return Vector3(X - scalar, Y - scalar, Z - scalar);
	}

	Vector3 Vector3::operator*(const Vector3& other) const
	{
		return Vector3(X * other.X, Y * other.Y, Z * other.Z);
	}

	Vector3 Vector3::operator*(const float scalar) const
	{
		return Vector3(X * scalar, Y * scalar, Z * scalar);
	}

	Vector3 Vector3::operator/(const Vector3& other) const
	{
		return Vector3(X / other.X, Y / other.Y, Z / other.Z);
	}
	
	Vector3 Vector3::operator/(const float scalar) const
	{
		return Vector3(X / scalar, Y / scalar, Z / scalar);
	}

	Vector3 Vector3::Add(const Vector3& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;

		return *this;
	}

	Vector3 Vector3::Subtract(const Vector3& other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;

		return *this;
	}

	Vector3 Vector3::Multiply(const Vector3& other)
	{
		X *= other.X;
		Y *= other.Y;
		Z *= other.Z;

		return *this;
	}

	Vector3 Vector3::Divide(const Vector3& other)
	{
		X /= other.X;
		Y /= other.Y;
		Z /= other.Z;

		return *this;
	}

	Vector3 Vector3::operator+=(const float scalar)
	{
		X += scalar;
		Y += scalar;
		Z += scalar;

		return *this;
	}

	Vector3 Vector3::operator-=(const float scalar)
	{
		X -= scalar;
		Y -= scalar;
		Z -= scalar;

		return *this;
	}

	Vector3 Vector3::operator*=(const float scalar)
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;

		return *this;
	}

	Vector3 Vector3::operator/=(const float scalar)
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;

		return *this;
	}

	Vector3 Vector3::operator+=(const Vector3& other)
	{
		return Add(other);
	}

	Vector3 Vector3::operator-=(const Vector3& other)
	{
		return Subtract(other);
	}

	Vector3 Vector3::operator*=(const Vector3& other)
	{
		return Multiply(other);
	}

	Vector3 Vector3::operator/=(const Vector3& other)
	{
		return Divide(other);
	}


	// logic
	bool Vector3::operator==(const Vector3& other) const
	{
		return X == other.X && Y == other.Y && Z == other.Z;
	}

	bool Vector3::operator!=(const Vector3& other) const
	{
		return !(*this == other);
	}

	bool Vector3::operator<(const Vector3 & other) const
	{
		return X < other.X && Y < other.Y && Z < other.Z;
	}
	
	bool Vector3::operator<=(const Vector3& other) const
	{
		return X <= other.X && Y <= other.Y && Z <= other.Z;
	}

	bool Vector3::operator>(const Vector3& other) const
	{
		return X > other.X && Y > other.Y && Z > other.Z;
	}

	bool Vector3::operator>=(const Vector3& other) const
	{
		return X >= other.X && Y >= other.Y && Z >= other.Z;
	}

	// visualization
	std::ostream& operator<<(std::ostream& stream, const Vector3& vector)
	{
		stream << "Vector3: (" << vector.X << ", " << vector.Y << ", " << vector.Z << ")";
		return stream;
	}

} }