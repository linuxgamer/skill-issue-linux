# Engine Library

### > void PlaySound(string sound)

### > void ClientCmd(string cmd, bool unrestricted)

### > int GetMaxClients()

### > bool IsInGame()

### > bool IsConnected()

### > Vector GetViewAngles()

### > void SetViewAngles(Vector &angle)

### > bool WorldToScreen(const Vector worldPos, Vector &out outPos)

### > bool IsGameUIVisible()

### > bool IsConsoleVisible()

### > bool IsTakingScreenshot()

## Examples

```cpp
void main()
{
	print(format("{}", Engine::IsTakingScreenshot()));
	print(format("{}", Engine::IsInGame()));
}
```