#pragma once

#include "Layer.h"
#include "../BatchRenderer2D.h"

namespace nuy { namespace graphics {

	class TileLayer : public Layer
	{
	public:
		TileLayer(Shader* shader);
		~TileLayer();
	};

} }