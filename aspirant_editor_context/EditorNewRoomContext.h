#pragma once
#include <string>
namespace aspirant::editor::context
{
	class EditorNewRoomContext
	{
		EditorNewRoomContext(const EditorNewRoomContext&) = delete;
		EditorNewRoomContext(EditorNewRoomContext&&) = delete;
		EditorNewRoomContext& operator=(const EditorNewRoomContext&) = delete;
		EditorNewRoomContext& operator=(EditorNewRoomContext&&) = delete;
	private:
		std::string newRoomName;
		size_t newRoomColumns;
		size_t newRoomRows;
	public:
		EditorNewRoomContext() = default;
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
