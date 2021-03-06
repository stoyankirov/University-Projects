#include "pch.h"
#include <iostream>

template<typename T>
Queue<T> merge(Queue<T> q, Queue<T> p, const T& dummy)
{
	q.push(dummy);
	p.push(dummy);
	Queue<T> newq;
	T x, y;
	p.pop(x);
	q.pop(y);
	while (!p.empty() && !q.empty)
	{
		if (x < y)
		{
			newq.push(x);
			p.pop(x);
		}
		else
		{
			newq.push(y);
			q.pop(y);
		}
	}
	if (!q.empty())
	{
		do {
			newq.push(y);
			q.pop(y);
		} while (y != dummy);
	}
	else
	{
		do {
			newq.push(x);
			p.pop(x);
		} while (x != dummy);
	}
	return newq;
}
