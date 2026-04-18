#pragma once

#include <string>

#include "../../sdk/definitions/imaterial.h"

class ChamsMaterial
{
public:
	ChamsMaterial(const std::string& name, const std::string& vmt);
	~ChamsMaterial();

	const std::string& GetVMT();
	void SetVMT(const std::string& vmt);

	bool IsValidMat();
	IMaterial* GetMaterial();
	void Refresh();

	void SetUsed(bool used);
	bool IsUsed();

	const std::string& GetInternalName();
	void SetInternalName(const std::string& name);

	const std::string& GetDisplayName();
	void SetDisplayName(const std::string& name);

	float GetAlpha();
	void SetAlpha(float alpha);

private:
	std::string m_DisplayName = "";
	std::string m_InternalName = "";
	std::string m_Vmt = "";
	IMaterial* m_Mat = nullptr;
	bool m_Used = false;
	float m_Alpha = 1.0f;
};