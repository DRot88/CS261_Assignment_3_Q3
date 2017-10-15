#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this
	list->sentinel = malloc(sizeof(struct Link));
	assert (list->sentinel != 0);

	list->sentinel->next = list->sentinel;
	list->sentinel->prev = list->sentinel;
	list->size = 0;
}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	// FIXME: you must write this
	struct Link *newLink = malloc(sizeof(struct Link));
	assert (newLink != 0);

	newLink->value = value;

	newLink->next = 0;
	newLink->prev = 0;

	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this
	//creates the new link
	struct Link *newLink = createLink(value);
	//add link after link in params
	newLink->prev = link;
	newLink->next = link->next;
	link->next = link;

	//assign adjacent links to point to newLink
	newLink->next->prev = newLink;
	newLink->prev->next = newLink;

	list->size++;

}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	// FIXME: you must write this

	/*rearrange adjacent links */
	link->next->prev = link->prev;
	link->prev->next = link->next;

	/* set link to null and delete */
	link->prev = 0;
	link->next = 0;
	free(link);
	link = 0;

	/* decrease size of list */
	list->size--;


}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	while(!circularListIsEmpty(list)) {
		struct Link *linkToDelete = malloc(sizeof(struct Link));
		linkToDelete = list->sentinel->next;
		removeLink(list, linkToDelete);
	}

	free(list->sentinel);
	free(list);

}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	// struct Link *linkToAdd = createLink(value);
	addLinkAfter(list, list->sentinel, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel->prev, value);	
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	if (!circularListIsEmpty(list)) {
		return (list->sentinel->next->value);
	}
	return 0;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	if (!circularListIsEmpty(list)) {
		return (list->sentinel->prev->value);
	}
	return 0;
}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	if (!circularListIsEmpty(list)) {
		removeLink(list, list->sentinel->next);
	}
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	if (!circularListIsEmpty(list)) {
		removeLink(list, list->sentinel->prev);
	}
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	// FIXME: you must write this
	if ((list->sentinel->next == list->sentinel) && (list->sentinel->prev == list->sentinel)) {
		return 1;
	}
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *itr = malloc(sizeof(struct Link));
	itr = list->sentinel->next;
	while (itr != list->sentinel) {
		printf("%.2f\n", itr->value);
		itr = itr->next;
	}
}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	// FIXME: you must write this
	struct Link *itr = malloc(sizeof(struct Link));
	itr = list->sentinel->prev;
	while (itr != list->sentinel) {
		printf("%.2f\n", itr->value);
		itr = itr->prev;
	}
}
