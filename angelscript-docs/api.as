/*
	AngelScript official documentation:
	https://angelcode.com/angelscript/sdk/docs/manual/doc_script.html
*/

// gotta do ts to make it not complain about it being undefined
class string
{
	// https://angelcode.com/angelscript/sdk/docs/manual/doc_script_stdlib_string.html
	// https://angelcode.com/angelscript/sdk/docs/manual/doc_datatypes_strings.html
}

class array
{

}

float FLT_MIN = 1.175494e-38;

void print(const string &in text) const;
void warn(const string &in text) const;
bool Execute(const string &in text) const;

class Vector2
{
	float x;
	float y;

	Vector2() const;
	Vector2(float x, float y) const;

	float Length() const;
	float LengthSqr() const;
	float DistTo() const;
	float DistToSqr() const;
	float Dot() const;
	bool IsZero() const;
}

class Vector3
{
	float x;
	float y;
	float z;

	Vector3() const;
	Vector3(float x, float y, float z) const;

	Vector2 Get2D();
	Vector3 To2D();
	float Length() const;
	float LengthSqr() const;
	float Normalize() const;
	float Normalize2D() const;
	Vector3 Normalized();
	Vector3 Normalized2D();
	float Length2D() const;
	float Length2DSqr() const;
	float DistTo() const;
	float DistTo2D() const;
	float DistToSqr() const;
	float DistTo2DSqr() const;
	float Dot(Vector3 vec) const;
	Vector3 Cross();
	bool IsZero() const;
	Vector3 ToAngle();
	Vector3 FromAngle();

	Vector3& opAssign(const Vector3 &in) const;
	float& opIndex(int) const;
	float opIndex(int) const;
	bool opEquals(const Vector3 &in) const;
	bool opCmp(const Vector3 &in) const;
	bool opImplConv() const;
	Vector3& opAddAssign(const Vector3 &in) const;
	Vector3& opSubAssign(const Vector3 &in) const;
	Vector3& opMulAssign(const Vector3 &in) const;
	Vector3& opDivAssign(const Vector3 &in) const;
	Vector3& opAddAssign(float) const;
	Vector3& opSubAssign(float) const;
	Vector3& opMulAssign(float) const;
	Vector3& opDivAssign(float) const;
	Vector3 opAdd(const Vector3 &in) const;
	Vector3 opSub(const Vector3 &in) const;
	Vector3 opMul(const Vector3 &in) const;
	Vector3 opDiv(const Vector3 &in) const;
	Vector3 opAdd(float) const;
	Vector3 opSub(float) const;
	Vector3 opMul(float) const;
	Vector3 opDiv(float) const;
}

class ViewSetup
{
	int x;
	int m_nUnscaledX;
	int y;
	int m_nUnscaledY;
	int width;
	int m_nUnscaledWidth;
	int height;
	int m_nUnscaledHeight;
	bool m_bOrtho;
	float m_OrthoLeft;
	float m_OrthoTop;
	float m_OrthoRight;
	float m_OrthoBottom;
	float fov;
	float fovViewmodel;
	Vector3 origin;
	Vector3 angles;
	float zNear;
	float zFar;
	float zNearViewmodel;
	float zFarViewmodel;
	bool m_bRenderToSubrectOfLargerScreen;
	float m_flAspectRatio;
	bool m_bOffCenter;
	float m_flOffCenterTop;
	float m_flOffCenterBottom;
	float m_flOffCenterLeft;
	float m_flOffCenterRight;
	bool m_bDoBloomAndToneMapping;
	bool m_bCacheFullSceneState;
	bool m_bViewToProjectionOverride;
}

class UserCmd
{
	int command_number;
	int tick_count;
	Vector3 viewangles;
	float forwardmove;
	float sidemove;
	float upmove;
	int buttons;
	int impulse;
	int weaponselect;
	int weaponsubtype;
	int random_seed;
	int mousedx;
	int mousedy;
	bool hasbeenpredicted;

	bool GetSendPacket() const;
	void SetSendPacket(bool state) const;
}

class Texture
{
	bool Delete() const;
	string GetName();
	uint GetFlags() const;
	int GetActualWidth() const;
	int GetActualHeight() const;
	bool IsTranslucent() const;
	bool IsRenderTarget() const;
}

class Material
{
	string GetName() const;
	string GetTextureGroupName() const;
	bool IsTranslucent() const;
	void SetMaterialVarFlag(int flag, bool on) const;
	bool GetMaterialVarFlag(int flag) const;
	void SetColorModulation(float r, float g, float b) const;
	void SetAlphaModulation(float a) const;
	float GetAlphaModulation() const;
	void GetColorModulation(float &out r, float &out g, float &out b) const;
	bool IsErrorMaterial() const;
	bool Delete() const;
}

class GameEvent
{
	string GetName() const;
	bool IsLocal() const;
	bool IsEmpty( const string &in keyName) const;
	bool GetBool(const string &in keyName, bool defaultValue) const;
	int GetInt(const string &in keyName, int defaultValue) const;
	float GetFloat(const string &in keyName, float defaultValue) const;
	string GetString(const string &in keyName, const string &in defaultValue) const;
	void SetBool(const string &in keyName, bool value) const;
	void SetInt(const string &in keyName, int value) const;
	void SetFloat(const string &in keyName, float value) const;
	void SetString(const string &in keyName, const string &in value) const;
}

class Entity
{
	int GetHealth() const;
	int GetMaxHealth() const;
	bool IsPlayer() const;
	bool IsWeapon() const;
	int GetIndex() const;
	bool IsPlayer() const;
	bool IsBuilding() const;
	int GetClassID() const;
	bool IsRobot() const;
	Vector3 EstimateAbsVelocity() const;
	bool IsProjectile() const;
	int GetPropInt(const string &in className, const string &in propName) const;
	float GetPropFloat(const string &in className, const string &in propName) const;
	bool GetPropBool(const string &in className, const string &in propName) const;
	Vector3 GetPropVector(const string &in className, const string &in propName) const;
	Entity@ GetPropEntity(const string &in className, const string &in propName) const;
	void SetPropInt(const string &in className, const string &in propName, int value) const;
	void SetPropFloat(const string &in className, const string &in propName, float value) const;
	void SetPropBool(const string &in className, const string &in propName, bool value) const;
	void SetPropVector(const string &in className, const string &in propName, Vector3 value) const;
	void SetPropEntity(const string &in className, const string &in propName, Entity@ value) const;
	Vector3 GetAbsOrigin() const;
	Vector3 GetAbsAngles() const;
	bool ShouldDraw() const;
	Entity@ GetFirstMoveChild() const;
	Entity@ GetNextMovePeer() const;
	void DrawModel(int flags) const;
	int GetTeamNumber() const;
	bool IsAlive() const;
	int GetMoveType() const;
	bool InCond(int cond) const;
	string GetClassName() const;
	string GetName() const;
	Entity@ GetEntityFromLoadoutSlot(int index) const;
}

class DrawModelContext
{
	int GetEntityIndex() const;
	bool IsChams() const;
	bool IsGlow() const;
	void Execute() const;
}

class ConVar
{
	int GetInt() const;
	float GetFloat() const;
	bool GetBool() const;
	string GetString() const;
	void SetValue(const string &in value) const;
	void SetValue(float value) const;
	void SetValue(int value) const;
	void SetValue(bool value) const;
}

namespace Client
{
	ConVar@ GetConVar(const string &in name) const;
	void Command(const string &in text, bool unrestricted = false) const;
	void ClearConsole() const;
}

namespace ClientState
{
	int m_Socket;
	uint m_nChallengeNr;
	double m_flConnectTime;
	int m_nRetryNumber;
	int m_retryChallenge;
	int m_nSignonState;
	double m_flNextCmdTime;
	int m_nServerCount;
	uint64 m_ulGameServerSteamID;
	int m_nCurrentSequence;
	int m_nDeltaTick;
	bool m_bPaused;
	float m_flPausedExpireTime;
	int m_nViewEntity;
	int m_nPlayerSlot;
	int m_nMaxClients;
	bool m_bRestrictServerCommands;
	bool m_bRestrictClientCommands;
	bool insimulation;
	int oldtickcount;
	float m_tickRemainder;
	float m_frameTime;
	int lastoutgoingcommand;
	int chokedcommands;
	int last_command_ack;
	int command_ack;
	int m_nSoundSequence;
	bool ishltv;
	bool isreplay;
	int demonum;
	bool m_bMarkedCRCsUnverified;
}

namespace Draw
{
	void Line(int x0, int y0, int x1, int y1) const;
	void SetColor(int r, int g, int b, int a) const;
	void GetTextSize(const string &in text, int &out w, int &out h) const;
	void GetCursorPos(int &out x, int &out y) const;
	void SetCursorPos(int x, int y) const;
	void Circle(int x, int y, int radius, int segments) const;
	bool HasFocus() const;
	void GetScreenSize(int &out w, int &out h) const;
	bool CreateFont(const string &in name, const string &in family, int height, int weight, int flags) const;
	bool SetFont(const string &in name) const;
	void Rect(int x, int y, int w, int h) const;
	void RectFade(int x0, int y0, int x1, int y1, int alpha0, int alpha1, bool bHorizontal) const;
	bool IsCursorVisible() const;
}

namespace Engine
{
	void PlaySound(const string &in sound) const;
	void ClientCmd(const string &in cmd, bool unrestricted) const;
	int GetMaxClients() const;
	bool IsInGame() const;
	bool IsConnected() const;
	Vector3 GetViewAngles() const;
	void SetViewAngles(Vector3 &in angle) const;
	bool WorldToScreen(const Vector3 &in worldPos, Vector2 &out outPos) const;
	bool IsGameUIVisible() const;
	bool IsConsoleVisible() const;
	bool IsTakingScreenshot() const;
}

namespace EnttyList
{
	Entity@ GetClientEntity(int entindex) const;
	int GetMaxEntities() const;
	Entity@ GetLocalPlayer() const;
	array<Entity@>@ GetEntities() const;
}

namespace GlobalVars
{
	float realtime;
	int framecount;
	float absolute_frametime;
	float curtime;
	float frametime;
	int max_clients;
	int tickcount;
	float interval_per_tick;
	float interpolation_amount;
	int sim_ticks_this_frame;
	int network_protocol;
	bool client;
	int nTimestampNetworkingBase;
	int nTimestampRandomizeWindow;
}

funcdef void CreateMoveHook(UserCmd@ cmd);
funcdef void OverrideViewHook(ViewSetup@ view);
funcdef void CalcViewModelHook(Vector3 position, Vector3 angle);
funcdef void GenericHook();
funcdef void LevelInitPreEntHook(const string &in mapName);
funcdef void DrawModelHook(DrawModelContext@ ctx);
funcdef void FireGameEventHook(GameEvent@ event);

namespace Hooks
{
	bool Add(const string &in event, const string &in id, CreateMoveHook @cb) const;
	bool Add(const string &in event, const string &in id, GenericHook @cb) const;
	bool Add(const string &in event, const string &in id, CalcViewModelHook @cb) const;
	bool Add(const string &in event, const string &in id, OverrideViewHook @cb) const;
	bool Add(const string &in event, const string &in id, LevelInitPreEntHook @cb) const;
	bool Add(const string &in event, const string &in id, DrawModelHook @cb) const;
	bool Add(const string &in event, const string &in id, FireGameEventHook @cb) const;
	bool Remove(const string &in event, const string &in id) const;
}

namespace ImGui
{
	bool Begin(const string &in name, bool &out p_open, int flags = 0) const;
	bool Begin(const string &in name, int flags = 0) const;
	void End() const;
	bool BeginChild(const string &in str_id, const Vector2 &in size = Vector2(0, 0), int child_flags = 0, int window_flags = 0) const;
	bool BeginChild(uint id, const Vector2 &in size = Vector2(0, 0), int child_flags = 0, int window_flags = 0) const;
	void EndChild() const;
	bool IsWindowAppearing() const;
	bool IsWindowCollapsed() const;
	bool IsWindowFocused(int flags = 0) const;
	bool IsWindowHovered(int flags = 0) const;
	Vector2 GetWindowPos() const;
	Vector2 GetWindowSize() const;
	float GetWindowWidth() const;
	float GetWindowHeight() const;
	void SetNextWindowPos(const Vector2 &in pos, int cond = 0, const Vector2 &in pivot = Vector2(0, 0)) const;
	void SetNextWindowSize(const Vector2 &in size, int cond = 0) const;
	void SetNextWindowContentSize(const Vector2 &in size) const;
	void SetNextWindowCollapsed(bool collapsed, int cond = 0) const;
	void SetNextWindowFocus() const;
	void SetNextWindowScroll(const Vector2 &in scroll) const;
	void SetNextWindowBgAlpha(float alpha) const;
	void SetWindowPos(const Vector2 &in pos, int cond = 0) const;
	void SetWindowSize(const Vector2 &in size, int cond = 0) const;
	void SetWindowCollapsed(bool collapsed, int cond = 0) const;
	void SetWindowFocus() const;
	void SetWindowPos(const string &in name, const Vector2 &in pos, int cond = 0) const;
	void SetWindowSize(const string &in name, const Vector2 &in size, int cond = 0) const;
	void SetWindowCollapsed(const string &in name, bool collapsed, int cond = 0) const;
	void SetWindowFocus(const string &in name) const;
	float GetScrollX() const;
	float GetScrollY() const;
	void SetScrollX(float scroll_x) const;
	void SetScrollY(float scroll_y) const;
	float GetScrollMaxX() const;
	float GetScrollMaxY() const;
	void SetScrollHereX(float center_x_ratio = 0.5f) const;
	void SetScrollHereY(float center_y_ratio = 0.5f) const;
	void SetScrollFromPosX(float local_x, float center_x_ratio = 0.5f) const;
	void SetScrollFromPosY(float local_y, float center_y_ratio = 0.5f) const;
	Vector2 GetFontTexUvWhitePixel() const;
	uint GetColorU32(int idx, float alpha_mul = 1.0f) const;
	uint GetColorU32(float r, float g, float b, float a) const;
	void GetStyleColorVec4(int idx, float &out r, float &out g, float &out b, float &out a) const;
	Vector2 GetCursorScreenPos() const;
	void SetCursorScreenPos(const Vector2 &in pos) const;
	Vector2 GetContentRegionAvail() const;
	Vector2 GetCursorPos() const;
	float GetCursorPosX() const;
	float GetCursorPosY() const;
	void SetCursorPos(const Vector2 &in local_pos) const;
	void SetCursorPosX(float local_x) const;
	void SetCursorPosY(float local_y) const;
	Vector2 GetCursorStartPos() const;
	void Separator() const;
	void SameLine(float offset_from_start_x = 0.0f, float spacing = -1.0f) const;
	void NewLine() const;
	void Spacing() const;
	void Dummy(const Vector2 &in size) const;
	void Indent(float indent_w = 0.0f) const;
	void Unindent(float indent_w = 0.0f) const;
	void BeginGroup() const;
	void EndGroup() const;
	void AlignTextToFramePadding() const;
	float GetTextLineHeight() const;
	float GetTextLineHeightWithSpacing() const;
	float GetFrameHeight() const;
	float GetFrameHeightWithSpacing() const;
	void TextUnformatted(const string &in text) const;
	void TextColored(int r, int g, int b, int a, const string &in fmt) const;
	void TextDisabled(const string &in fmt) const;
	void TextWrapped(const string &in fmt) const;
	void LabelText(const string &in label, const string &in fmt) const;
	void BulletText(const string &in fmt) const;
	void SeparatorText(const string &in label) const;
	bool Button(const string &in label, const Vector2 &in size = Vector2(0, 0)) const;
	bool SmallButton(const string &in label) const;
	bool InvisibleButton(const string &in str_id, const Vector2 &in size, int flags = 0) const;
	bool ArrowButton(const string &in str_id, int dir) const;
	bool Checkbox(const string &in label, bool &out v) const;
	bool CheckboxFlags(const string &in label, int &out flags, int flags_value) const;
	bool CheckboxFlags(const string &in label, uint &out flags, uint flags_value) const;
	bool RadioButton(const string &in label, bool active) const;
	bool RadioButton(const string &in label, int &out v, int v_button) const;
	void ProgressBar(float fraction, const Vector2 &in size_arg = Vector2(-FLT_MIN, 0)) const;
	void ProgressBar(float fraction, const Vector2 &in size_arg = Vector2(-FLT_MIN, 0), const string &in overlay = "") const;
	void Bullet() const;
	bool TextLink(const string &in label) const;
	bool TextLinkOpenURL(const string &in label) const;
	bool TextLinkOpenURL(const string &in label, const string &in url) const;
	bool BeginCombo(const string &in label, const string &in preview_value, int flags = 0) const;
	void EndCombo() const;
	bool Combo(const string &in label, int &out current_item, array<string>@ items, int popup_max_height_in_items = -1) const;
}

namespace Input
{
	bool IsButtonDown(int button) const;
	bool IsButtonPressed(int button) const;
	bool IsButtonReleased(int button) const;
	void SetCursorAlwaysVisible(bool state) const;
	bool IsCursorVisible() const;
	int GetPollTick() const;
	bool IsButtonValid() const;
}

namespace Materials
{
	Material@ CreateMaterial(const string &in name, const string &in vmt) const;
	Material@ GetMaterial(const string &in name) const;
	Texture@ CreateTextureNamedRenderTarget(const string &in name, int width, int height) const;
}

namespace Render
{
	void GetColorModulation(float &out r, float &out g, float &out b) const;
	void SetColorModulation(float r, float g, float b) const;
	float GetBlend() const;
	void SetBlend(float blend) const;
	void ForcedMaterialOverride(Material@ mat) const;
	Material@ GetMaterialOverride() const;
	void DrawScreenSpaceRectangle(Material@, int, int, int, int, float, float, float, float, int, int) const;
	void DrawScreenSpaceQuad(Material@) const;
	void GetViewport(int &out, int &out, int &out, int &out) const;
	void Viewport(int, int, int, int) const;
	void DepthRange(float, float) const;
	bool GetDepthRange(float &out, float &out) const;
	void SetRenderTarget(Texture@) const;
	Texture@ GetRenderTarget() const;
	void PushRenderTargetAndViewport() const;
	void PopRenderTargetAndViewport() const;
	void ClearBuffers(bool, bool, bool = false) const;
	void ClearColor3ub(uint, uint, uint) const;
	void ClearColor4ub(uint, uint, uint, uint) const;
	void OverrideDepthEnable(bool, bool) const;
	void OverrideAlphaEnable(bool, bool) const;
	void OverrideColorEnable(bool, bool) const;
	void SetStencilEnable(bool) const;
	void SetStencilFailOperation(int) const;
	void SetStencilZFailOperation(int) const;
	void SetStencilPassOperation(int) const;
	void SetStencilCompareFunction(int) const;
	void SetStencilReferenceValue(int) const;
	void SetStencilTestMask(uint) const;
	void SetStencilWriteMask(uint) const;
	void ClearStencilBufferRectangle(int, int, int, int, int) const;
}

enum ETFClassID
{
	CTFWearableRazorback		      = 341,
	CTFWearableDemoShield		      = 338,
	CTFWearableLevelableItem	      = 340,
	CTFWearableCampaignItem		      = 337,
	CTFBaseRocket			      = 185,
	CTFWeaponBaseMerasmusGrenade	      = 325,
	CTFWeaponBaseMelee		      = 324,
	CTFWeaponBaseGun		      = 323,
	CTFWeaponBaseGrenadeProj	      = 322,
	CTFWeaponBase			      = 321,
	CTFWearableRobotArm		      = 342,
	CTFRobotArm			      = 287,
	CTFWrench			      = 344,
	CTFProjectile_ThrowableBreadMonster   = 279,
	CTFProjectile_ThrowableBrick	      = 280,
	CTFProjectile_ThrowableRepel	      = 281,
	CTFProjectile_Throwable		      = 278,
	CTFThrowable			      = 319,
	CTFSyringeGun			      = 315,
	CTFKatana			      = 225,
	CTFSword			      = 314,
	CSniperDot			      = 118,
	CTFSniperRifleClassic		      = 308,
	CTFSniperRifleDecap		      = 309,
	CTFSniperRifle			      = 307,
	CTFChargedSMG			      = 197,
	CTFSMG				      = 306,
	CTFSlap				      = 305,
	CTFShovel			      = 304,
	CTFShotgunBuildingRescue	      = 303,
	CTFPEPBrawlerBlaster		      = 241,
	CTFSodaPopper			      = 310,
	CTFShotgun_Revenge		      = 301,
	CTFScatterGun			      = 297,
	CTFShotgun_Pyro			      = 300,
	CTFShotgun_HWG			      = 299,
	CTFShotgun_Soldier		      = 302,
	CTFShotgun			      = 298,
	CTFRocketPack			      = 296,
	CTFCrossbow			      = 201,
	CTFRocketLauncher_Mortar	      = 295,
	CTFRocketLauncher_AirStrike	      = 293,
	CTFRocketLauncher_DirectHit	      = 294,
	CTFRocketLauncher		      = 292,
	CTFRevolver			      = 286,
	CTFDRGPomson			      = 202,
	CTFRaygun			      = 284,
	CTFPistol_ScoutSecondary	      = 246,
	CTFPistol_ScoutPrimary		      = 245,
	CTFPistol_Scout			      = 244,
	CTFPistol			      = 243,
	CTFPipebombLauncher		      = 242,
	CTFWeaponPDA_Spy		      = 332,
	CTFWeaponPDA_Engineer_Destroy	      = 331,
	CTFWeaponPDA_Engineer_Build	      = 330,
	CTFWeaponPDAExpansion_Teleporter      = 334,
	CTFWeaponPDAExpansion_Dispenser	      = 333,
	CTFWeaponPDA			      = 329,
	CTFParticleCannon		      = 239,
	CTFParachute_Secondary		      = 238,
	CTFParachute_Primary		      = 237,
	CTFParachute			      = 236,
	CTFMinigun			      = 234,
	CTFMedigunShield		      = 231,
	CWeaponMedigun			      = 352,
	CTFProjectile_MechanicalArmOrb	      = 263,
	CTFMechanicalArm		      = 230,
	CTFLunchBox_Drink		      = 229,
	CTFLunchBox			      = 228,
	CLaserDot			      = 78,
	CTFLaserPointer			      = 227,
	CTFKnife			      = 226,
	CTFGasManager			      = 212,
	CTFProjectile_JarGas		      = 261,
	CTFJarGas			      = 223,
	CTFProjectile_Cleaver		      = 254,
	CTFProjectile_JarMilk		      = 262,
	CTFProjectile_Jar		      = 260,
	CTFCleaver			      = 198,
	CTFJarMilk			      = 224,
	CTFJar				      = 222,
	CTFWeaponInvis			      = 328,
	CTFCannon			      = 196,
	CTFGrenadeLauncher		      = 216,
	CTFGrenadePipebombProjectile	      = 217,
	CTFGrapplingHook		      = 215,
	CTFFlareGun_Revenge		      = 210,
	CTFFlareGun			      = 209,
	CTFFlameRocket			      = 207,
	CTFFlameThrower			      = 208,
	CTFFists			      = 205,
	CTFFireAxe			      = 204,
	CTFWeaponFlameBall		      = 327,
	CTFCompoundBow			      = 200,
	CTFClub				      = 199,
	CTFBuffItem			      = 195,
	CTFStickBomb			      = 312,
	CTFBreakableSign		      = 194,
	CTFBottle			      = 192,
	CTFBreakableMelee		      = 193,
	CTFBonesaw			      = 190,
	CTFBall_Ornament		      = 182,
	CTFStunBall			      = 313,
	CTFBat_Giftwrap			      = 188,
	CTFBat_Wood			      = 189,
	CTFBat_Fish			      = 187,
	CTFBat				      = 186,
	CTFProjectile_EnergyRing	      = 256,
	CTFDroppedWeapon		      = 203,
	CTFWeaponSapper			      = 335,
	CTFWeaponBuilder		      = 326,
	C_TFWeaponBuilder		      = 0,
	CTFProjectile_Rocket		      = 264,
	CTFProjectile_Flare		      = 257,
	CTFProjectile_EnergyBall	      = 255,
	CTFProjectile_GrapplingHook	      = 258,
	CTFProjectile_HealingBolt	      = 259,
	CTFProjectile_Arrow		      = 252,
	CMannVsMachineStats		      = 80,
	CTFTankBoss			      = 316,
	CTFBaseBoss			      = 183,
	CBossAlpha			      = 0,
	NextBotCombatCharacter		      = 357,
	CTFProjectile_SpellKartBats	      = 268,
	CTFProjectile_SpellKartOrb	      = 269,
	CTFHellZap			      = 220,
	CTFProjectile_SpellLightningOrb	      = 270,
	CTFProjectile_SpellTransposeTeleport  = 277,
	CTFProjectile_SpellMeteorShower	      = 271,
	CTFProjectile_SpellSpawnBoss	      = 274,
	CTFProjectile_SpellMirv		      = 272,
	CTFProjectile_SpellPumpkin	      = 273,
	CTFProjectile_SpellSpawnHorde	      = 275,
	CTFProjectile_SpellSpawnZombie	      = 276,
	CTFProjectile_SpellBats		      = 266,
	CTFProjectile_SpellFireball	      = 267,
	CTFSpellBook			      = 311,
	CHightower_TeleportVortex	      = 74,
	CTeleportVortex			      = 160,
	CZombie				      = 354,
	CMerasmusDancer			      = 83,
	CMerasmus			      = 82,
	CHeadlessHatman			      = 73,
	CEyeballBoss			      = 48,
	CTFBotHintEngineerNest		      = 191,
	CBotNPCMinion			      = 0,
	CBotNPC				      = 0,
	CPasstimeGun			      = 94,
	CTFViewModel			      = 320,
	CRobotDispenser			      = 112,
	CTFRobotDestruction_Robot	      = 288,
	CTFReviveMarker			      = 285,
	CTFPumpkinBomb			      = 282,
	CTFProjectile_BallOfFire	      = 253,
	CTFBaseProjectile		      = 184,
	CTFPointManager			      = 250,
	CBaseObjectUpgrade		      = 11,
	CTFRobotDestructionLogic	      = 291,
	CTFRobotDestruction_RobotGroup	      = 289,
	CTFRobotDestruction_RobotSpawn	      = 290,
	CTFPlayerDestructionLogic	      = 248,
	CPlayerDestructionDispenser	      = 101,
	CTFMinigameLogic		      = 233,
	CTFHalloweenMinigame_FallingPlatforms = 219,
	CTFHalloweenMinigame		      = 218,
	CTFMiniGame			      = 232,
	CTFPowerupBottle		      = 251,
	CTFItem				      = 221,
	CHalloweenSoulPack		      = 71,
	CTFGenericBomb			      = 213,
	CBonusRoundLogic		      = 23,
	CTFGameRulesProxy		      = 211,
	CTETFParticleEffect		      = 179,
	CTETFExplosion			      = 178,
	CTETFBlood			      = 177,
	CTFFlameManager			      = 206,
	CHalloweenGiftPickup		      = 69,
	CBonusDuckPickup		      = 21,
	CHalloweenPickup		      = 70,
	CCaptureFlagReturnIcon		      = 27,
	CCaptureFlag			      = 26,
	CBonusPack			      = 22,
	CTFTeam				      = 318,
	CTFTauntProp			      = 317,
	CTFPlayerResource		      = 249,
	CTFPlayer			      = 247,
	CTFRagdoll			      = 283,
	CTEPlayerAnimEvent		      = 165,
	CTFPasstimeLogic		      = 240,
	CPasstimeBall			      = 93,
	CTFObjectiveResource		      = 235,
	CTFGlow				      = 214,
	CTEFireBullets			      = 152,
	CTFBuffBanner			      = 0,
	CTFAmmoPack			      = 181,
	CObjectTeleporter		      = 89,
	CObjectSentrygun		      = 88,
	CTFProjectile_SentryRocket	      = 265,
	CObjectSapper			      = 87,
	CObjectCartDispenser		      = 85,
	CObjectDispenser		      = 86,
	CMonsterResource		      = 84,
	CFuncRespawnRoomVisualizer	      = 64,
	CFuncRespawnRoom		      = 63,
	CFuncPasstimeGoal		      = 61,
	CFuncForceField			      = 57,
	CCaptureZone			      = 28,
	CCurrencyPack			      = 31,
	CBaseObject			      = 10,
	CTestTraceline			      = 176,
	CTEWorldDecal			      = 180,
	CTESpriteSpray			      = 174,
	CTESprite			      = 173,
	CTESparks			      = 172,
	CTESmoke			      = 171,
	CTEShowLine			      = 169,
	CTEProjectedDecal		      = 167,
	CTEPlayerDecal			      = 166,
	CTEPhysicsProp			      = 164,
	CTEParticleSystem		      = 163,
	CTEMuzzleFlash			      = 162,
	CTELargeFunnel			      = 159,
	CTEKillPlayerAttachments	      = 158,
	CTEImpact			      = 157,
	CTEGlowSprite			      = 156,
	CTEShatterSurface		      = 168,
	CTEFootprintDecal		      = 154,
	CTEFizz				      = 153,
	CTEExplosion			      = 151,
	CTEEnergySplash			      = 150,
	CTEEffectDispatch		      = 149,
	CTEDynamicLight			      = 148,
	CTEDecal			      = 146,
	CTEClientProjectile		      = 145,
	CTEBubbleTrail			      = 144,
	CTEBubbles			      = 143,
	CTEBSPDecal			      = 142,
	CTEBreakModel			      = 141,
	CTEBloodStream			      = 140,
	CTEBloodSprite			      = 139,
	CTEBeamSpline			      = 138,
	CTEBeamRingPoint		      = 137,
	CTEBeamRing			      = 136,
	CTEBeamPoints			      = 135,
	CTEBeamLaser			      = 134,
	CTEBeamFollow			      = 133,
	CTEBeamEnts			      = 132,
	CTEBeamEntPoint			      = 131,
	CTEBaseBeam			      = 130,
	CTEArmorRicochet		      = 129,
	CTEMetalSparks			      = 161,
	CSteamJet			      = 123,
	CSmokeStack			      = 117,
	DustTrail			      = 355,
	CFireTrail			      = 50,
	SporeTrail			      = 362,
	SporeExplosion			      = 361,
	RocketTrail			      = 359,
	SmokeTrail			      = 360,
	CPropVehicleDriveable		      = 108,
	ParticleSmokeGrenade		      = 358,
	CParticleFire			      = 90,
	MovieExplosion			      = 356,
	CTEGaussExplosion		      = 155,
	CEnvQuadraticBeam		      = 43,
	CEmbers				      = 36,
	CEnvWind			      = 47,
	CPrecipitation			      = 107,
	CBaseTempEntity			      = 17,
	CWeaponIFMSteadyCam		      = 351,
	CWeaponIFMBaseCamera		      = 350,
	CWeaponIFMBase			      = 349,
	CTFWearableVM			      = 343,
	CTFWearable			      = 336,
	CTFWearableItem			      = 339,
	CEconWearable			      = 35,
	CBaseAttributableItem		      = 3,
	CEconEntity			      = 34,
	CHandleTest			      = 72,
	CTeamplayRoundBasedRulesProxy	      = 126,
	CTeamRoundTimer			      = 127,
	CSpriteTrail			      = 122,
	CSpriteOriented			      = 121,
	CSprite				      = 120,
	CRagdollPropAttached		      = 111,
	CRagdollProp			      = 110,
	CPoseController			      = 106,
	CGameRulesProxy			      = 68,
	CInfoLadderDismount		      = 75,
	CFuncLadder			      = 58,
	CEnvDetailController		      = 40,
	CWorld				      = 353,
	CWaterLODControl		      = 348,
	CWaterBullet			      = 347,
	CVoteController			      = 346,
	CVGuiScreen			      = 345,
	CPropJeep			      = 0,
	CPropVehicleChoreoGeneric	      = 0,
	CTest_ProxyToggle_Networkable	      = 175,
	CTesla				      = 170,
	CTeamTrainWatcher		      = 128,
	CBaseTeamObjectiveResource	      = 16,
	CTeam				      = 125,
	CSun				      = 124,
	CParticlePerformanceMonitor	      = 91,
	CSpotlightEnd			      = 119,
	CSlideshowDisplay		      = 116,
	CShadowControl			      = 115,
	CSceneEntity			      = 114,
	CRopeKeyframe			      = 113,
	CRagdollManager			      = 109,
	CPhysicsPropMultiplayer		      = 98,
	CPhysBoxMultiplayer		      = 96,
	CBasePropDoor			      = 15,
	CDynamicProp			      = 33,
	CPointWorldText			      = 105,
	CPointCommentaryNode		      = 104,
	CPointCamera			      = 103,
	CPlayerResource			      = 102,
	CPlasma				      = 100,
	CPhysMagnet			      = 99,
	CPhysicsProp			      = 97,
	CPhysBox			      = 95,
	CParticleSystem			      = 92,
	CMaterialModifyControl		      = 81,
	CLightGlow			      = 79,
	CInfoOverlayAccessor		      = 77,
	CFuncTrackTrain			      = 67,
	CFuncSmokeVolume		      = 66,
	CFuncRotating			      = 65,
	CFuncReflectiveGlass		      = 62,
	CFuncOccluder			      = 60,
	CFuncMonitor			      = 59,
	CFunc_LOD			      = 54,
	CTEDust				      = 147,
	CFunc_Dust			      = 53,
	CFuncConveyor			      = 56,
	CBreakableSurface		      = 25,
	CFuncAreaPortalWindow		      = 55,
	CFish				      = 51,
	CEntityFlame			      = 38,
	CFireSmoke			      = 49,
	CEnvTonemapController		      = 46,
	CEnvScreenEffect		      = 44,
	CEnvScreenOverlay		      = 45,
	CEnvProjectedTexture		      = 42,
	CEnvParticleScript		      = 41,
	CFogController			      = 52,
	CEntityParticleTrail		      = 39,
	CEntityDissolve			      = 37,
	CDynamicLight			      = 32,
	CColorCorrectionVolume		      = 30,
	CColorCorrection		      = 29,
	CBreakableProp			      = 24,
	CBasePlayer			      = 13,
	CBaseFlex			      = 8,
	CBaseEntity			      = 7,
	CBaseDoor			      = 6,
	CBaseCombatCharacter		      = 4,
	CBaseAnimatingOverlay		      = 2,
	CBoneFollower			      = 20,
	CBaseAnimating			      = 1,
	CInfoLightingRelative		      = 76,
	CAI_BaseNPC			      = 0,
	CBeam				      = 19,
	CBaseViewModel			      = 18,
	CBaseProjectile			      = 14,
	CBaseParticleEntity		      = 12,
	CBaseGrenade			      = 9,
	CBaseCombatWeapon		      = 5
}

enum EButtonCode
{
	BUTTON_CODE_INVALID = -1,
	BUTTON_CODE_NONE    = 0,
	KEY_FIRST	    = 0,
	KEY_NONE	    = KEY_FIRST,
	KEY_0,
	KEY_1,
	KEY_2,
	KEY_3,
	KEY_4,
	KEY_5,
	KEY_6,
	KEY_7,
	KEY_8,
	KEY_9,
	KEY_A,
	KEY_B,
	KEY_C,
	KEY_D,
	KEY_E,
	KEY_F,
	KEY_G,
	KEY_H,
	KEY_I,
	KEY_J,
	KEY_K,
	KEY_L,
	KEY_M,
	KEY_N,
	KEY_O,
	KEY_P,
	KEY_Q,
	KEY_R,
	KEY_S,
	KEY_T,
	KEY_U,
	KEY_V,
	KEY_W,
	KEY_X,
	KEY_Y,
	KEY_Z,
	KEY_PAD_0,
	KEY_PAD_1,
	KEY_PAD_2,
	KEY_PAD_3,
	KEY_PAD_4,
	KEY_PAD_5,
	KEY_PAD_6,
	KEY_PAD_7,
	KEY_PAD_8,
	KEY_PAD_9,
	KEY_PAD_DIVIDE,
	KEY_PAD_MULTIPLY,
	KEY_PAD_MINUS,
	KEY_PAD_PLUS,
	KEY_PAD_ENTER,
	KEY_PAD_DECIMAL,
	KEY_LBRACKET,
	KEY_RBRACKET,
	KEY_SEMICOLON,
	KEY_APOSTROPHE,
	KEY_BACKQUOTE,
	KEY_COMMA,
	KEY_PERIOD,
	KEY_SLASH,
	KEY_BACKSLASH,
	KEY_MINUS,
	KEY_EQUAL,
	KEY_ENTER,
	KEY_SPACE,
	KEY_BACKSPACE,
	KEY_TAB,
	KEY_CAPSLOCK,
	KEY_NUMLOCK,
	KEY_ESCAPE,
	KEY_SCROLLLOCK,
	KEY_INSERT,
	KEY_DELETE,
	KEY_HOME,
	KEY_END,
	KEY_PAGEUP,
	KEY_PAGEDOWN,
	KEY_BREAK,
	KEY_LSHIFT,
	KEY_RSHIFT,
	KEY_LALT,
	KEY_RALT,
	KEY_LCONTROL,
	KEY_RCONTROL,
	KEY_LWIN,
	KEY_RWIN,
	KEY_APP,
	KEY_UP,
	KEY_LEFT,
	KEY_DOWN,
	KEY_RIGHT,
	KEY_F1,
	KEY_F2,
	KEY_F3,
	KEY_F4,
	KEY_F5,
	KEY_F6,
	KEY_F7,
	KEY_F8,
	KEY_F9,
	KEY_F10,
	KEY_F11,
	KEY_F12,
	KEY_CAPSLOCKTOGGLE,
	KEY_NUMLOCKTOGGLE,
	KEY_SCROLLLOCKTOGGLE,
	KEY_LAST    = KEY_SCROLLLOCKTOGGLE,
	KEY_COUNT   = KEY_LAST - KEY_FIRST + 1,
	MOUSE_FIRST = KEY_LAST + 1,
	MOUSE_LEFT  = MOUSE_FIRST,
	MOUSE_RIGHT,
	MOUSE_MIDDLE,
	MOUSE_4,
	MOUSE_5,
	MOUSE_WHEEL_UP,
	MOUSE_WHEEL_DOWN,
	MOUSE_LAST	      = MOUSE_WHEEL_DOWN,
	MOUSE_COUNT	      = MOUSE_LAST - MOUSE_FIRST + 1,
	JOYSTICK_FIRST	      = MOUSE_LAST + 1,
	JOYSTICK_FIRST_BUTTON = JOYSTICK_FIRST,
	JOYSTICK_LAST_BUTTON  = JOYSTICK_BUTTON_INTERNAL(MAX_JOYSTICKS - 1, JOYSTICK_MAX_BUTTON_COUNT - 1),
	JOYSTICK_FIRST_POV_BUTTON,
	JOYSTICK_LAST_POV_BUTTON = JOYSTICK_POV_BUTTON_INTERNAL(MAX_JOYSTICKS - 1, JOYSTICK_POV_BUTTON_COUNT - 1),
	JOYSTICK_FIRST_AXIS_BUTTON,
	JOYSTICK_LAST_AXIS_BUTTON = JOYSTICK_AXIS_BUTTON_INTERNAL(MAX_JOYSTICKS - 1, JOYSTICK_AXIS_BUTTON_COUNT - 1),
	JOYSTICK_LAST		  = JOYSTICK_LAST_AXIS_BUTTON,
	NOVINT_FIRST		  = JOYSTICK_LAST + 2,
	NOVINT_LOGO_0		  = NOVINT_FIRST,
	NOVINT_TRIANGLE_0,
	NOVINT_BOLT_0,
	NOVINT_PLUS_0,
	NOVINT_LOGO_1,
	NOVINT_TRIANGLE_1,
	NOVINT_BOLT_1,
	NOVINT_PLUS_1,
	NOVINT_LAST		     = NOVINT_PLUS_1,
	STEAMCONTROLLER_FIRST	     = NOVINT_LAST + 1,
	STEAMCONTROLLER_FIRST_BUTTON = STEAMCONTROLLER_FIRST,
	STEAMCONTROLLER_LAST_BUTTON =
	    STEAMCONTROLLER_BUTTON_INTERNAL(MAX_STEAM_CONTROLLERS - 1, STEAMCONTROLLER_MAX_BUTTON_COUNT - 1),
	STEAMCONTROLLER_FIRST_AXIS_BUTTON,
	STEAMCONTROLLER_LAST_AXIS_BUTTON =
	    STEAMCONTROLLER_AXIS_BUTTON_INTERNAL(MAX_STEAM_CONTROLLERS - 1, STEAMCONTROLLER_AXIS_BUTTON_COUNT - 1),
	STEAMCONTROLLER_LAST = STEAMCONTROLLER_LAST_AXIS_BUTTON,
	BUTTON_CODE_LAST,
	BUTTON_CODE_COUNT = BUTTON_CODE_LAST - KEY_FIRST + 1,
	KEY_XBUTTON_UP	  = JOYSTICK_FIRST_POV_BUTTON,
	KEY_XBUTTON_RIGHT,
	KEY_XBUTTON_DOWN,
	KEY_XBUTTON_LEFT,
	KEY_XBUTTON_A = JOYSTICK_FIRST_BUTTON,
	KEY_XBUTTON_B,
	KEY_XBUTTON_X,
	KEY_XBUTTON_Y,
	KEY_XBUTTON_LEFT_SHOULDER,
	KEY_XBUTTON_RIGHT_SHOULDER,
	KEY_XBUTTON_BACK,
	KEY_XBUTTON_START,
	KEY_XBUTTON_STICK1,
	KEY_XBUTTON_STICK2,
	KEY_XSTICK1_RIGHT = JOYSTICK_FIRST_AXIS_BUTTON,
	KEY_XSTICK1_LEFT,
	KEY_XSTICK1_DOWN,
	KEY_XSTICK1_UP,
	KEY_XBUTTON_LTRIGGER,
	KEY_XBUTTON_RTRIGGER,
	KEY_XSTICK2_RIGHT,
	KEY_XSTICK2_LEFT,
	KEY_XSTICK2_DOWN,
	KEY_XSTICK2_UP,
	STEAMCONTROLLER_A = STEAMCONTROLLER_FIRST_BUTTON,
	STEAMCONTROLLER_B,
	STEAMCONTROLLER_X,
	STEAMCONTROLLER_Y,
	STEAMCONTROLLER_DPAD_UP,
	STEAMCONTROLLER_DPAD_RIGHT,
	STEAMCONTROLLER_DPAD_DOWN,
	STEAMCONTROLLER_DPAD_LEFT,
	STEAMCONTROLLER_LEFT_BUMPER,
	STEAMCONTROLLER_RIGHT_BUMPER,
	STEAMCONTROLLER_LEFT_TRIGGER,
	STEAMCONTROLLER_RIGHT_TRIGGER,
	STEAMCONTROLLER_LEFT_GRIP,
	STEAMCONTROLLER_RIGHT_GRIP,
	STEAMCONTROLLER_LEFT_PAD_FINGERDOWN,
	STEAMCONTROLLER_RIGHT_PAD_FINGERDOWN,
	STEAMCONTROLLER_LEFT_PAD_CLICK,
	STEAMCONTROLLER_RIGHT_PAD_CLICK,
	STEAMCONTROLLER_LEFT_PAD_UP,
	STEAMCONTROLLER_LEFT_PAD_RIGHT,
	STEAMCONTROLLER_LEFT_PAD_DOWN,
	STEAMCONTROLLER_LEFT_PAD_LEFT,
	STEAMCONTROLLER_RIGHT_PAD_UP,
	STEAMCONTROLLER_RIGHT_PAD_RIGHT,
	STEAMCONTROLLER_RIGHT_PAD_DOWN,
	STEAMCONTROLLER_RIGHT_PAD_LEFT,
	STEAMCONTROLLER_SELECT,
	STEAMCONTROLLER_START,
	STEAMCONTROLLER_STEAM,
	STEAMCONTROLLER_INACTIVE_START,
	STEAMCONTROLLER_F1,
	STEAMCONTROLLER_F2,
	STEAMCONTROLLER_F3,
	STEAMCONTROLLER_F4,
	STEAMCONTROLLER_F5,
	STEAMCONTROLLER_F6,
	STEAMCONTROLLER_F7,
	STEAMCONTROLLER_F8,
	STEAMCONTROLLER_F9,
	STEAMCONTROLLER_F10,
	STEAMCONTROLLER_F11,
	STEAMCONTROLLER_F12
}