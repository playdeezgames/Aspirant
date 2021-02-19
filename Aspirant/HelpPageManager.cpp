#include "HelpPageManager.h"
std::string HelpPageManager::ParseKey(const std::string& key)
{
	return key;
}

HelpPage* HelpPageManager::ParseDescriptor(const nlohmann::json& properties)
{
	return new HelpPage(properties, fontManager);
}

HelpPageManager::HelpPageManager
(
	tggd::common::FinishManager& finishManager, 
	const tggd::common::FontManager& fontManager
)
	: BaseDescriptorManager(finishManager)
	, fontManager(fontManager)
{

}
