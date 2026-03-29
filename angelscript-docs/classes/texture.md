# Texture Class

### > bool Delete()

### > string GetName()

### > uint GetFlags()

### > int GetActualWidth()

### > int GetActualHeight()

### > bool IsTranslucent()

### > bool IsRenderTarget()

## Examples

```cpp
void main()
{
	Texture@ tex = Materials::CreateTextureNamedRenderTarget("im cool", 1920, 1080);
	if (tex is null) return;
	
	print(tex.GetName());
	tex.Delete();
}
```