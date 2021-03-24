#pragma once
#include <string>
namespace aspirant::context::editor::NewRoom
{
	void Reset();
	const std::string& GetName();
	void AppendName(const std::string&);
	void ClearName();
	size_t GetColumns();
	void IncrementColumns();
	void DecrementColumns();
	size_t GetRows();
	void IncrementRows();
	void DecrementRows();
}
