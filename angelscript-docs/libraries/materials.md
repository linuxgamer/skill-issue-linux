# Materials Library

### > Material@ CreateMaterial(string name, string vmt)

### > Material@ GetMaterial(string name)

### > Texture@ CreateTextureNamedRenderTarget(string name, int width, int height)

## Examples

```cpp
void main()
{
	Material@ mat = Materials::CreateMaterial("CoolMat", 
	"""
	UnlitGeneric
	{
		$basetexture \"white\"
	}
	"""
	);

	print(format("{}", mat.GetName()));
}
```