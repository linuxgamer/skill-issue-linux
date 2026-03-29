# Client Library

### > ConVar@ GetConVar(string name)
Will return **null** if the ConVar is not found

### > void Command(string text, bool unrestricted = false)

### > void ClearConsole()
Clears the console

## Examples

```cpp
void main()
{
	ConVar@ sv_cheats = Client::GetConVar("sv_cheats");
	print(format("sv_cheats is {}", sv_cheats.GetBool()));
}
```