#include "pch.h"
#include <iostream>

template<typename T>
void minInQueue(Queue<T> q, T& min, Queue<T>& newq)
{
	T x;
	q.pop(min);
	while (!q.empty())
	{
		q.pop(x);
		if (x < min)
		{
			newq.push(min);
			min = x;
		}
		else newq.push(x);
	}
}
template<typename T>
void sortQueue(Queue<T> q, Queue<T>& newq)
{
	while (!q.empty())
	{
		T min;
		Queue<T> q1;
		minInQueue(q, min, q1);
		newq.push(min);
		q = q1;
	}
}


