#pragma once

#include "Renderable2D.h"

namespace nuy { namespace graphics {

    class StaticSprite : public Renderable2D
    {
    private:
        VertexArray* _VertexArray;
		IndexBuffer* _IndexBuffer;
		Shader& _Shader;

    public:
        StaticSprite(float x, float y, float width, float height, maths::Vector4& color, Shader& shader);
        ~StaticSprite();

        inline const VertexArray* GetVAO() const { return _VertexArray; }
		inline const IndexBuffer* GetIBO() const { return _IndexBuffer; }
		inline Shader& GetShader() const { return _Shader; }
    };

} }
