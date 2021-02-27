#pragma once
#include "RoomCellObject.h"
#include <set>
#include <stack>
#include "Utility.h"
namespace tggd::common
{
	template<typename TObjectData, typename TCellFlags>
	class RoomCell
	{
	private:
		const std::string PROPERTY_CELL_FLAGS = "cellFlags";
		const std::string PROPERTY_OBJECTS = "objects";
		std::stack<RoomCellObject<TObjectData, TCellFlags>*> objects;
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
		virtual nlohmann::json CellFlagToJSON(const TCellFlag&) = 0;
		virtual TCellFlag CellFlagFromJSON(const nlohmann::json&) = 0;
		virtual RoomCellObject<TObjectData, TCellFlags>* ObjectFromJSON(const nlohmann::json&) = 0;
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
		bool AddObject(RoomCellObject<TObjectData, TCellFlags>* newObject)
		{
			if (newObject && newObject->CanCover(GetObject()))
			{
				newObject->roomCell = this;
				objects.push(newObject);
				return true;
			}
			return false;
		}
		const RoomCellObject<TObjectData, TCellFlags>* GetObject() const 
		{ 
			return 
				(objects.empty()) ? (nullptr) :
				(objects.top()); 
		}
		RoomCellObject<TObjectData, TCellFlags>* GetObject() 
		{ 
			return
				(objects.empty()) ? (nullptr) :
				(objects.top());
		}
		bool HasObjects() const { return !objects.empty() }
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
		RoomCellObject<TObjectData, TCellFlags>* RemoveObject()
		{
			if (!objects.empty())
			{
				return objects.pop();
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