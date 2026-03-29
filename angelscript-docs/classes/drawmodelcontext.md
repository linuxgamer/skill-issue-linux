# DrawModelContext Class

### > int GetEntityIndex()

### > bool IsChams()

### > bool IsGlow()

### > void Execute()

## Examples

```cpp
void OnDrawModel(DrawModelContext@ ctx)
{
	int entindex = ctx.GetEntityIndex();
	if (entindex == -1) return;

	Entity@ ent = EntityList::ClientEntity(entindex);
	if (ent is null) return;

	if (ent.IsPlayer() && !ctx.IsGlow() && !ctx.IsChams())
	{
		Render::SetColorModulation(1, 0, 0);
	}
}

void main()
{
	Hooks::Add("DrawModel", "lolo", @OnDrawModel);
}
```