//
//  ArraySequence.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "Sequence.h"
#include "Node.h"

Node **content;
Node **removed;
const int SIZE = 7;
unsigned int init;
unsigned int end;

Sequence::Sequence()
{
    content = new Node*[SIZE];
    this->quantity = 0;
    init = 0;
    end = 0;
}

Sequence::~Sequence()
{
    // TO - DO
    delete [] content;
}

/**
 Returns the i-th element in this sequence.
 */
Node* Sequence::get(int i)
{
    return content[i-1];
}

/**
 Inserts the element in this sequence.
 After inserting, the element must be in the i-th position.
 */
void Sequence::insert(int i, Node* element)
{
    if(end == 0)
    {
        content[i] = element;
    } else
    {
        for(int j = end; j > i; j--)
        {
            content[j] = content[j-1];
        }
        content[i] = element;
    }
    end++;
    this->quantity++;
}

/**
 Inserts the element in the begin of this sequence.
 After inserting, the element will be the first in the sequence.
 */
void Sequence::insertBegin(Node* element)
{
    if(end == 0)
    {
        content[end] = element;
    } else
    {
        for(unsigned int i = end; i > init; i--)
        {
            content[i] = content[i-1];
        }
        content[init] = element;
    }
    this->quantity++;
    end++;
}

/**
 Inserts the element in the end position of this sequence.
 After inserting, the element will be the last in the sequence.
 */
void Sequence::insertEnd(Node* element)
{
    content[end] = element;
    end++;
    this->quantity++;
}

/**
 Removes the element in the i-th position of this sequence.
 Returns the removed element.
 */
Node* Sequence::remove(int i)
{
    // TO - DO
    return nullptr;
}

/**
 Removes the first element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeBegin()
{
    removed = new Node*[init];
    removed[init] = content[init];
    for(unsigned int i = init; i < end; i++)
    {
        content[i] = content[i + 1];
    }
    end--;
    this->quantity--;
    return removed[init];
}

/**
 Removes the last element in this sequence.
 Returns the removed element.
 */
Node* Sequence::removeEnd()
{
    removed = new Node*[init];
    removed[init] = content[end - 1];
    end--;
    this->quantity--;
    return removed[init];
}

bool Sequence::isEmpty()
{
    return this->getQuantity()==0;
}

int Sequence::getQuantity()
{
    return this->quantity;
}
