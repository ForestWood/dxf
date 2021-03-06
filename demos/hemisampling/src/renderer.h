// renderer.h
//
// Created at 2014/02/20
//
// Hongwei Li hongwei.li@amd.com
// All rights reserved


#ifndef RENDERER_H
#define RENDERER_H

#include <dxf/dxf.h>

class Renderer : public dxf::AbstractRenderer
{
public:
    Renderer();
    virtual ~Renderer();

    virtual HRESULT initialize(ID3D11Device* device, ID3D11DeviceContext* context, 
        CDXUTTextHelper *txtHelper);
    virtual void uninitialize();
    virtual void render(double fTime, float fElapsedTime);
    virtual void renderText(double fTime, float fElapsedTime);
    virtual void update(double fTime, float fElapsedTime);
    virtual HRESULT resize(UINT width, UINT height);
    virtual void keyboard(UINT c, bool bKeyDown, bool bAltDown);
    virtual LRESULT msgproc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
    ID3D11DepthStencilState*           m_dsState;
    ID3D11BlendState*                  m_blendState;
    dxf::Model*                        m_sphere;
    dxf::Model*                        m_points;
    dxf::Shader*                       m_sphereShader;
    dxf::Shader*                       m_pointsShader;
    struct CbEveryFrameStruct   
    {
        DirectX::XMMATRIX m_mvp;
    };
    dxf::CBuffer<CbEveryFrameStruct>*  m_cbEveryFrame;
    struct CbEveryFrameStruct2
    {
        DirectX::XMMATRIX m_cameraView;
        DirectX::XMMATRIX m_projection;
    };
    dxf::CBuffer<CbEveryFrameStruct2>* m_cbEveryFrame2;
    struct CbInitStruct
    {
        dxf::DirectionalLight light;
    };
    dxf::CBuffer<CbInitStruct>*        m_cbInit;
    CModelViewerCamera                 m_camera; 
    bool                               m_showPoints;
};


#endif // !RENDERER_H
