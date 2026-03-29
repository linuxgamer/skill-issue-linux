# Material Class

### > string GetName()

### > string GetTextureGroupName()

### > bool IsTranslucent() const

### > void SetMaterialVarFlag(int flag, bool on)

### > bool GetMaterialVarFlag(int flag)

### > void SetColorModulation(float r, float g, float b)

### > void SetAlphaModulation(float a)

### > float GetAlphaModulation()

### > void GetColorModulation(float &out r, float &out g, float &out b)

### > bool IsErrorMaterial()
Checks if the material is valid

### > bool Delete()
Should be called when the material is not used anymore

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

	print(format("{}", mat.IsTranslucent()));
	mat.Delete();
}
```