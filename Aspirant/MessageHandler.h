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
				_parent->_children.remove(this);
			}
			_parent = parent;
			if (_parent)
			{
				_parent->_children.push_back(this);
			}
		}
	protected:
		virtual bool IsEnabled()
		{
			return true;
		}
		virtual bool OnMessage(const MGeneric*) = 0;
	public:
		MessageHandler(MessageHandler* parent)
			: _parent(nullptr)
			, _children()
		{
			SetParent(parent);
		}
		virtual ~MessageHandler()
		{
			for (auto& child : _children)
			{
				delete child;
			}
		}
		bool Handle(const MGeneric& message)
		{
			if (!IsEnabled())
			{
				return false;
			}
			if (OnMessage(&message))
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
			if (!IsEnabled())
			{
				return;
			}
			OnMessage(&message);
			for (auto& child : _children)
			{
				child->Broadcast(message);
			}
		}
		bool HandleBroadcast(const MGeneric& message)
		{
			if (!IsEnabled())
			{
				return false;
			}
			for (auto iter = _children.rbegin(); iter != _children.rend(); ++iter)
			{
				auto child = *iter;
				if (child->HandleBroadcast(message))
				{
					return true;
				}
			}
			return OnMessage(&message);
		}
	};
}
