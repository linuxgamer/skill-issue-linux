# Vector Class

## Constructor
### > Vector()
Returns a Vector with x, y and z as 0

### > Vector(float x, float y, float z)

## Fields

### > float x

### > float y

### > float z

## Methods

### > Vector To2D()

### > float Length() const

### > float LengthSqr() const

### > float Normalize() const

### > float Normalize2D() const

### > Vector Normalized()

### > Vector Normalized2D()

### > Vector Get2D()

### > float Length2D() const

### > float Length2DSqr() const

### > float DistTo() const

### > float DistTo2D() const

### > float DistToSqr() const

### > float DistTo2DSqr() const

### > float Dot()

### > Vector Cross()

### > bool IsZero() const

### > Vector ToAngle()

### > Vector FromAngle()

## Examples

```cpp
void main()
{
	Vector vecA = Vector(10, 5, 5);
	Vector vecB = Vector();
	print(format("{}", vecA.Dot(vecB)));
}
```