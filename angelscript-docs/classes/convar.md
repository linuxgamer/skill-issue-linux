# ConVar Class

### > int GetInt()

### > float GetFloat()

### > bool GetBool()

### > string GetString()

### > void SetValue(const string &in value)

### > void SetValue(float value)

### > void SetValue(int value)

### > void SetValue(bool value)

## Examples

```cpp
void main()
{
	ConVar@ sv_cheats = Client::GetConVar("sv_cheats");
	if (sv_cheats is null) return;

	print(format("sv_cheats is {}", sv_cheats.GetBool()));

	sv_cheats.SetValue(true);

	print(format("sv_cheats is {}", sv_cheats.GetBool()));
}
```