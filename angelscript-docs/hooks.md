# Hooks

You can register a callback for a hook here.

They are called when the real function is being called, so you can modify the data or do something before it runs

### CalcViewModelView ( position: **Vector3**, angle: **Vector3** )
Called before drawing the Viewmodel

### LevelInitPreEntity ( mapName: **string** )
Called before receiving the first entity packet

### LevelInitPostEntity ( )
Called after receiving the first entity packet

### LevelShutdown ( )
Called when leaving a match

### CreateMove ( cmd: **UserCmd** )
Called when the game wants to create a movement command

### DoPostScreenSpaceEffects ( )
Called when the game wants to create screen effects

You can use this to make custom bloom, glow, etc

### Draw ( )
Called before drawing stuff to the screen

### DrawModel ( ctx: **DrawModelContext** )
Called before the game draws a model

You can use this to change how a model is drawn: their color, material, transparency, etc

You can use this to change the info we are sending to the server

### FrameStageNotify ( stage: **int** )
Called at various stages of a frame

### FireGameEvent ( event: **GameEvent** )
Called when a game event is called. For example, when a player spawns

### OverrideView ( view: **ViewSetup** )
Called before drawing the localplayer's view

### GameShutdown ( )
Called before the game closes so you can do stuff like saving settings or something else before closing

## Examples

CalcViewModelView
```cpp
void CalcViewModelView(Vector position, Vector angle)
{
	print(format("position: {}, {}, {}; angle: {}, {}, {}", position.x, position.y, position.z, angle.x, angle.y, angle.z));
}

Hooks::Add("CalcViewModelView", "damn", @CalcViewModelView);
```

LevelInitPreEntity
```cpp
void InitPreEntity(string mapName)
{
	print(format("Map is {}", mapName));
}

Hooks::Add("LevelInitPreEntity", "hi", @InitPreEntity);
```

LevelInitPostEntity
```cpp
void InitPostEntity()
{
	print(format("There are {} players in the server right now", Engine::GetMaxClients()));
}

Hooks::Add("LevelInitPostEntity", "lol", @InitPostEntity);
```

LevelShutdown
```cpp
void OnLeavingMatch()
{
	print("Leaving match :(");
}

Hooks::Add("LevelShutdown", "sad", @OnLeavingMatch);
```

CreateMove
```cpp
void OnCreateMove(UserCmd@ cmd)
{
	Entity@ localplayer = EntityList::GetLocalPlayer();

	if (localplayer is null)
		return;

	Vector vel = localplayer.EstimateAbsVelocity();
	print(format("Velocity: {}, {}, {}", vel.x, vel.y, vel.z));
}

hooks.Add("CreateMove", "damn", @OnCreateMove)
```

DoPostScreenSpaceEffects
```cpp
void DPSSE()
{
	foreach (Entity@ ent : EntityList::GetEntities())
	{
		print(format("{}", ent.ShouldDraw()));
	}
}

Hooks::Add("DoPostScreenSpaceEffects", "lolo", @DPSSE);
```

DrawModel
```cpp
void DrawModel(DrawModelContext@ ctx)
{
	Entity@ ent = ctx.GetEntity();
	if (ent is null || !ent.IsPlayer())
		return;

	Render::SetColorModulation(1, 0, 0);
	Render::SetBlend(0.5f);
}

Hooks::Add("DrawModel", "beautiful", @DrawModel);
```