#include "StaticText.h"
#include "Utility.h"
#include "ConstantValue.h"
namespace tggd::common
{
	StaticText::StaticText
	(
		const tggd::common::IDataStore<SpriteFont>& fontStore,
		const tggd::common::XY<int>& xy,
		const std::string& text,
		const std::string& fontName,
		const std::string& color,
		bool hasDropShadow,
		const tggd::common::XY<int>& dropShadowOffset,
		const std::string& dropShadowColor,
		const HorizontalAlignment& alignment
	)
		: x(new ConstantValue(xy.GetX()))
		, y(new ConstantValue(xy.GetY()))
		, text(new ConstantValue(text))
		, fontStore(fontStore)
		, fontName(new ConstantValue(fontName))
		, color(new ConstantValue(color))
		, hasDropShadow(new ConstantValue(hasDropShadow))
		, dropShadowX(new ConstantValue(dropShadowOffset.GetX()))
		, dropShadowY(new ConstantValue(dropShadowOffset.GetY()))
		, dropShadowColor(new ConstantValue(dropShadowColor))
		, alignment(new ConstantValue((int)alignment))
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
		const tggd::common::IDataStore<std::string>& stringStore,
		const tggd::common::IDataStore<int>& intStore,
		const tggd::common::IDataStore<bool>& flagStore,
		const tggd::common::IDataStore<SpriteFont>& fontStore,
		const nlohmann::json& properties
	)
		: text(Utility::LoadString(stringStore,properties[PROPERTY_TEXT]))
		, fontStore(fontStore)
		, fontName(Utility::LoadString(stringStore, properties[PROPERTY_FONT]))
		, color(Utility::LoadString(stringStore, properties[PROPERTY_COLOR]))
		, x(Utility::LoadInt(intStore, properties[PROPERTY_X]))
		, y(Utility::LoadInt(intStore, properties[PROPERTY_Y]))
		, hasDropShadow(nullptr)
		, dropShadowColor(nullptr)
		, dropShadowX(nullptr)
		, dropShadowY(nullptr)
		, alignment(nullptr)
	{
		if (properties.count(PROPERTY_DROP_SHADOW) > 0)
		{
			hasDropShadow = Utility::LoadFlag(flagStore, properties[PROPERTY_DROP_SHADOW]);
		}
		else
		{
			hasDropShadow = new ConstantValue(false);
		}
		if (properties.count(PROPERTY_HORIZONTAL_ALIGNMENT) > 0)
		{
			alignment = Utility::LoadInt(intStore, properties[PROPERTY_HORIZONTAL_ALIGNMENT]);
		}
		else
		{
			alignment = new ConstantValue((int)HorizontalAlignment::LEFT);
		}
		if (properties.count(PROPERTY_DROP_SHADOW) > 0)
		{
			dropShadowColor = Utility::LoadString(stringStore,properties[PROPERTY_DROP_SHADOW_COLOR]);
		}
		if (properties.count(PROPERTY_DROP_SHADOW_X) > 0)
		{
			dropShadowX = Utility::LoadInt(intStore, properties[PROPERTY_DROP_SHADOW_X]);
		}
		if (properties.count(PROPERTY_DROP_SHADOW_Y) > 0)
		{
			dropShadowY = Utility::LoadInt(intStore, properties[PROPERTY_DROP_SHADOW_Y]);
		}
	}

	StaticText::~StaticText()
	{
		Utility::SafeDelete(text);
		Utility::SafeDelete(fontName);
		Utility::SafeDelete(color);
		Utility::SafeDelete(dropShadowColor);
		Utility::SafeDelete(hasDropShadow);
		Utility::SafeDelete(x);
		Utility::SafeDelete(y);
		Utility::SafeDelete(dropShadowX);
		Utility::SafeDelete(dropShadowY);
		Utility::SafeDelete(alignment);
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
