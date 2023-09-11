cbuffer ConstantBufferNeverChanges : register(b0)
{
    float4 lightDirection;
    float4 lightColor;
    float ambient_factor;
}

cbuffer ConstantBufferChangeOnResize : register(b1)
{
    matrix projection;
};

cbuffer ConstantBufferChangesEveryFrame : register(b2)
{
    matrix view;
};

cbuffer ConstantBufferChangesEveryPrim : register(b3)
{
    matrix world;
};
