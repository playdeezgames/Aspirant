#pragma once
#include "json.hpp"
#include <string>
#include "Common.XY.h"
namespace game
{
	class Avatar
	{
	private:
		Avatar(const Avatar&) = delete;
		Avatar(Avatar&&) = delete;
		Avatar& operator=(const Avatar&) = delete;
		Avatar& operator=(Avatar&&) = delete;

		std::string roomId;
		common::XY<size_t> position;
	public:
		Avatar() = default;
		void SetRoomId(const std::string&);
		const std::string& GetRoomId() const;
		void SetPosition(const common::XY<size_t>);
		const common::XY<size_t> GetPosition() const;
		void FromJSON(const nlohmann::json&);
		nlohmann::json ToJSON() const;
	};
}
