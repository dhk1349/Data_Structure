#ifndef _UNSORTEDLIST_H
#define _UNSORTEDLIST_H

#include <iostream>
#include <fstream>	
#include <string>
using namespace std;

#include "ItemType.h"

#define MAXSIZE 5

/**
*	array based simple unsorted list.
*/
class ArrayList
{
public:
	/**
	*	default constructor.
	*/
	ArrayList()
	{
		m_Length = 0;
		ResetList();
	}

	/**
	*	destructor.
	*/
	~ArrayList()	{}

	/**
	*	@brief	Make list empty.
	*	@pre	none.
	*	@post	clear list.
	*/
	void MakeEmpty();

	/**
	*	@brief	Get a number of records in current list.
	*	@pre	none.
	*	@post	none.
	*	@return	number of records in current list.
	*/
	int GetLength();

	/**
	*	@brief	Check capacity of list is full.
	*	@pre	none.
	*	@post	none.
	*	@return	return true if list capacity reached to the upper bound, otherwise return false.
	*/
	bool IsFull();

	/**
	*	@brief	add a new data into list.
	*	@pre	list should be initialized.
	*	@post	added the new record into the list.
	*	@param	data	new data.
	*	@return	return 1 if this function works well, otherwise 0.
	*/
	int Add(ItemType data);

	/**
	*	@brief	Initialize list iterator.
	*	@pre	list should be initialized.
	*	@post	iterator is reset.
	*/
	void ResetList();

	/**
	*	@brief	move list iterator to the next item in list and get that item.
	*	@pre	list and list iterator should not be initialized. 
	*	@post	iterator is moved to next item.
	*	@param	data	get current iterator's item. it does not need to be initialized.
	*	@return	index of current iterator's item if is not end of list, oterwise return -1.
	*/
	int GetNextItem(ItemType& data);
	
	/**
	* @brief check if array is empty
	* @pre none
	* @post none
    * @param no parameter is neede
	* @return return 0 if list is empty. return 1 if list is not empty.
	*/
	int IsEmpty();
	/**
	* @brief Get ID from keyboard and tells index of item with thta ID
	* @pre none
	* @post none
	* @param input ID from keyboard is stored at parameter 'data'
	* @return
	*/
	int Get(ItemType& data);
	/**
	* @brief Use Get fnc to get index and delete the item with that index. Items at 'index+n' will be pulled forward.
	* @pre N Items in the array
	* @post N-1 Items in the array
	* @param parameter carrys info about primary key.
	* @return return 0 if something was deleted and return 1 there is no such item with given primary key.
	*/
	int Delete(ItemType data);
	/**
	* @brief find curresponding index from data(parameter)'s primary key and replace Item with data(parameter)
	* @pre none
	* @post item is replaced with data
	* @param carries information that user want to replace. but there must be corresponding primary key in the array.
	* @return return -1 if there is nothing to replace in the list. return 0 if there was replacement.
	*/
	int Replace(ItemType data);
private:
	ItemType m_Array[MAXSIZE];  ///< list array.
	int m_Length;				///< number of elements in list.
	int m_CurPointer;			///< iterator pointer.
};

#endif	// _UNSORTEDLIST_H