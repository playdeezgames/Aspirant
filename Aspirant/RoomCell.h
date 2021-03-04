#pragma once
#include <set>
#include <stack>
#include "Utility.h"
#include "json.hpp"
namespace tggd::common
{
	template<typename TObjectData, typename TCellFlags>
	class RoomCell
	{
	private:
		const std::string PROPERTY_CELL_FLAGS = "cellFlags";
		const std::string PROPERTY_OBJECTS = "objects";
		std::stack<TObjectData*> objects;
		size_t column;
		size_t row;
		std::set<TCellFlags> cellFlags;
		void ClearObjects()
		{
			while (HasObjects())
			{
				auto object = RemoveObject();
				Utility::SafeDelete(object);
			}
		}
	protected:
		virtual nlohmann::json CellFlagToJSON(const TCellFlags&) = 0;
		virtual TCellFlags CellFlagFromJSON(const nlohmann::json&) = 0;
		virtual TObjectData* ObjectFromJSON(const nlohmann::json&) = 0;
		virtual bool CanCover(const TObjectData*, const TObjectData*) const = 0;
	public:
		RoomCell(size_t column, size_t row)
			: objects()
			, column(column)
			, row(row)
			, cellFlags()
		{}
		void FromJSON(const nlohmann::json& properties)
		{
			ClearObjects();
			cellFlags.clear();
			const auto& cellFlagsProperty = properties[PROPERTY_CELL_FLAGS];
			for (auto& cellFlag : cellFlagsProperty)
			{
				SetFlag(CellFlagFromJSON(cellFlag));
			}
			const auto& objectsProperty = properties[PROPERTY_OBJECTS];
			for (auto& object : objectsProperty)
			{
				AddObject(ObjectFromJSON(object));
			}
		}
		~RoomCell()
		{
			ClearObjects();
		}
		bool AddObject(TObjectData* newObject)
		{
			if (newObject && CanCover(newObject, GetObject()))
			{
				objects.push(newObject);
				return true;
			}
			return false;
		}
		const TObjectData* GetObject() const 
		{ 
			return 
				(objects.empty()) ? (nullptr) :
				(objects.top()); 
		}
		TObjectData* GetObject() 
		{ 
			return
				(objects.empty()) ? (nullptr) :
				(objects.top());
		}
		bool HasObjects() const { return !objects.empty(); }
		size_t GetColumn() const { return column; }
		size_t GetRow() const { return row; }
		void SetFlag(const TCellFlags& flag)
		{
			cellFlags.insert(flag);
		}
		void ClearFlag(const TCellFlags& flag)
		{
			cellFlags.erase(flag);
		}
		bool IsFlagSet(const TCellFlags& flag) const
		{
			return cellFlags.contains(flag);
		}
		TObjectData* RemoveObject()
		{
			if (!objects.empty())
			{
				auto result = objects.top();
				objects.pop();
				return result;
			}
			return nullptr;
		}
		void ClearAllFlags()
		{
			cellFlags.clear();
		}
		nlohmann::json ToJSON() const
		{
			nlohmann::json properties;
			//cell flags
			properties[PROPERTY_CELL_FLAGS] = nlohmann::json(nlohmann::detail::value_t::array);
			for (auto& cellFlag : cellFlags)
			{
				properties[PROPERTY_CELL_FLAGS].push_back(CellFlagToJSON(cellFlag));
			}
			//objects
			properties[PROPERTY_OBJECTS] = nlohmann::json(nlohmann::detail::value_t::array);
			for (auto object : objects)
			{
				properties[PROPERTY_OBJECTS].push_back(object->ToJSON());
			}
			return properties;
		}
	};

}