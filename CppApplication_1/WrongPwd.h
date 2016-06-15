#ifndef WrongPwd_h
#define WrongPwd_h

#include<exception>
#include<iostream>

using namespace std;

class WrongPwd : public exception{
	public:
		virtual const char* what()const throw();

};


#endif