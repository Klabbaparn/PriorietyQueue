//#include "TestPriorityQueue.hpp"
#include <string>
#include <iostream>
#include "PriorityQueue.h"



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	PriorityQueue<int>collection;
	
	collection.enqueue(2);
	collection.enqueue(16);
	collection.enqueue(74);
	collection.enqueue(58);
	collection.enqueue(36);
	collection.enqueue(4);
	collection.enqueue(28);
	collection.enqueue(15);
	collection.enqueue(35);
	collection.enqueue(82);
	collection.enqueue(6);



	//std::cout << collection[1] << std::endl;
	//std::cout << collection[2] << std::endl;
	//std::cout << collection[3] << std::endl;
	//std::cout << collection[4] << std::endl;
	//std::cout << collection[5] << std::endl;
	//std::cout << collection[6] << std::endl;
	//std::cout << collection[7] << std::endl;
	//std::cout << collection[8] << std::endl;
	//std::cout << collection[9] << std::endl;
	//std::cout << collection[10] << std::endl;
	//std::cout << collection[11] << std::endl;

	collection.dequeue();
	/*collection.peek();
	collection.dequeue();
	collection.peek();
	collection.dequeue();
	collection.peek();
	collection.dequeue();
	collection.peek();
	collection.dequeue();
	collection.peek();
	collection.dequeue();
	collection.peek();
	collection.dequeue();
	collection.peek();
	collection.dequeue();
	collection.peek();
	collection.dequeue();
	collection.peek();
	collection.dequeue();
	collection.peek();*/

	return 0;
}

