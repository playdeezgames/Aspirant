#pragma once
#include "BaseDescriptorManager.h"
#include "SpriteFont.h"
namespace tggd::common
{
	class FontManager: public BaseDescriptorManager<std::string, SpriteFont>
	{
	private:
		const SpriteManager& spriteManager;
		const ColorManager& colorManager;
	protected:
		std::string ParseKey(const std::string&);
		SpriteFont* ParseDescriptor(const nlohmann::json&);
	public:
		FontManager
		(
			FinishManager&,
			const SpriteManager&,
			const ColorManager&
		);
	};
}
