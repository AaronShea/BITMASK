#pragma once

class ComponentMessage
{
	public:
		void* data;
		int eventId = 0;

		ComponentMessage(int id)
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