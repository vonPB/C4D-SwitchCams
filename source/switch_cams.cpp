#include "switch_cams.hpp"
#include "c4d_basedocument.h"
#include "c4d_general.h"
#include "c4d_basebitmap.h"
#include "c4d_basedraw.h"
#include "gui.h"

Bool SwitchCams::Execute(BaseDocument* doc, GeDialog* parentManager)
{
	ApplicationOutput("Excute BaseDocument 1st line");
	camdialog_.GetString(1, cam_name_);
	ApplicationOutput("Get String");
	auto bd{ doc->GetActiveBaseDraw() };
	auto default_cam{ bd->GetEditorCamera() };
	auto main_cam{ doc->SearchObject(cam_name_) };
	auto active_cam{ bd->GetSceneCamera(doc) };
	if (!main_cam || main_cam->GetType() != CAM_TYPE_ID)
		return true;
	if (active_cam->GetGUID() == main_cam->GetGUID())
		bd->SetSceneCamera(default_cam);
	else if (active_cam->GetGUID() == default_cam->GetGUID())
		bd->SetSceneCamera(main_cam);
	
	EventAdd();
	return true;
}
Bool SwitchCams::ExecuteOptionID(BaseDocument* doc, Int32 plugid, Int32 subid, GeDialog* parentManager)
{
	camdialog_.SetString(1, cam_name_);
	camdialog_.Open(DLG_TYPE::ASYNC, ID, -1, -1, 400, 25);

	return true;
}
Int32 SwitchCams::GetState(BaseDocument* doc, GeDialog* parentManager)
{
	return 0xffffffff;
}
Bool SwitchCams::register_class()
{
	return RegisterCommandPlugin(ID, "SwitchCams"_s, 0, nullptr, "Switch a Camera to the Default one and back"_s, new SwitchCams);
}
