#pragma once
#include "json.hpp"
namespace tggd::common
{
	template<typename TObjectData, typename TCellFlags>
	class RoomCell;
	template<typename TObjectData, typename TCellFlags>
	class RoomCellObject
	{
	private:
		friend class RoomCell<TObjectData, TCellFlags>;
		RoomCell<TObjectData, TCellFlags>* roomCell;
	public:
		RoomCellObject(RoomCell<TObjectData, TCellFlags>* roomCell = nullptr) :roomCell(roomCell) {}
		virtual ~RoomCellObject() {}
		const RoomCell<TObjectData, TCellFlags>* GetRoomCell() const { return roomCell; }
		RoomCell<TObjectData, TCellFlags>* GetRoomCell() { return roomCell; }
		virtual const TObjectData& GetData() const = 0;
		virtual bool CanCover(const RoomCellObject<TObjectData, TCellFlags>*) = 0;
		virtual nlohmann::json ToJSON() const = 0;
	};
}