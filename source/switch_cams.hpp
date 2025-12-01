#pragma once
#include "c4d_baselist.h"
#include "c4d_commanddata.h"
#include "camdialog.hpp"

struct SwitchCams : CommandData
{
	static const Int32 ID{1000010};
	static const Int32 CAM_TYPE_ID{ 5103 };

	Bool Execute(BaseDocument* doc, GeDialog* parentManager) override;
	Bool ExecuteOptionID(BaseDocument* doc, Int32 plugid, Int32 subid, GeDialog* parentManager) override;
	Int32 GetState(BaseDocument* doc, GeDialog* parentManager) override;

	static Bool register_class();

private:
	maxon::String cam_name_{ "Main" };
	CamDialog camdialog_;
};


