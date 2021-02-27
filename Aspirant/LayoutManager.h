#pragma once
#include "CommonDescriptorManager.h"
#include <string>
#include "Layout.h"
#include "SpriteManager.h"
#include "ColorManager.h"
#include "FontManager.h"
namespace tggd::common
{
	class LayoutManager: public CommonDescriptorManager<Layout>
	{
	private:
		const SpriteManager& spriteManager;
		const ColorManager& colorManager;
		const FontManager& fontManager;
		const IDataStore<std::string>& stringStore;
		const IDataStore<int>& intStore;
		const IDataStore<bool>& flagStore;
		FinishManager& finishManager;
	protected:
		Layout* ParseDescriptor(const nlohmann::json&);
	public:
		LayoutManager
		(
			FinishManager&,
			const SpriteManager&,
			const ColorManager&,
			const FontManager&,
			const IDataStore<std::string>&,
			const IDataStore<int>&,
			const IDataStore<bool>&
		);
	};
}
