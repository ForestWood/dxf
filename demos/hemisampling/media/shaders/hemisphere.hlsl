cbuffer cbChangesEveryFrame
{
    matrix MVP;
};

cbuffer cbInit
{
    float4 Ambient;
    float4 Diffuse;
    float4 Specular;
    float3 Attenuation;
    float  Shinness;
    float3 LightDirection;
    float  padding;
};

struct VS_INPUT
{
    float3 Pos    : POSITION;
    float3 Normal : NORMAL;
    //float2 Tex    : TEXCOORD;
};

struct PS_INPUT
{
    float4 Pos    : SV_POSITION;
    float4 Color  : TEXCOORD0;
    float Clip    : SV_ClipDistance0;
};

//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
PS_INPUT VS(VS_INPUT input) 
{
    PS_INPUT output = (PS_INPUT)0;
   
    output.Pos = mul(float4(input.Pos, 1.0f), MVP);
    float3 n = normalize(input.Normal);
    float nDotL = max(dot(normalize(-LightDirection), n), 0);
    output.Color =nDotL * Diffuse + Ambient;
    output.Clip = input.Pos.y;
    return output;
}

//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(PS_INPUT input) : SV_TARGET
{
    return float4(input.Color.rgb, 1.0); 
    //return float4(0.25f, 0.25f, 0.0f, 0.0); 
}
