#ifndef NOEXISTECHAT_H
#define	NOEXISTECHAT_H

#include<exception>
#include<iostream>

using namespace std;

class NoExisteChat : public exception{
	public:
		NoExisteChat();
		~NoExisteChat();
		virtual const char* what()const throw();

};

#endif	/* NOEXISTECHAT_H */
