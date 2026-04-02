# Entity Class

### > int GetHealth()

### > int GetMaxHealth()

### > bool IsPlayer()

### > bool IsWeapon()

### > int GetIndex()

### > bool IsPlayer()

### > bool IsBuilding()

### > int GetClassID()

### > bool IsRobot()

### > Vector EstimateAbsVelocity()

### > bool IsProjectile()

### > int GetPropInt(string className, string propName)

### > float GetPropFloat(string className, string propName)

### > bool GetPropBool(string className, string propName)

### > Vector GetPropVector(string className, string propName)

### > Entity@ GetPropEntity(string className, string propName)

### > void SetPropInt(string className, string propName, int value)

### > void SetPropFloat(string className, string propName, float value)

### > void SetPropBool(string className, string propName, bool value)

### > void SetPropVector(string className, string propName, Vector value)

### > void SetPropEntity(string className, string propName, Entity@ value)

### > Vector GetAbsOrigin()

### > Vector GetAbsAngles()

### > bool ShouldDraw()

### > Entity@ GetFirstMoveChild()

### > Entity@ GetNextMovePeer()

### > void DrawModel(int flags)

### > int GetTeamNumber()

### > bool IsAlive()

### > int GetMoveType()

### > bool InCond(int cond)

### > string GetClassName()
CTFViewModel, CTFPlayer, etc.

### > string GetName()

### > Entity@ GetWeaponFromSlot(int index)

## Examples

```cpp
void main()
{
	Entity@ pLocal = EntityList::GetLocalPlayer();
	if (pLocal is null) return;

	print(format("{}", pLocal.IsAlive()));
}
```