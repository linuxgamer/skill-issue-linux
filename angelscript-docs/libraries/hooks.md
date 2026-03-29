# Hooks Library

### > bool Add(string event, const string &in id, Function @cb)

### > bool Remove(string event, string id)

## Examples

```cpp
void OnCreateMove(UserCmd@ cmd)
{
	print(format("{}", cmd.buttons));
}

void main()
{
	Hooks::Remove("CreateMove", "damn");
	Hooks::Add("CreateMove", "damn", @OnCreateMove);
}
```