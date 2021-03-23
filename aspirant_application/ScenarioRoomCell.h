#pragma once
#include "ScenarioObjectInstance.h"
#include "Game.Descriptors.h"
#include "FinishUtility.h"
namespace aspirant::game
{
	class ScenarioRoomCell
	{
	private:
		const std::string PROPERTY_OBJECTS = "objects";
		std::vector<ScenarioObjectInstance*> objects;
		size_t column;
		size_t row;
		void ClearObjects()
		{
			while (HasObjects())
			{
				auto object = RemoveObject();
				tggd::common::FinishUtility::SafeDelete(object);
			}
		}
	protected:
		nlohmann::json ObjectToJSON(const ScenarioObjectInstance*) const;
		ScenarioObjectInstance* ObjectFromJSON(const nlohmann::json&);
		bool CanCover(const ScenarioObjectInstance*, const ScenarioObjectInstance*) const;
	public:
		ScenarioRoomCell(size_t column, size_t row)
			: objects()
			, column(column)
			, row(row)
		{}
		void FromJSON(const nlohmann::json& properties)
		{
			ClearObjects();
			const auto& objectsProperty = properties[PROPERTY_OBJECTS];
			for (auto& object : objectsProperty)
			{
				AddObject(ObjectFromJSON(object));
			}
		}
		~ScenarioRoomCell()
		{
			ClearObjects();
		}
		bool AddObject(ScenarioObjectInstance* newObject)
		{
			if (newObject && CanCover(newObject, GetObject()))
			{
				objects.push_back(newObject);
				return true;
			}
			return false;
		}
		const std::vector<ScenarioObjectInstance*>& GetObjects() const
		{
			return objects;
		}
		const ScenarioObjectInstance* GetObject() const
		{
			return
				(objects.empty()) ? (nullptr) :
				(objects.back());
		}
		ScenarioObjectInstance* GetObject()
		{
			return
				(objects.empty()) ? (nullptr) :
				(objects.back());
		}
		bool HasObjects() const { return !objects.empty(); }
		size_t GetColumn() const { return column; }
		size_t GetRow() const { return row; }
		ScenarioObjectInstance* RemoveObject()
		{
			if (!objects.empty())
			{
				auto result = objects.back();
				objects.pop_back();
				return result;
			}
			return nullptr;
		}
		nlohmann::json ToJSON() const
		{
			nlohmann::json properties;
			//objects
			properties[PROPERTY_OBJECTS] = nlohmann::json(nlohmann::detail::value_t::array);
			for (auto object : objects)
			{
				properties[PROPERTY_OBJECTS].push_back(ObjectToJSON(object));
			}
			return properties;
		}
	};
}
