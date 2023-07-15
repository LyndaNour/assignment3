#ifndef _QUEUE_H_
#define _QUEUE_H_

#include<list>

namespace KW {

	template<typename Item_Type>
	class queue {
	public:
		queue();
		void push(const Item_Type& item );
		const Item_Type& front();
		void pop();
		bool empty() const;
		size_t size() const;

	private:
		//insert implementation specific data fields
		std::list<Item_Type> container;
	};// end class queue

	//insert member function implementation
#include"List_Queue.tc"
	//end naamespace KW 

}

#endif
