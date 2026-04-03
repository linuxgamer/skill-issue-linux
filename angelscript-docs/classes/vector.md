# Vector Class

## Constructor
### > Vector3()
Returns a Vector with x, y and z as 0

### > Vector3(float x, float y, float z)

## Fields

### > float x

### > float y

### > float z

## Methods

### > Vector3 To2D()

### > float Length() const

### > float LengthSqr() const

### > float Normalize() const

### > float Normalize2D() const

### > Vector3 Normalized()

### > Vector3 Normalized2D()

### > Vector3 Get2D()

### > float Length2D() const

### > float Length2DSqr() const

### > float DistTo() const

### > float DistTo2D() const

### > float DistToSqr() const

### > float DistTo2DSqr() const

### > float Dot()

### > Vector3 Cross()

### > bool IsZero() const

### > Vector3 ToAngle()

### > Vector3 FromAngle()

## Examples

```cpp
void main()
{
	Vector3 vecA = Vector3(10, 5, 5);
	Vector3 vecB = Vector3();
	print(format("{}", vecA.Dot(vecB)));
}
```