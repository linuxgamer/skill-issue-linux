# ClientState Library

### > int GetChokedCommands()

### > int GetLastOutgoingCommand()

### > int GetLastCommandAck()

### > int GetClientSignonState()

### > int GetDeltaTick()

### > void ForceFullUpdate()

## Examples

```cpp
void main()
{
	int chokedcommands = ClientState::GetChokedCommands();
	print(format("choked: {}", chokedcommands));
}
```