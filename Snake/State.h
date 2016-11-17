#pragma once

struct State
{
	virtual void Load() = 0;
	virtual void Save() = 0;
	virtual void Update() = 0;
};