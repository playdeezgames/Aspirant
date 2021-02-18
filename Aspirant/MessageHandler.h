#pragma once
#include <list>
#include "MGeneric.h"
namespace tggd::common
{
	class MessageHandler
	{
	private:
		MessageHandler* _parent;
		std::list<MessageHandler*> _children;
		void SetParent(MessageHandler* parent)
		{
			if (_parent)
			{
				_children.remove(this);
			}
			_parent = parent;
			if (_parent)
			{
				_children.push_back(this);
			}
		}
	protected:
		virtual bool OnMessage(const MGeneric&) = 0;
	public:
		MessageHandler(MessageHandler* parent = nullptr)
			: _parent(nullptr)
			, _children()
		{
			SetParent(parent);
		}
		bool Handle(const MGeneric& message)
		{
			if (OnMessage(message))
			{
				return true;
			}
			else
			{
				if (_parent)
				{
					return _parent->Handle(message);
				}
				else
				{
					return false;
				}
			}
		}
		void Broadcast(const MGeneric& message)
		{
			OnMessage(message);
			for (auto& child : _children)
			{
				child->Broadcast(message);
			}
		}
		bool HandleBroadcast(const MGeneric& message)
		{
			for (auto iter = _children.rbegin(); iter != _children.rend(); ++iter)
			{
				auto child = *iter;
				if (child->HandleBroadcast(message))
				{
					return true;
				}
			}
			return OnMessage(message);
		}
	};
}
