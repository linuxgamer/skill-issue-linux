# Input Library

### > bool IsButtonDown(int button)

### > bool IsButtonPressed(int button)

### > bool IsButtonReleased(int button)

### > void SetCursorAlwaysVisible(bool state)

### > bool IsCursorVisible()

### > int GetPollTick()

### > bool IsButtonValid()

## Examples

```cpp
void main()
{
	print(format("{}", Input::IsCursorVisible()));
}
```