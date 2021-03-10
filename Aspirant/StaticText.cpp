#include "StaticText.h"
#include "Utility.h"
#include "ConstantValue.h"
#include <DataUtility.h>
namespace tggd::common
{
	StaticText::StaticText
	(
		const tggd::data::IDataStore<SpriteFont>& fontStore,
		const tggd::common::XY<int>& xy,
		const std::string& text,
		const std::string& fontName,
		const std::string& color,
		bool hasDropShadow,
		const tggd::common::XY<int>& dropShadowOffset,
		const std::string& dropShadowColor,
		const HorizontalAlignment& alignment
	)
		: x(new tggd::data::ConstantValue(xy.GetX()))
		, y(new tggd::data::ConstantValue(xy.GetY()))
		, text(new tggd::data::ConstantValue(text))
		, fontStore(fontStore)
		, fontName(new tggd::data::ConstantValue(fontName))
		, color(new tggd::data::ConstantValue(color))
		, hasDropShadow(new tggd::data::ConstantValue(hasDropShadow))
		, dropShadowX(new tggd::data::ConstantValue(dropShadowOffset.GetX()))
		, dropShadowY(new tggd::data::ConstantValue(dropShadowOffset.GetY()))
		, dropShadowColor(new tggd::data::ConstantValue(dropShadowColor))
		, alignment(new tggd::data::ConstantValue((int)alignment))
	{

	}

	const std::string PROPERTY_X = "x";
	const std::string PROPERTY_Y = "y";
	const std::string PROPERTY_TEXT = "text";
	const std::string PROPERTY_FONT = "font";
	const std::string PROPERTY_COLOR = "color";
	const std::string PROPERTY_DROP_SHADOW = "dropShadow";
	const std::string PROPERTY_DROP_SHADOW_COLOR = "dropShadowColor";
	const std::string PROPERTY_DROP_SHADOW_X = "dropShadowX";
	const std::string PROPERTY_DROP_SHADOW_Y = "dropShadowY";
	const std::string PROPERTY_HORIZONTAL_ALIGNMENT = "horizontalAlignment";

	StaticText::StaticText
	(
		const tggd::data::IDataStore<std::string>& stringStore,
		const tggd::data::IDataStore<int>& intStore,
		const tggd::data::IDataStore<bool>& flagStore,
		const tggd::data::IDataStore<SpriteFont>& fontStore,
		const nlohmann::json& properties
	)
		: text(tggd::data::DataUtility::LoadString(stringStore,properties[PROPERTY_TEXT]))
		, fontStore(fontStore)
		, fontName(tggd::data::DataUtility::LoadString(stringStore, properties[PROPERTY_FONT]))
		, color(tggd::data::DataUtility::LoadString(stringStore, properties[PROPERTY_COLOR]))
		, x(tggd::data::DataUtility::LoadInt(intStore, properties[PROPERTY_X]))
		, y(tggd::data::DataUtility::LoadInt(intStore, properties[PROPERTY_Y]))
		, hasDropShadow(nullptr)
		, dropShadowColor(nullptr)
		, dropShadowX(nullptr)
		, dropShadowY(nullptr)
		, alignment(nullptr)
	{
		if (properties.count(PROPERTY_DROP_SHADOW) > 0)
		{
			hasDropShadow = tggd::data::DataUtility::LoadFlag(flagStore, properties[PROPERTY_DROP_SHADOW]);
		}
		else
		{
			hasDropShadow = new tggd::data::ConstantValue(false);
		}
		if (properties.count(PROPERTY_HORIZONTAL_ALIGNMENT) > 0)
		{
			alignment = tggd::data::DataUtility::LoadInt(intStore, properties[PROPERTY_HORIZONTAL_ALIGNMENT]);
		}
		else
		{
			alignment = new tggd::data::ConstantValue((int)HorizontalAlignment::LEFT);
		}
		if (properties.count(PROPERTY_DROP_SHADOW) > 0)
		{
			dropShadowColor = tggd::data::DataUtility::LoadString(stringStore,properties[PROPERTY_DROP_SHADOW_COLOR]);
		}
		if (properties.count(PROPERTY_DROP_SHADOW_X) > 0)
		{
			dropShadowX = tggd::data::DataUtility::LoadInt(intStore, properties[PROPERTY_DROP_SHADOW_X]);
		}
		if (properties.count(PROPERTY_DROP_SHADOW_Y) > 0)
		{
			dropShadowY = tggd::data::DataUtility::LoadInt(intStore, properties[PROPERTY_DROP_SHADOW_Y]);
		}
	}

	StaticText::~StaticText()
	{
		FinishUtility::SafeDelete(text);
		FinishUtility::SafeDelete(fontName);
		FinishUtility::SafeDelete(color);
		FinishUtility::SafeDelete(dropShadowColor);
		FinishUtility::SafeDelete(hasDropShadow);
		FinishUtility::SafeDelete(x);
		FinishUtility::SafeDelete(y);
		FinishUtility::SafeDelete(dropShadowX);
		FinishUtility::SafeDelete(dropShadowY);
		FinishUtility::SafeDelete(alignment);
	}


	void StaticText::Draw(SDL_Renderer* renderer) const
	{
		if (hasDropShadow)
		{
			fontStore.Get(fontName->Get()).WriteText(renderer, XY<int>(x->Get() + dropShadowX->Get(), y->Get() + dropShadowY->Get()), text->Get(), dropShadowColor->Get(), (HorizontalAlignment)alignment->Get());
		}
		fontStore.Get(fontName->Get()).WriteText(renderer, XY<int>(x->Get(), y->Get()), text->Get(), color->Get(), (HorizontalAlignment)alignment->Get());
	}
}
