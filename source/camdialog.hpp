#pragma once
#include "c4d_gui.h"


struct CamDialog : GeDialog
{
	Bool CreateLayout() override
	{
		SetTitle("Camera"_s);
		AddEditText(1, BFH_CENTER, 400, 20);
		return true;
	}
};