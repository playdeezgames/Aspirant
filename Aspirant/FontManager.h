#pragma once
#include "BaseDescriptorManager.h"
#include "SpriteFont.h"
#include "IDataStore.h"
namespace tggd::common
{
	class FontManager: public BaseDescriptorManager<std::string, SpriteFont>, public IDataStore<SpriteFont>
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
		const SpriteFont& Get(const std::string&) const;
	};
}
