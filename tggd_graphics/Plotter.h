#pragma once
#include "XY.h"
namespace tggd::graphics
{
	template<typename TInputDimension, typename TOutputDimension>
	class Plotter
	{
	public:
		virtual XY<TOutputDimension> Plot(const XY<TInputDimension>) const = 0;
	};
}