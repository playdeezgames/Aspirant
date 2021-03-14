#pragma once
#include <string>
namespace aspirant::editor::context
{
	class EditorNewRoomContext
	{
	private:
		std::string newRoomName;
		size_t newRoomColumns;
		size_t newRoomRows;
	public:
		void ResetNewRoom();
		const std::string& GetNewRoomName() const;
		void AppendNewRoomName(const std::string&);
		void ClearNewRoomName();
		size_t GetNewRoomColumns() const;
		void IncrementNewRoomColumns();
		void DecrementNewRoomColumns();
		size_t GetNewRoomRows() const;
		void IncrementNewRoomRows();
		void DecrementNewRoomRows();
	};
}
