#pragma once
#include "BaseDescriptorManager.h"
#include <string>
#include "Layout.h"
#include "SpriteManager.h"
#include "ColorManager.h"
#include "FontManager.h"
#include "StringManager.h"
namespace tggd::common
{
	class LayoutManager: public BaseDescriptorManager<std::string, Layout>
	{
	private:
		const SpriteManager& spriteManager;
		const ColorManager& colorManager;
		const FontManager& fontManager;
		const StringManager& stringManager;
		FinishManager& finishManager;
	protected:
		std::string ParseKey(const std::string&);
		Layout* ParseDescriptor(const nlohmann::json&);
	public:
		LayoutManager
		(
			FinishManager&,
			const SpriteManager&,
			const ColorManager&,
			const FontManager&,
			const StringManager&
		);
	};
}
