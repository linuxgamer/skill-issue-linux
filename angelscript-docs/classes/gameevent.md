# Game Event Class

### > bool IsLocal()

### > bool IsEmpty(string keyName)

### > bool GetBool(string keyName, bool defaultValue)

### > int GetInt(string keyName, int defaultValue)

### > float GetFloat(string keyName, float defaultValue)

### > string GetString(string keyName, string defaultValue)

### > void SetBool(string keyName, bool value)

### > void SetInt(string keyName, int value)

### > void SetFloat(string keyName, float value)

### > void SetString(string keyName, string value)

## Examples

```cpp
void OnFireGameEvent(GameEvent@ event)
{
	string name = event.GetName();
	print(format("{}", name));
}

void main()
{
	Hooks::Add("FireGameEvent", "nice", @OnFireGameEvent);
}
```