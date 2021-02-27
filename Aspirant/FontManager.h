#pragma once
#include "CommonDescriptorManager.h"
#include "SpriteFont.h"
#include "IDataStore.h"
namespace tggd::common
{
	class FontManager: public CommonDescriptorManager<SpriteFont>, public IDataStore<SpriteFont>
	{
	private:
		const SpriteManager& spriteManager;
		const ColorManager& colorManager;
	protected:
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
