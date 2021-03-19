#pragma once
#include "XY.h"
namespace tggd::graphics
{
	template<typename TInputDimension, typename TOutputDimension>
	class Plotter
	{
	public:
		virtual tggd::common::XY<TOutputDimension> Plot(const tggd::common::XY<TInputDimension>&) const = 0;
	};
}