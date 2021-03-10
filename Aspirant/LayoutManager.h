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
		const tggd::data::IDataStore<std::string>& stringStore;
		const tggd::data::IDataStore<int>& intStore;
		const tggd::data::IDataStore<bool>& flagStore;
		FinishManager& finishManager;
	protected:
		Layout* ParseDescriptor(const std::string&, const nlohmann::json&);
	public:
		LayoutManager
		(
			FinishManager&,
			const SpriteManager&,
			const ColorManager&,
			const FontManager&,
			const tggd::data::IDataStore<std::string>&,
			const tggd::data::IDataStore<int>&,
			const tggd::data::IDataStore<bool>&
		);
	};
}
