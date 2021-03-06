// -------------------------------------------------------------- 
// dxf_main.h
// The main entry of a single thread directx demo.
//
// A DirectX11 framework.
//
// All rights reserved by AMD.
//
// Hongwei Li (hongwei.li@amd.com)
// -------------------------------------------------------------- 


#ifndef DXF_MAIN_H
#define DXF_MAIN_H

#include "dxf_common.h"

DXF_NAMESPACE_BEGIN

class AbstractRenderer;
class AbstractControl;

DXF_EXTERN AbstractRenderer* DXF_APIENTRY createRenderer();
DXF_EXTERN AbstractControl* DXF_APIENTRY createControl();

DXF_EXTERN AbstractRenderer* DXF_APIENTRY getRenderer();
DXF_EXTERN AbstractControl* DXF_APIENTRY getControl();

struct GlobalProperties
{
    UINT   width;
    UINT   height;
    WCHAR* applicationName;
};

DXF_EXTERN void DXF_APIENTRY fillProperties(GlobalProperties *properties);

DXF_NAMESPACE_END

#endif // !DXF_MAIN_H
