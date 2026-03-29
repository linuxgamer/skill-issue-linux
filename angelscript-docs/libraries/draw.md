# Draw Library

### > void Line(int x0, int y0, int x1, int y1)

### > void SetColor(int r, int g, int b, int a)

### > void GetTextSize(string text, int &out w, int &out h)

### > void GetCursorPos(int &out x, int &out y)

### > void SetCursorPos(int x, int y)

### > void Circle(int x, int y, int radius, int segments)

### > bool HasFocus()

### > void GetScreenSize(int &out w, int &out h)

### > bool CreateFont(string name, string family, int height, int weight, int flags)

### > bool SetFont(string name)

### > void Rect(int x, int y, int w, int h)

### > void RectFade(int x0, int y0, int x1, int y1, int alpha0, int alpha1, bool bHorizontal)

### > bool IsCursorVisible()

## Examples

```cpp
void OnDraw()
{
	Draw::SetColor(255, 255, 255, 255);
	Draw::Rect(0, 0, 100, 100);
}

void main()
{
	Hooks::Add("Draw", "cool rectangle", @OnDraw);
}
```