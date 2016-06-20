
#ifndef USER_INTERFACE_H_
#define USER_INTERFACE_H_

class UserInterface {
public:
	UserInterface();
	virtual void ejecutar() = 0;
	virtual ~UserInterface();
};

#endif /* USER_INTERFACE_H_ */
