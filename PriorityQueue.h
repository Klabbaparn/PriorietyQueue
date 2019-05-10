#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <stdexcept>
#include <utility>

template<typename T>
class PriorityQueue {

public:
	PriorityQueue(T a[], int size) : m_arr(a), m_size(size) {}
	PriorityQueue() : m_arr(nullptr), m_size(1) {}
	~PriorityQueue() { delete[] m_arr; }

private:
	T* m_arr = nullptr;
	int m_size = 1;
	int m_MaxSize = 0;
	T m_front;
	int initListSize = 1000;


	void heapify(T a[], int i, int arrSize)
	{
		int j; 
		T temp;								    // Föräldernoden man jämnför med
		temp = a[i];
		j = 2 * i;							    
		while (j <= arrSize)		 	    
		{
			if (j < arrSize && a[j + 1] < a[j]) 
				j = j + 1;						
			if (temp < a[j])					
				break;							
			else if (a[j] < temp)
			{
				a[j / 2] = a[j];				
				j = 2 * j;						
			}
		}
		a[j / 2] = temp;						
	}
	void createMinHeap(T a[], int arrSize)
	{
		int i;
		for (i = arrSize / 2; 1 <= i; i--)      //Loopar igenom alla noder, börjar med sista föräldern.
		{
			heapify(a, i, arrSize);
		}
	}

	void swap(T *a, T *b) {
		T temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}


public:

	void enqueue(T Element)
	{
		if (!m_arr)
		{
			m_arr = new T[initListSize];
			m_MaxSize = initListSize;
		}

		if (m_size < m_MaxSize)
		{
			m_arr[m_size++] = Element;
		}
		else
		{
			T* temp = m_arr;
			m_MaxSize += initListSize;
			m_arr = new T[m_MaxSize];
			for (int i = 0; i < m_size; i++)
				m_arr[i] = temp[i];
			m_arr[m_size++] = Element;
			delete[] temp;
			temp = nullptr;
		}
	}

	void dequeue()
	{
		if (!isEmpty())
		{
			createMinHeap(m_arr, m_size - 1);
			swap(&m_arr[1], &m_arr[m_size - 1]);
			m_size--;
		}
		else
			throw "Queue is empty";
	}

	
	T peek()
	{
		if (!isEmpty())
		{
			createMinHeap(m_arr, m_size-1);
			return m_arr[1];
		}
		else
			throw ("Queue is empty");
	}

	size_t size()
	{
		if (!isEmpty())
			return m_size-1;
		else
			return m_size; 
	}

	bool isEmpty() const
	{
		return m_size == 1;
	}

};

#endif // PRIORITYQUEUE_H
