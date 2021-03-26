#pragma once
#include "json.hpp"
#include <string>
#include "Common.XY.h"
namespace game
{
	class Avatar
	{
	private:
		Avatar() = delete;
		Avatar(const Avatar&) = delete;
		Avatar(Avatar&&) = delete;
		Avatar& operator=(const Avatar&) = delete;
		Avatar& operator=(Avatar&&) = delete;
		nlohmann::json& model;
	public:
		Avatar(nlohmann::json& model) :model(model) {}
		void SetRoomId(const std::string&);
		std::string GetRoomId() const;
		void SetPosition(const common::XY<size_t>);
		common::XY<size_t> GetPosition() const;
	};
}
