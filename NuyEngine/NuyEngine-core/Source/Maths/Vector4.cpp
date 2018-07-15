#include "Vector4.h"

namespace nuy { namespace maths {
	
	// globals static initialization
	const Vector4 Vector4::ZeroVector(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4 Vector4::UnitVector(1.0f, 1.0f, 1.0f, 1.0f);

	Vector4::Vector4()
		: X(0.0f), Y(0.0f), Z(0.0f), W(0.0f)
	{
	}

	Vector4::Vector4(float scalar)
		: X(scalar), Y(scalar), Z(scalar), W(scalar)
	{
	}

	Vector4::Vector4(float x, float y, float z, float w)
		: X(x), Y(y), Z(z), W(w)
	{
	}

	// arithmetics
	Vector4 Vector4::operator+(const Vector4& other) const
	{
		return Vector4(X + other.X, Y + other.Y, Z + other.Z, W + other.W);
	}

	Vector4 Vector4::operator+(const float scalar) const
	{
		return Vector4(X + scalar, Y + scalar, Z + scalar, W + scalar);
	}

	Vector4 Vector4::operator-(const Vector4& other) const
	{
		return Vector4(X - other.X, Y - other.Y, Z - other.Z, W - other.W);
	}

	Vector4 Vector4::operator-(const float scalar) const
	{
		return Vector4(X - scalar, Y - scalar, Z - scalar, W - scalar);
	}

	Vector4 Vector4::operator*(const Vector4& other) const
	{
		return Vector4(X * other.X, Y * other.Y, Z * other.Z, W * other.W);
	}

	Vector4 Vector4::operator*(const float scalar) const
	{
		return Vector4(X * scalar, Y * scalar, Z * scalar, W * scalar);
	}

	Vector4 Vector4::operator/(const Vector4& other) const
	{
		return Vector4(X / other.X, Y / other.Y, Z / other.Z, W / other.W);
	}
	
	Vector4 Vector4::operator/(const float scalar) const
	{
		return Vector4(X / scalar, Y / scalar, Z / scalar, W / scalar);
	}

	Vector4 Vector4::Add(const Vector4& other)
	{
		X += other.X;
		Y += other.Y;
		Z += other.Z;
		W += other.W;

		return *this;
	}

	Vector4 Vector4::Subtract(const Vector4& other)
	{
		X -= other.X;
		Y -= other.Y;
		Z -= other.Z;
		W -= other.W;

		return *this;
	}

	Vector4 Vector4::Multiply(const Vector4& other)
	{
		X *= other.X;
		Y *= other.Y;
		Z *= other.Z;
		W *= other.W;

		return *this;
	}

	Vector4 Vector4::Divide(const Vector4& other)
	{
		X /= other.X;
		Y /= other.Y;
		Z /= other.Z;
		W /= other.W;

		return *this;
	}

	Vector4 Vector4::operator+=(const float scalar)
	{
		X += scalar;
		Y += scalar;
		Z += scalar;
		W += scalar;

		return *this;
	}

	Vector4 Vector4::operator-=(const float scalar)
	{
		X -= scalar;
		Y -= scalar;
		Z -= scalar;
		W -= scalar;

		return *this;
	}

	Vector4 Vector4::operator*=(const float scalar)
	{
		X *= scalar;
		Y *= scalar;
		Z *= scalar;
		W *= scalar;

		return *this;
	}

	Vector4 Vector4::operator/=(const float scalar)
	{
		X /= scalar;
		Y /= scalar;
		Z /= scalar;
		W /= scalar;

		return *this;
	}

	Vector4 Vector4::operator+=(const Vector4& other)
	{
		return Add(other);
	}

	Vector4 Vector4::operator-=(const Vector4& other)
	{
		return Subtract(other);
	}

	Vector4 Vector4::operator*=(const Vector4& other)
	{
		return Multiply(other);
	}

	Vector4 Vector4::operator/=(const Vector4& other)
	{
		return Divide(other);
	}


	// logic
	bool Vector4::operator==(const Vector4& other) const
	{
		return X == other.X && Y == other.Y && Z == other.Z && W == other.W;
	}

	bool Vector4::operator!=(const Vector4& other) const
	{
		return !(*this == other);
	}

	bool Vector4::operator<(const Vector4 & other) const
	{
		return X < other.X && Y < other.Y && Z < other.Z && W < other.W;
	}
	
	bool Vector4::operator<=(const Vector4& other) const
	{
		return X <= other.X && Y <= other.Y && Z <= other.Z && W <= other.W;
	}

	bool Vector4::operator>(const Vector4& other) const
	{
		return X > other.X && Y > other.Y && Z > other.Z && W > other.W;
	}

	bool Vector4::operator>=(const Vector4& other) const
	{
		return X >= other.X && Y >= other.Y && Z >= other.Z && W >= other.W;
	}

	// visualization
	std::ostream& operator<<(std::ostream& stream, const Vector4& vector)
	{
		stream << "Vector4: (" << vector.X << ", " << vector.Y << ", " << vector.Z << ", " << vector.W << ")";
		return stream;
	}

} }