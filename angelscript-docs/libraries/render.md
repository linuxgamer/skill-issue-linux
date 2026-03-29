# Render Library

### > void GetColorModulation(float &out r, float &out g, float &out b)

### > void SetColorModulation(float r, float g, float b)

### > float GetBlend()

### > void SetBlend(float blend)

### > void ForcedMaterialOverride(Material@ mat)

### > Material@ GetMaterialOverride()

### > void DrawScreenSpaceRectangle(Material@, int, int, int, int, float, float, float, float, int, int)

### > void DrawScreenSpaceQuad(Material@)

### > void GetViewport(int &out, int &out, int &out, int &out)

### > void Viewport(int, int, int, int)

### > void DepthRange(float, float)

### > bool GetDepthRange(float &out, float &out)

### > void SetRenderTarget(Texture@)

### > Texture@ GetRenderTarget()

### > void PushRenderTargetAndViewport()

### > void PopRenderTargetAndViewport()

### > void ClearBuffers(bool, bool, bool = false)

### > void ClearColor3ub(uint, uint, uint)

### > void ClearColor4ub(uint, uint, uint, uint)

### > void OverrideDepthEnable(bool, bool)

### > void OverrideAlphaEnable(bool, bool)

### > void OverrideColorEnable(bool, bool)

### > void SetStencilEnable(bool)

### > void SetStencilFailOperation(int)

### > void SetStencilZFailOperation(int)

### > void SetStencilPassOperation(int)

### > void SetStencilCompareFunction(int)

### > void SetStencilReferenceValue(int)

### > void SetStencilTestMask(uint)

### > void SetStencilWriteMask(uint)

### > void ClearStencilBufferRectangle(int, int, int, int, int)

## Examples

```cpp
void OnDrawModel(DrawModelContext@ ctx)
{
	Render::SetColorModulation(1.0f, 0.0f, 0.0f);
	Render::SetBlend(0.5f);
}

void main()
{
	Hooks::Add("DrawModel", "cool", @OnDrawModel);
}
```