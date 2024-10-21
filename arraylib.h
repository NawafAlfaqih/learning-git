#pragma once

#include <iostream>
#include <string>
#include "Iolib.h"
#include "mathlib.h"

using namespace std;

namespace arraylib {

	void readArray(int arr[], int& arrLength) {

		for (int i = 0; i < arrLength; i++) {

			cout << "Element [" << i + 1 << "]: ";
			cin >> arr[i];
		}
	}

	void printArray(int arr[], int arrLength) {

		cout << "Original Array: ";
		for (int i = 0; i < arrLength; i++)
			cout << arr[i] << " ";
		cout << endl;
	}


	void randomizeArray(int arr[], int& arrLength) {
		for (int i = 0; i < arrLength; i++)
			arr[i] = mathlib::randomNumber(1, 100);
	}


	int MaxNumberInArray(int arr[], int arrLength) {

		int maxNum = 0;
		for (int i = 0; i < arrLength; i++)
			if (arr[i] > maxNum)
				maxNum = arr[i];
		return maxNum;
	}

	int MinNumberInArray(int arr[], int arrLength) {

		int minNum = 100;
		for (int i = 0; i < arrLength; i++)
			if (arr[i] < minNum)
				minNum = arr[i];
		return minNum;
	}

	int sumNumbersInArray(int arr[], int arrLength) {

		int sumOfArr = 0;
		for (int i = 0; i < arrLength; i++)
			sumOfArr += arr[i];
		return sumOfArr;
	}

	float averageNumbersInArray(int arr[], int arrLength) {

		return (float)sumNumbersInArray(arr, arrLength) / arrLength;
	}

	void addArrayElement(int number, int arr[], int& arrLength) {

		arr[arrLength] = number;
		arrLength++;
	}
	
	void copyArray(int arr1[], int arr2[], int arrLength) {
		for (int i = 0; i < arrLength; i++)
			arr2[i] = arr1[i];
	}

	void sumArrays(int arr1[], int arr2[], int newArr[], int arrLength) {
		for (int i = 0; i < arrLength; i++) {
			newArr[i] = arr1[i] + arr2[i];
		}
	}

	void shuffleArray(int arr[], int& arrLength) {

		for (int i = 0; i < arrLength; i++) {

			util::swap(arr[i], arr[mathlib::randomNumber(0, arrLength - 1)]);
		}
	}

	void reverseArray(int arr1[], int arr2[], int& arrLength) {

		int j = arrLength - 1;
		for (int i = 0; i < arrLength; i++) {
			arr2[j] = arr1[i];
			j--;
		}
	}

	int indexInArray(int arr[], int arrLength, int num) {

		for (int i = 0; i < arrLength; i++)
			if (num == arr[i])
				return i;

		return -1; //not found
	}

	bool isInArray(int arr[], int arrLength, int num) {

		return indexInArray(arr, arrLength, num) != -1;
	}

	void semiDynamicArray(int arr[], int& arrLength) {

		int reEnter = 1;
		arrLength = 0;
		do {
			arr[arrLength] = read::readPositiveNumber("\nPlease Enter a number: ");
			arrLength++;

			reEnter = read::readPositiveNumber("do you want to add more numbers?  [0 -> NO | 1 -> YES] : ");

		} while (reEnter == 1);
	}

	void copyArrayDistinctNumbers(int arr1[], int arr2[], int arrLength1, int& arrLength2) {

		for (int i = 0; i < arrLength1; i++)
			if (isInArray(arr2, arrLength2, arr1[i]))
				addArrayElement(arr1[i], arr2, arrLength2);
	}

	bool isPalindromeArray(int arr[], int arrLength) {

		for (int i = 0; i < arrLength; i++) {
			if (arr[i] != arr[arrLength - i - 1])
				return false;
		}
		return true;
	}

	int countElement(int arr[], int element, int arrLength) {

		int counter = 0;
		for (int i = 0; i < arrLength; i++)
			if (arr[i] == element)
				counter++;
		return counter;
	}


}