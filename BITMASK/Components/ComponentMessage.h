#pragma once

enum event_type
{
	PLAYER_MOVEMENT,
	SPRITE_CHANGE
};

class ComponentMessage
{
	public:
		void* data;
		event_type eventId;

		ComponentMessage(event_type id)
		{
			this->eventId = id;
			
		};

		template <typename DataType>
		void setData(DataType dataIn)
		{
			this->data = (void*)&dataIn;
		}

		template <typename DataType>
		DataType getData()
		{
			return *static_cast<DataType*>(data);
		}

		~ComponentMessage() {};
};