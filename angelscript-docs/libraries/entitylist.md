# Entity List Library

### > Entity@ GetClientEntity(int entindex)

### > int GetMaxEntities()

### > Entity@ GetLocalPlayer()

### > array<Entity@>@ GetEntities()

## Examples

```cpp
void main()
{
	Entity@ localPlayer = EntityList::GetLocalPlayer();
	if (localPlayer is null)
	{
		warn("LocalPlayer is null!");
		return;
	}

	print(format("health: {}", localPlayer.GetHealth()));
}
```

Entities Array Loop
```cpp
void main()
{
	auto entities = EntityList::GetEntities();

	foreach(Entity@ ent : entities)
	{
		if (ent is null)
			continue;

		print(format("{}", ent.GetIndex()));
	}
}
```